__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public double largestSumOfAverages(int[] A, int K) {
        int N = A.length;
        double[][] cache = new double[N + 1][K + 1];
        
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i];
            cache[i + 1][1] = (double) sum / (i + 1);
        }

        double ret = helper(A, cache, N, K);
        return ret;
    }
    
    private double helper(int[] A, double[][] cache, int n, int k) {
        if (k > n) return 0;
        if (cache[n][k] > 0) return cache[n][k];
        
        double ret = 0;
        int sum = 0;
        for (int i = n - 1; i >= k - 1; i--) {
            sum += A[i];
            ret = Math.max(ret, helper(A, cache, i, k - 1) + (double) sum / (n - i));
        }
        
        cache[n][k] = ret;
        return ret;
    }
}
__________________________________________________________________________________________________
sample 35500 kb submission
class Solution {
    public double largestSumOfAverages(int[] A, int K) {
        int N = A.length;
        double[] P = new double[N+1];
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + A[i];

        double[] dp = new double[N];
        for (int i = 0; i < N; ++i)
            dp[i] = (P[N] - P[i]) / (N - i);

        for (int k = 0; k < K-1; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = i+1; j < N; ++j)
                    dp[i] = Math.max(dp[i], (P[j]-P[i]) / (j-i) + dp[j]);

        return dp[0];
    }
}
__________________________________________________________________________________________________
