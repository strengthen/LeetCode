__________________________________________________________________________________________________
sample 88 ms submission
class Solution {
public:
    struct Node{
        int r, c, d;
        Node(int i, int j, int v) {
            r = i;  // row
            c = j;  // col
            d = v;  // height or Detour
        }
        
        bool operator<(const Node& n) const{
            return (d < n.d);
        }
    };
    
    int cutOffTree(vector<vector<int>>& forest) {
        vector<Node> v;
        
        // STEP One: put the trees in order according to their height
        for (int i = 0; i < forest.size(); i++) {
            for (int j = 0; j < forest[i].size(); j++) {
                if (forest[i][j] > 1) {
                    Node n(i, j, forest[i][j]); 
                    v.push_back(n);
                }                
            }
        }
        
        sort(v.begin(), v.end());
        
        // STEP Two: Start from (0, 0) and cut trees one by one
        int ans = 0;
        Node cur(0, 0, 1);
        for (int i = 0; i < v.size(); i++) {
            int step = hadlock(forest, cur.r, cur.c, v[i].r, v[i].c);
            if (step < 0) {
                return -1;
            }
            
            ans += step;
            cur = v[i];
        }
        return ans;
    }
private:
    int hadlock(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {    
        deque<Node> dq;
        Node cur(sr, sc, 0);
        dq.push_back(cur);
        
        int R = forest.size(), C = forest[0].size();
        vector<bool> mask(R*C, false);
        
        vector<vector<int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!dq.empty()) {
            Node n = dq.front();
            dq.pop_front();
            if (mask[n.r*C+n.c]) {
                continue;
            }
            mask[n.r*C+n.c] = true;
            if (n.r == tr && n.c == tc) {
                return abs(sr - tr) + abs(sc - tc) + 2*n.d;
            }
            
            for (int i = 0; i < direct.size(); i++) {
                int nr = n.r + direct[i][0];
                int nc = n.c + direct[i][1];
                
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && forest[nr][nc] > 0) {
                    bool closer = abs(n.r - tr) > abs(nr - tr) || abs(n.c - tc) > abs(nc - tc);
                    // If the next position is closer to the target, we put it in the front of the deque
                    if (closer) {
                        Node t(nr, nc, n.d);
                        dq.push_front(t);
                    }
                    // Otherwise, we put it in the rear of the deque
                    else {
                        Node t(nr, nc, n.d+1);
                        dq.push_back(t);
                    }
                }
            }
        }
        
        return -1;
    }
};
__________________________________________________________________________________________________
sample 28196 kb submission
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty() || forest[0].empty()) return 0;
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> trees;
        // get all the tree positions and sort based on height
        // trees[i][0] is height. The default comparison of vector compare first element before other elements.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
            }
        }
        sort(trees.begin(), trees.end());
        int ans = 0;
        // accumulate all the paths
        for (int i = 0, cur_row = 0, cur_col = 0; i < trees.size(); i++) {
            int step = next_step(forest, cur_row, cur_col, trees[i][1], trees[i][2]);
            // if next tree cannot be reached, step = -1;
            if (step == -1) return -1;
            ans += step;
            cur_row = trees[i][1];
            cur_col = trees[i][2];
        }
        return ans;
    }
private:
    // BFS to find shortest path to next tree; if cannot reach next tree, return -1
    int next_step1(vector<vector<int>>& forest, int sr, int sc, int er, int ec) {
        if (sr == er && sc == ec) return 0;
        int m = forest.size(), n = forest[0].size();
        queue<pair<int, int>> myq;
        myq.push({sr, sc}); 
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[sr][sc] = 1;
        int step = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!myq.empty()) {
            step++;
            int sz = myq.size();
            for (int i = 0; i < sz; i++) {
                int row = myq.front().first, col = myq.front().second;
                myq.pop();
                for (int i = 0; i < 4; i++) {
                    int r = row + dir[i], c = col + dir[i+1];
                    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == 1 || forest[r][c] == 0) continue;
                    if (r == er && c == ec) return step;
                    visited[r][c] = 1;
                    myq.push({r, c});
                }
            }
        }
        return -1;
    }
    
    typedef tuple<int, int, int> iTuple;
    // A*
    int next_step(vector<vector<int>>& forest, int sr, int sc, int er, int ec) {
        if (sr == er && sc == ec) return 0;
        int M = forest.size(), N = forest[0].size();
        int g[50][50]; // distance from start to forest[i][j]
        for (int i = 0; i < 50; i++) {
            for (int j=0; j<50; j++) {
                g[i][j] = INT_MAX;
            }
        }
        g[sr][sc] = 0;
        
        int h[50][50];
        for (int i = 0; i < 50; i++) {
            for (int j=0; j<50; j++) {
                h[i][j] = abs(er-i) + abs(ec-j);
            }
        }
        
        priority_queue<iTuple, vector<iTuple>, greater<iTuple>> heap;
        heap.push(make_tuple(0, sr, sc)); // (f, x, y)
        
        int dir[5] = {-1, 0, 1, 0, -1};
        while(!heap.empty()) {
            iTuple cur = heap.top();
            heap.pop();
            
            int f = get<0>(cur), x = get<1>(cur), y = get<2>(cur);
            if (f > g[x][y] + h[x][y]) continue;
            if (x==er && y==ec) return g[x][y];
            
            for (int i=0; i<4; i++) {
                int r = x + dir[i], c = y + dir[i+1];
                if (r < 0 || r >= M || c < 0 || c >= N || forest[r][c] == 0) continue;
                if (g[x][y] + 1 < g[r][c]) {
                    g[r][c] = g[x][y]+1;
                    
                    heap.push( make_tuple(g[r][c] + h[r][c], r, c) );
                }
            }
        }
        return -1;
    }
};
__________________________________________________________________________________________________
