__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        long dp[N + 1][L + 1], mod = 1e9 + 7;
        for (int i = K + 1; i <= N; ++i)
            for (int j = i; j <= L; ++j)
                if ((i == j) || (i == K + 1))
                    dp[i][j] = factorial(i);
                else
                    dp[i][j] = (dp[i - 1][j - 1] * i + dp[i][j - 1] * (i - K))  % mod;
        return (int) dp[N][L];
    }

    long factorial(int n) {
        return n ? factorial(n - 1) * n % (long)(1e9 + 7) : 1;
    }
};
__________________________________________________________________________________________________
sample 8628 kb submission
class Solution {
public:
    // dp[4][3] = dp[3][2]*(3-2) + dp[3][3]*(3-1) = 6*1 + 6*2 = 18
    // dp[3][2] = [1,2,1],[2,1,2],[2,3,2],[3,2,3],[1,3,1],[3,1,3]
    // dp[3][3] = [1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]
    
    int numMusicPlaylists(int N, int L, int K) {
        int mod = pow(10, 9) + 7;
        long int dp[L+1][N+1];
        dp[0][0] = 1;
        for(int i=1; i<=L; i++) dp[i][0] = 0;
        for(int i=1; i<=N; i++) dp[0][i] = 0;
        for (int i = 1; i <= L; i++){
            for (int j = 1; j <= N; j++){
                dp[i][j] = (dp[i-1][j-1] * (N - (j-1)))%mod; 
                if (j > K){
                    dp[i][j] = (dp[i][j] + (dp[i-1][j] * (j-K))%mod)%mod;
                }
                //cout << i <<" "<<j<< " "<< dp[i][j] << endl;
            }
        }
        return (int)dp[L][N];
    }
};
__________________________________________________________________________________________________
