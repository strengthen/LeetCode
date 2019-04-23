__________________________________________________________________________________________________
8ms
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int n=grid.size(),m=n?grid[0].size():0;
        vector<int> dp(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i|j) dp[j]=min(i?dp[j]:INT_MAX,j?dp[j-1]:INT_MAX);
                dp[j] += grid[i][j];
            }
        }
        return dp[m-1];
    }
};
static auto _=[](){ios::sync_with_stdio(false);return 0;}();
__________________________________________________________________________________________________
10468 kb
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (i > 0 && j > 0)
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                else if (i > 0)
                    grid[i][j] += grid[i - 1][j];
                else if (j > 0)
                    grid[i][j] += grid[i][j - 1];
            }
        
        return grid[m - 1][n - 1];
    }
};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
