__________________________________________________________________________________________________
sample 6 ms submission
class Solution {
    public int kInversePairs(int n, int k) {
        long[] top = new long[k + 1];
        long[] ps = new long[k + 2];
        final long MOD = 1000000007L;

        Arrays.fill(ps, 1, ps.length, 1);

        for (int i = 2; i <= n; ++i) {
            top[0] = 1;

            for (int j = 1; j <= k; ++j)
                top[j] = (ps[j + 1] - ps[Math.max(0, j - i + 1)]) % MOD;

            for (int j = 0; j <= k; ++j) {
                ps[j + 1] = ps[j] + top[j];
                top[j] = 0;
            }
        }

        return (int) (ps[k + 1] - ps[k]);
    }
}
__________________________________________________________________________________________________
sample 31752 kb submission
class Solution {
    private final int MOD = 1000000007;

  public int kInversePairs(int n, int k) {
    int[][] dp = new int[2][k + 1];
    dp[1][0] = 1;
    for (int i = 2; i <= n; ++i) {
      int idx = i & 1;
      dp[idx][0] = 1;
      int sub = 0;
      int prefixSum = 1;
      for (int j = 1; j <= k; ++j) {
        dp[idx][j] = ((prefixSum + dp[idx ^ 1][j]) % MOD - sub + MOD) % MOD;
        if (j >= i - 1) {
          sub = (sub + dp[idx ^ 1][j - i + 1]) % MOD;
        }
        prefixSum = (prefixSum + dp[idx ^ 1][j]) % MOD;
        if (dp[idx][j] == 0) {
          break;
        }
      }
    }
    return dp[n & 1][k];
  }
}
__________________________________________________________________________________________________
