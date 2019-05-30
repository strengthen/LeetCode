__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
		int N = nums.length;
        int[] dp = new int[2*N];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < 2*N; i++) {
            dp[i] = Math.max(dp[i-1], dp[i-2]+nums[i >= N? i-N: i]);
        }
        return dp[2*N-1]-dp[N-1];
    }
}
__________________________________________________________________________________________________
sample 34160 kb submission
class Solution {
    public int rob(int[] nums) {
        if (nums.length==1) return nums[0];
        return Math.max(helper(nums, 0, nums.length - 2), helper(nums, 1, nums.length - 1));
    }
    
    public int helper(int[] nums, int lo, int hi){
        int rob = 0, notRob = 0;
        
        for (int i = lo; i <= hi; i++) {
            int r = rob;
            int n = notRob;
            rob = n + nums[i]; 
            notRob = Math.max(r, n);
        }
        
        return Math.max(rob, notRob);
    }
}
__________________________________________________________________________________________________
