__________________________________________________________________________________________________
104ms
class Solution {
public:
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    struct Node {
        int x,y,dist;
        bool operator<(const Node &X) const { 
            return dist > X.dist; 
        } 
    };
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ANS(R, vector<int>(C,INT_MAX));
        vector<vector<int>> ANS2;
        
        
        queue<Node> Q;
        Q.push({r0,c0,0});
        ANS[r0][c0] = 0;
        
        while(!Q.empty()) {
            Node F = Q.front();
            Q.pop();
            
            int x = F.x;
            int y = F.y;
            int dist = F.dist;
            ANS2.push_back({F.x,F.y});
            
            for(int i=0;i<4;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx>=0 && nx<R && ny>=0 && ny<C) {
                    if(ANS[nx][ny] > dist + 1) {
                        ANS[nx][ny] = dist + 1;
                        Q.push({nx,ny,dist+1});
                    }
                }
            }
            
        }
        
        return ANS2;
    }
};
__________________________________________________________________________________________________
112ms
class Solution {
public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> ans;
    for (int i = 0; i < R; ++ i) {
      for (int j = 0; j < C; ++ j) {
        ans.push_back({i, j});
      }
    }
    sort(ans.begin(), ans.end(), [r0, c0](const vector<int>& a, const vector<int>& b) {
      int da = abs(a[0] - r0) + abs(a[1] - c0);
      int db = abs(b[0] - r0) + abs(b[1] - c0);
      return da < db;
    });
    return ans;
  }
};
__________________________________________________________________________________________________
116ms
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        for (int r=0; r<R; r++)
            for (int c=0; c<C; c++)
                res.push_back({r, c});
        sort(res.begin(), res.end(), [&](const vector<int>& a, const vector<int>& b) {
            return abs(a[0]-r0) + abs(a[1]-c0) < abs(b[0]-r0) + abs(b[1]-c0);
        });
        return res;
    }
};
__________________________________________________________________________________________________
128ms
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        queue<vector<int>> q;
        q.push({r0, c0});
        int drs [4] = {0, 0, 1, -1};
        int dcs [4] = {1, -1, 0, 0};
        vector<vector<bool>> seen(R, vector<bool>(C, false));
        seen[r0][c0] = true;
        vector<vector<int>> ans;
        while (!q.empty()) {
            auto node = q.front();
            ans.push_back(node);
            q.pop();
            int r = node[0], c = node[1];
            for(int k = 0; k < 4; ++k) {
                int newr = r + drs[k], newc = c + dcs[k];
                if (0 <= newr && newr < R && 0 <= newc && newc < C && seen[newr][newc] == false) {
                    seen[newr][newc] = true;
                    q.push({newr, newc});
                }
            }
        }
        return ans;
        
    }
};
__________________________________________________________________________________________________
132ms
class Solution {    
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                    int d = abs(i - r0) + abs(j - c0);
                    ans.push_back({d, i, j});
                }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            ans[i].erase(ans[i].begin());
        return ans;
    }
};
__________________________________________________________________________________________________