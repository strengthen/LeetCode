__________________________________________________________________________________________________
4ms
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = int(obstacleGrid.size());
        int n = int(obstacleGrid[0].size());
        vector<vector<long>>dp(m,vector<long>(n,0));
        if(obstacleGrid[0][0] == 0) dp[0][0] = 1;
        for(int i =0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else {
                    if(i -1 >=0 && i - 1<m) dp[i][j] += dp[i-1][j];
                    if(j -1 >=0 && j - 1<n) dp[i][j] += dp[i][j-1];
                }
            }
        }
        return (int)dp[m-1][n-1];
    }
};
__________________________________________________________________________________________________
8896 kb
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        long dp[m][n] = {0};

        if(a[0][0] == 0) dp[0][0] = 1;

        for (int i = 1; i < m; i++){
          if (a[i][0] == 0) dp[i][0] = dp[i - 1][0];
          else dp[i][0] = 0;
        }

        for (int j = 1; j < n; j++){
          if (a[0][j] == 0) dp[0][j] = dp[0][j - 1];
          else dp[0][j] =0;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++){
                if(a[i][j] == 0)
                  dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};
__________________________________________________________________________________________________
