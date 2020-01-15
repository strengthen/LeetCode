__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        /* dp[i][j] = maximum sum get reach at (i, j)
         * dp[i][j] = max{dp[i+1][j], dp[i][j+1], dp[i+1][j+1]} + board[i][j];
         * dp[M][j] = dp[M][j+1] + board[M][j];
         * dp[i][N] = dp[i+1][N] + board[i][N];
         */
        int bigM = 1e9 + 7;
        
        int M = board.size(), N = (M == 0) ? (0) : (board[0].size());
        if ((M == 0) || (N == 0)){return vector<int>({0, 0});}
        
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        vector<vector<int>> np(M + 1, vector<int>(N + 1, 0));
        
        np[M-1][N-1] = 1; dp[M-1][N-1] = 0;
        for (int j = N-2; j >= 0; --j){
            dp[M-1][j] = (board[M-1][j] == 'X') ? (-1) : ((dp[M-1][j+1] == (-1)) ? (-1) : (dp[M-1][j+1] + (board[M-1][j] - '0')));
            np[M-1][j] = (dp[M-1][j] == (-1)) ? (0) : (1);
        }

        for (int i = M-2; i >= 0; --i){
            dp[i][N-1] = (board[i][N-1] == 'X') ? (-1) : ((dp[i+1][N-1] == (-1)) ? (-1) : (dp[i+1][N-1] + (board[i][N-1] - '0')));
            np[i][N-1] = (np[i][N-1] == (-1)) ? (0) : (1);
        }
        
        for (int i = M - 2; i >= 0; --i){
            for (int j = N - 2; j >= 0; --j){
                if (board[i][j] == 'X'){
                    dp[i][j] = (-1);
                    np[i][j] = ( 0);
                    continue;
                }
                int maxs = (-1);
                // if (dp[i+1][j+1] != (-1))
                {
                    maxs = max(maxs, dp[i+1][j+1]);
                }
                // if (dp[i+1][j+0] != (-1))
                {
                    maxs = max(maxs, dp[i+1][j+0]);
                }
                // if (dp[i+0][j+1] != (-1))
                {
                    maxs = max(maxs, dp[i+0][j+1]);
                }
                
                if (maxs == (-1)){
                    dp[i][j] = (-1);
                    np[i][j] = ( 0);
                    continue;
                }
                
                int64_t nps = 0;
                if (maxs == dp[i+1][j+1]){
                    nps += np[i+1][j+1];
                }
                if (maxs == dp[i+1][j+0]){
                    nps += np[i+1][j+0];
                }
                if (maxs == dp[i+0][j+1]){
                    nps += np[i+0][j+1];
                }
                
                dp[i][j] = maxs + (((i | j) == 0) ? (0) : (board[i][j] - '0'));
                np[i][j] = (nps % bigM); 
                
                // printf("dp[%2d][%2d] = %2d\n", i, j, dp[i][j]);
            }
        }
        
        dp[0][0] = (dp[0][0] == (-1)) ? (0) : (dp[0][0]);
        return vector<int>({dp[0][0], np[0][0]});
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
        const int n = board.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        vector<vector<int>> cc(n + 1, vector<int>(n + 1, 0));
        board[n - 1][n - 1] = board[0][0] = '0';
        cc[n - 1][n - 1] = 1;
        for (int i = n - 1; i >= 0; --i)
          for (int j = n - 1; j >= 0; --j) {
            if (board[i][j] != 'X') {          
              int m = max({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
              dp[i][j] = (board[i][j] - '0') + m;
              if (dp[i + 1][j] == m) cc[i][j] = (cc[i][j] + cc[i + 1][j]) % MOD;
              if (dp[i][j + 1] == m) cc[i][j] = (cc[i][j] + cc[i][j + 1]) % MOD;
              if (dp[i + 1][j + 1] == m) cc[i][j] = (cc[i][j] + cc[i + 1][j + 1]) % MOD;
            }
          }
        return {cc[0][0] ? dp[0][0] : 0, cc[0][0]};
    }
};
__________________________________________________________________________________________________
