__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int minScoreTriangulation(int[] A) {
        Integer[][] dp = new Integer[A.length][A.length];
        return helper(A, 0, A.length - 1, dp);
    }
    
    private int helper(int[] A, int lo, int hi, Integer[][] dp) {
        if (hi - lo < 2) return 0;
        if (dp[lo][hi] != null) return dp[lo][hi];
        int min = Integer.MAX_VALUE;
        for (int i = lo + 1; i < hi; ++i) {
            min = Math.min(min, helper(A, lo, i, dp) + helper(A, i, hi, dp) + A[i] * A[lo] * A[hi]);
        }
        dp[lo][hi] = min;
        return min;
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    
    private int minTriangulate(int[] A, int start, int end, int[][] memo) {
        if (memo[start][end] < 0) {
            if (end - start < 2) {
                memo[start][end] = 0;
            }
            else {
                int result = Integer.MAX_VALUE;
                for (int i = start + 1; i < end; i++) {
                    result = Math.min(result, this.minTriangulate(A, start, i, memo) + this.minTriangulate(A, i, end, memo) + A[start] * A[i] * A[end]);
                }
                memo[start][end] = result;
            }
        }
        return memo[start][end];
        
    }
    
    public int minScoreTriangulation(int[] A) {
        int n = A.length;
        int[][] memo = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = -1;
            }
        }
        
        return this.minTriangulate(A, 0, n - 1, memo);
    }
}
__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int minScoreTriangulation(int[] A) {
        if (A == null) {
            return 0;
        }
        int[][] dp = new int[A.length][A.length];
        
        for (int len = 3; len <= A.length; len++) {
            for (int i = 0; i + len - 1 < A.length; i++) {
                int j = i + len - 1;
                int sum = Integer.MAX_VALUE;
                for (int k = i + 1; k < j; k++) {
                    sum = Math.min(sum, dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]);
                }
                dp[i][j] = sum;
            }
        }
        return dp[0][A.length - 1];
    }
}