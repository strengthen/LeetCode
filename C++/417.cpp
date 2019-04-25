__________________________________________________________________________________________________
sample 32 ms submission
class Solution {
    // we need to check down, up, left and right directions
    vector<vector<int>> dr = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> v;
        if(matrix.empty() || matrix[0].empty()) return v;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, false)), atlantic(m, vector<int>(n, false));

        //start from top and down boundary
        for(int i = 0; i < m; i++) {
            dfs(matrix, i, 0, INT_MIN, pacific);
            dfs(matrix, i, n-1, INT_MIN, atlantic);
        }
        
        //do the same steps as above for left and right boundary touching pacific and atlantic ocean resp.
        for(int j = 0; j < n; j++) {
            dfs(matrix, 0, j, INT_MIN, pacific);
            dfs(matrix, m-1, j, INT_MIN, atlantic);
        }
        
        //points that are reachable from both pacific and atlantic go to result vector
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) v.push_back({i, j});
            }
        }
        
        return v;
    }
    
    void dfs(auto &matrix, int i, int j, int prev, auto &seen) {
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() 
           || matrix[i][j] < prev || seen[i][j]) return;
        seen[i][j] = true;
        for(int k = 0; k < dr.size(); k++) {
            dfs(matrix, i+dr[k][0], j+dr[k][1], matrix[i][j], seen);
    }
}
};
static auto s = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;   
}();
__________________________________________________________________________________________________
sample 13484 kb submission
class Solution {

public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) return {};
        
        int n(matrix.size()), m(matrix[0].size());

        vector<pair<int,int>> res;
        
        queue<pair<int,int>> que;
        int state[n][m] = {};
        state[0][m-1] = state[n-1][0] = 3;
        
        for (int i = 0; i < n; ++i) {
            state[i][0] |= 1;
            state[i][m-1] |= 2;
            if (state[i][0] == 3) res.push_back({i,0});
            
            que.push({i,0});
            if (m > 1) {
                que.push({i,m-1});
                if (state[i][m-1] == 3) res.push_back({i,m-1});
            }
        }
        
        for (int j = 1; j < m-1; ++j) {
            state[0][j] |= 1;
            state[n-1][j] |= 2;
            if (state[0][j] == 3) res.push_back({0,j});
            
            que.push({0,j});
            if (n > 1) {
                que.push({n-1,j});
                if (state[n-1][j] == 3) res.push_back({n-1,j});
            }
        }
       
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
         
        while (!que.empty()) {
            int i(que.front().first), j(que.front().second); que.pop();

            for (auto d : dirs) {
                int r(i+d[0]), c(j+d[1]);
                if (r < 0 || c < 0 || r == n || c == m) continue;
                if (matrix[r][c] >= matrix[i][j] && (state[i][j] | state[r][c]) != state[r][c]) {
                    state[r][c] |= state[i][j];
                    if (state[r][c] == 3) res.push_back({r,c});
                    que.push({r,c});
                }
            }
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
