__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int minMoves(int[] nums) {
        int min = nums[0], res = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < min) {
                res += (min - nums[i]) * i;
                min = nums[i];
            }
            else
                res += nums[i] - min;
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 38544 kb submission
class Solution {
    public int minMoves(int[] nums) {
        int sum = Arrays.stream(nums).sum();
        int min = Arrays.stream(nums).min().orElse(0);
        // sum + m(nums.length-1) = (min+m) * nums.length;
        // sum + m(len-1) = min*len + m*len
        // sum + m*len - m = min*len + m*len
        // sum - m = min*len
        // m = sum - min*len;
        return sum - (min * nums.length);
    }
}
__________________________________________________________________________________________________
