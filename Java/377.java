__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] dp;
    public int combinationSum4(int[] nums, int target) {
        if (nums == null || nums.length == 0) return 0;
        dp = new int[target + 1];
        Arrays.fill(dp, -1);
        dp[0] = 1;
        return helper(nums, target);
    }
    
    public int helper(int[] nums, int target) {
        if (dp[target] != -1) return dp[target];
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            if (target >= nums[i]) {
                res += helper(nums, target - nums[i]);
            }
        }
        dp[target] = res;
        return res;
    }
}
__________________________________________________________________________________________________
sample 32668 kb submission
class Solution {
public int combinationSum4(int[] nums, int target) {
    if(nums == null || nums.length == 0) return target == 0 ? 1 : 0;
    // w[sum] += w[sum - nums[0 to n]] 
    // return w[target], for every 
    int[] w = new int[target + 1];
    w[0] = 1;
    //深层的原因是 [2,1] 和 [1,2]算是两种sum to 3的方式,所以保证, 使用2之后能再次使用1
    /*如果将两个for loop位置调换,那么[1,2,3], target=4, 得到的结果是4, 意味着顺序不考虑
    */
    for (int sum = 1; sum <= target; sum++){
        for(int i = 0; i < nums.length; i++){ 
            w[sum] += (sum - nums[i]) >= 0 ? w[sum-nums[i]] : 0;
        }
    }
    return w[target];
 }
}
__________________________________________________________________________________________________
