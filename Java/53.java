__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int maxSubArray(int[] nums) {
        
        int maxSum = Integer.MIN_VALUE;
        int sum = 0;
        for(int i : nums)
        {
            sum = sum +i;
            if(sum > maxSum)
                maxSum = sum;
            if(sum <=0)
                sum =0;
        }
        return maxSum;
    }
}
__________________________________________________________________________________________________
sample 35600 kb submission
class Solution {
    public int maxSubArray(int[] nums) {
        int globalMax = nums[0];
        int cur = nums[0];
        for(int i = 1; i < nums.length; i++) {
            
            if(cur < 0) {                
                cur = nums[i];
            }
            else {
                cur = cur + nums[i];
            }
            globalMax = Math.max(globalMax, cur);
        }
        return globalMax;
    }
}
__________________________________________________________________________________________________
