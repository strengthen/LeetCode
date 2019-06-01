__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int maxCoins(int[] nums) {
        int[] extended = new int[nums.length + 2];
        for (int i = 1; i < extended.length - 1; i++) {
            extended[i] = nums[i-1];
        }
        
        extended[0] = extended[nums.length+1] = 1;
        
        int[][] dp = new int[extended.length][extended.length];
        
        for (int n = 2; n < extended.length; n++) {
            for (int left = 0; left < extended.length - n; left++) {
                int right = left + n;
                int curr = 0;
                for (int i = left + 1; i < right; i++) {
                    curr = Math.max(curr, extended[left] * extended[i] * extended[right] + dp[left][i] + dp[i][right]);
                }
                dp[left][right] = curr;
            }
        }
        
        return dp[0][extended.length - 1];
    }
}
__________________________________________________________________________________________________
sample 33968 kb submission
class Solution {
    public int maxCoins(int[] nums) {
        int[] arr = new int[nums.length + 2];
        int n = 1;
        for (int num : nums) if (num > 0) arr[n++] = num;
        arr[0] = arr[n++] = 1;
        int[][] dp = new int[n][n];
        for (int len = 1; len <= n - 2; len++) {
            for (int i = 1; i <= n - 2 - len + 1; i++) {
                int j = i + len - 1;
                for (int k = i; k <= j ; k++) {
                    dp[i][j] = Math.max(dp[i][j], dp[i][k - 1] + arr[i - 1] * arr[k] * arr[j + 1] + dp[k + 1][j]);
                }
            }
        }
        return dp[1][n-2];
    }
}
__________________________________________________________________________________________________
