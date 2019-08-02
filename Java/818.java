__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int racecar(int target) {
        return racecarHelper(target, new int[target + 1]);
    }

    private int racecarHelper(int target, int[] dp) {
        if (dp[target] != 0) {
            return dp[target];
        }

        // 2^(n-1) <= target < 2^n
        int n = (int) (Math.log(target) / Math.log(2)) + 1;

        if ((1 << n) == target + 1) {
            dp[target] = n;
        } else {
            //          "A" for n times
            //              "R"
            dp[target] = n + 1 + racecarHelper(((1 << n) - 1) - target, dp);

            for (int m = 0; m < n - 1; m++) {
                //                                "A" for (n - 1) times
                //                                         "RR"
                //                                             "A" for m times
                dp[target] = Math.min(dp[target], (n - 1) + 2 + m + racecarHelper(target - (((1 << (n - 1)) - 1) - ((1 << m) - 1)), dp));
            }
        }

        return dp[target];
    }
}
__________________________________________________________________________________________________
sample 31876 kb submission
class Solution {
    public int racecar(int target) {
        int[] dp = new int[target + 1];
        for (int i = 1; i <= target; i++) {
            dp[i] = Integer.MAX_VALUE;
            int m = 1, j = 1; 
            for (; j < i; j = (1 << ++m) - 1) {
                for (int p = 0, q = 0; q < j; q = (1 << ++p) - 1)
                    dp[i] = Math.min(dp[i], m + 1 + p + 1 + dp[i - (j - q)]);
            }
            dp[i] = Math.min(dp[i], m + (i == j ? 0 : 1 + dp[j - i]));
        }
        return dp[target];
    }
}
__________________________________________________________________________________________________
