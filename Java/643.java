__________________________________________________________________________________________________
sample 2 ms submission
//fix size sliding window
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        long sum = 0;
        //init sliding window
        for (int fast = 0; fast < k; fast++) {
            sum += nums[fast];
        }
        long max = sum;
        //moving sliding window
        for (int fast = k; fast < nums.length; fast++) {
            sum += nums[fast] - nums[fast - k];
            max = Math.max(max, sum);
        }  
        return max / 1.0 / k;
    }
}
__________________________________________________________________________________________________
sample 40028 kb submission
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = sum[i - 1] + nums[i]; 
        }
        double res = sum[k - 1] * 1.0 / k;
        for (int i = k; i < nums.length; i++) {
            res = Math.max(res, (sum[i] - sum[i - k]) * 1.0 / k);
        }
        return res;
    }
}
__________________________________________________________________________________________________
