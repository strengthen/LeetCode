__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    private int helper(int[][] dp, int h, int w, int[][] A, int H, int W){
        if(h >= H || w >= W)
            return 0;
        if(dp[h][w] != 0)
            return dp[h][w];
        int left = (w==0) ? Integer.MAX_VALUE : A[h][w-1] + helper(dp, h+1, w-1, A, H, W);
        int mid = A[h][w] + helper(dp, h+1, w, A, H, W);
        int right = (w==W-1) ? Integer.MAX_VALUE : A[h][w+1] + helper(dp, h+1, w+1, A, H, W);
        dp[h][w] = Math.min(left, Math.min(mid, right));
        return dp[h][w];
    }
    public int minFallingPathSum(int[][] A) {
        int choices = A[0].length;
        int levels = A.length;
        int[][] dp = new int[levels][choices];
        for(int j = 0; j < choices; j++)
            dp[0][j] = A[0][j] + helper(dp, 1, j, A, levels, choices);
        int res = Integer.MAX_VALUE;
        for(int i = 0; i < choices; i++)
            if(dp[0][i] < res)
                res = dp[0][i];
        return res;
    }
}
__________________________________________________________________________________________________
sample 35908 kb submission
class Solution {
    public int minFallingPathSum(int[][] A) {
      for (int i = 1; i < A.length; ++i)
        for (int j = 0; j < A.length; ++j)
          A[i][j] += Math.min(A[i - 1][j], Math.min(A[i - 1][Math.max(0, j - 1)], A[i - 1][Math.min(A.length - 1, j + 1)]));
      return Arrays.stream(A[A.length - 1]).min().getAsInt();
    }        
}
__________________________________________________________________________________________________
