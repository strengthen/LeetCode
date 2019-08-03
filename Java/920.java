__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int numMusicPlaylists(int N, int L, int K) {
        int MOD = 1_000_000_007;

        // dp[S] at time P = <S, P> as discussed in article
        long[] dp = new long[L - N + 1];
        Arrays.fill(dp, 1);
        for (int p = 2; p <= N - K; ++p)
            for (int i = 1; i <= L - N; ++i) {
                dp[i] += dp[i - 1] * p;
                dp[i] %= MOD;
            }

        // Multiply by N!
        long ans = dp[L - N];
        for (int k = 2; k <= N; ++k)
            ans = ans * k % MOD;
        return (int) ans;
    }
}
__________________________________________________________________________________________________
sample 31648 kb submission
class Solution {
    public int numMusicPlaylists(int N, int L, int K) {
        long MOD = (long)1e9 + 7;
        
        long[] dp = new long[L-N+1];        // 반복될 애들
        Arrays.fill(dp, 1);
        for (int p = 2; p <= N-K; ++p){     // ??
            for (int i = 1; i <= L-N; ++i) {    // dp 사이즈 => factorial
                dp[i] += dp[i-1] * p; 
                dp[i] %= MOD;
            }
        }
        
        // Multiply by N!
        long res = dp[L-N];
        for (int i = 2; i <= N; ++i)
            res = res * i % MOD;
        return (int) res;
    }
}
__________________________________________________________________________________________________
