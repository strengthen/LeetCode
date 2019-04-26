__________________________________________________________________________________________________
sample 4 ms submission
class Solution
{
public:
    int findPaths(int m, int n, int N, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || N < 1) return 0;
        
        long long** numpaths = new long long*[m];
        long long** numpathsAux = new long long*[m];
        for(int ii = 0; ii < m; ++ii)
        {
            numpaths[ii] = new long long[n]();
            numpathsAux[ii] = new long long[n]();
        }
        
        //initialization
        long long totalPaths = 0;        
        if (i == 0) ++totalPaths; else ++numpaths[i-1][j];
        if (i == m-1) ++totalPaths; else ++numpaths[i+1][j];
        if (j == 0) ++totalPaths; else ++numpaths[i][j-1];
        if (j == n-1) ++totalPaths; else ++numpaths[i][j+1];

        for(int NN = 2; NN <= N; ++NN)
        {
            for (int ii = 0; ii < m; ++ii)
            {
                for (int jj = 0; jj < n; ++jj)
                {
                    if(numpaths[ii][jj] > 0)
                    {
                        if (ii == 0) totalPaths += numpaths[ii][jj] % 1000000007; else numpathsAux[ii-1][jj] += numpaths[ii][jj] % 1000000007;
                        if (ii == m-1) totalPaths += numpaths[ii][jj] % 1000000007; else numpathsAux[ii+1][jj] += numpaths[ii][jj] % 1000000007;
                        if (jj == 0) totalPaths += numpaths[ii][jj] % 1000000007; else numpathsAux[ii][jj-1] += numpaths[ii][jj] % 1000000007;
                        if (jj == n-1) totalPaths += numpaths[ii][jj] % 1000000007; else numpathsAux[ii][jj+1] += numpaths[ii][jj] % 1000000007;
                        totalPaths % 1000000007;
                        numpaths[ii][jj] = 0;
                    }
                }
            }
            
            long long** tmp = numpaths;
            numpaths = numpathsAux;
            numpathsAux = tmp;
        }

        return totalPaths % 1000000007;
    }
};
__________________________________________________________________________________________________
sample 9576 kb submission
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        // denote dp[i][j][k] := under k steps, at (i, j), how many paths to escape?
        // dp[i][j][k] = dp[i - 1][j][k - 1] + dp[i + 1][j][k - 1] + dp[i][j - 1][k - 1] + dp[i][j + 1][k - 1];
        
        for (int k = 0; k < N; k++) {
            for (int ii = 0; ii <= m + 1; ii++) {
                dp[ii][0][k] = 1;
                dp[ii][n + 1][k] = 1;
            }
            for (int jj = 0; jj <= n + 1; jj++) {
                dp[0][jj][k] = 1;
                dp[m + 1][jj][k] = 1;
            }
        }
        for (int k = 0; k <= N; k++) {
            for (int ii = 1; ii <= m; ii++) {
                for (int jj = 1; jj <= n; jj++) {
                    if (k == 0) {
                        dp[ii][jj][k] = 0;
                    } else {
                        dp[ii][jj][k] = dp[ii - 1][jj][k - 1] + dp[ii + 1][jj][k - 1] + 
                            dp[ii][jj - 1][k - 1] + dp[ii][jj + 1][k - 1];
                        dp[ii][jj][k] %= 1000000007;
                    }
                }
            }
        }
        cout << dp[i+1][j+1][N] << endl;
        return (int)(dp[i + 1][j + 1][N] % 1000000007);
    }
private:
    unsigned int dp[52][52][51];
};
__________________________________________________________________________________________________
