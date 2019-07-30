__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    int[][] memo;
    int[] sum;
    public int stoneGameII(int[] piles) {
        int n = piles.length;
        this.memo = new int[n][n];
        this.sum = new int[n];
        sum[n - 1] = piles[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            sum[i] = piles[i] + sum[i + 1];
        }
        
        return dp(piles, 0, 1);
    }
    
    private int dp(int[] piles, int start, int M) {
        if(start >= piles.length) return 0;
        if(start + 2 * M >= piles.length) return sum[start];
        
        if(memo[start][M] != 0) return memo[start][M];
        
        int min = Integer.MAX_VALUE;
        
        for(int i = 1; i <= 2 * M; i++) {
            min = Math.min(min, dp(piles, start + i, Math.max(i, M)));
        }
        
        memo[start][M] = sum[start] - min;
        return memo[start][M];
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
// memo[i][j] represents the following state:

// All piles with index < i have been picked.
// m = j.
    public int stoneGameII(int[] piles) {
        int[] sums = new int[piles.length];
        int[][] memo = new int[piles.length][piles.length];
        sums[0] = piles[0];
        
        for(int i = 1; i < sums.length; i++)
            sums[i] = sums[i - 1] + piles[i];
        
        dfs(0, 1, sums, memo);
        return memo[0][1];
    }
    
    int dfs(int i, int m, int[] sums, int[][] memo){
        
        if(i == sums.length)
            return 0;
        
        if(memo[i][m] != 0) return memo[i][m];
        
        int res = Integer.MAX_VALUE;
        
        for(int k = i; k < Math.min(sums.length, i + m * 2); k++)
            res = Math.min(res, dfs(k + 1, Math.max(m, k - i + 1), sums, memo));
        
        res = sums[sums.length - 1] - (i == 0 ? 0 : sums[i - 1]) - res;
        
        memo[i][m] = res;
        
        return res;
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution
{
    private int[][][] dp;
    private int n;

    private int solve(int[] piles, int total, int turn, int cur, int m)
    {
        if (cur == n) return 0;
        if (dp[turn][cur][m] < 0)
        {
            int sum = 0, best = 0;
            for (int x = 1; x <= 2 * m && cur + x - 1 < n; x++)
            {
                sum += piles[cur + x - 1];
                total -= piles[cur + x - 1];
                int res = sum;
                int op = solve(piles, total, (turn ^ 1) & 1, cur + x, Math.max(m, x));
                if (op != 0) res += total - op;
                best = Math.max(best, res);
            }
            dp[turn][cur][m] = best;
        }
        return dp[turn][cur][m];
    }

    public int stoneGameII(int[] piles)
    {
        n = piles.length;
        dp = new int[2][n][n];
        int total = 0;
        for (int i = 0; i < n; i++) total += piles[i];
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++) Arrays.fill(dp[i][j], -1);
        }
        return solve(piles, total, 0, 0, 1);
    }
}