__________________________________________________________________________________________________
sample 132 ms submission
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n = hits.size();
        swap(grid, G_);
        n1_ = G_.size(), n2_ = G_[0].size();
        vector<int> res(n, 0);
        for (const auto &h : hits) 
            G_[h[0]][h[1]]--;
        for (int i = 0; i < n2_; i++) {
            if (G_[0][i] == 1) {
                int cnt = 0;
                DFS(0, i, cnt);
            }
        }
        for (int k = n - 1; k >= 0; k--) {
            int i = hits[k][0];
            int j = hits[k][1];
            if (++G_[i][j] == 1) {
                if (isValid(i, j)) {
                    int cnt = 0;
                    DFS(i, j, cnt);
                    res[k] = cnt - 1;
                }
            }            
        }
        return res;
    }
private:
    vector<vector<int>> G_;
    int n1_, n2_;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    void DFS(int i, int j, int &cnt) {
        if (i < 0 || j < 0 || i >= n1_ || j >= n2_ || G_[i][j] != 1)
            return;
        G_[i][j] = 2;
        cnt++;
        for (int d = 0; d < 4; d++) {
            int x = i + dir[d][0];
            int y = j + dir[d][1];
            DFS(x, y, cnt);
        }
    }
    
    bool isValid(int i, int j) {
        if (i == 0)
            return true;
        for (int d = 0; d < 4; d++) {
            int x = i + dir[d][0];
            int y = j + dir[d][1];
            if (x < 0 || y < 0 || x >= n1_ || y >= n2_)
                continue;
            if (G_[x][y] == 2)
                return true;
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 26516 kb submission
class Solution {
public:
    int cnt;
    int r, c;
    
    bool check(int x, int y) {
        if (x < 0 || y < 0 || x >= r || y >= c) return false;
        return true;
    }
    
    bool sides(vector<vector<int>>& g, int x, int y) {
        if (check(x + 1, y) && g[x + 1][y] == 2) return true;
        if (check(x - 1, y) && g[x - 1][y] == 2) return true;
        if (check(x, y + 1) && g[x][y + 1] == 2) return true;
        if (check(x, y - 1) && g[x][y - 1] == 2) return true;
        return false;
    }
    
    void f(vector<vector<int>>& g, int x, int y) {
        if (!check(x, y) || g[x][y] != 1) return;
        
        cnt++;
        g[x][y] = 2;
        f(g, x + 1, y);
        f(g, x - 1, y);
        f(g, x, y + 1);
        f(g, x, y - 1);
    }
    
    vector<int> hitBricks(vector<vector<int>>& g, vector<vector<int>>& h) {
        g.insert(g.begin(), vector<int>(g[0].size(), 2));
        for (int i = 0; i < h.size(); i++)
            if (g[h[i][0] + 1][h[i][1]]) {
                g[h[i][0] + 1][h[i][1]] = -1;
            }
        
        r = g.size();
        c = g[0].size();
        cnt = 0;
        for (int i = 0; i < g[0].size(); i++)
            if (g[1][i]) f(g, 1, i);
        
        vector<int> ans(h.size(), 0);
        for (int i = h.size() - 1; i >= 0; i--) {
            int x = h[i][0] + 1;
            int y = h[i][1];
            
            int last = cnt;
            if (g[x][y] == -1) {
                g[x][y] = 1;
                if (sides(g, x, y)) {
                    f(g, x, y);
                    ans[i] = cnt - last - 1;
                }
            }
        }
        
        return ans;
    }
};
__________________________________________________________________________________________________
