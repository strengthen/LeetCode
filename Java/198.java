__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int rob(int[] nums) {
        if(nums == null || nums.length == 0){
            return 0;
        }
        
        int n = nums.length;
        int[] f = new int[n];
        
        for(int i = 0; i < n; ++i){
            if(i == 0){
                f[i] = nums[0];
            }else if(i == 1){
                f[1] = (nums[1] > nums[0] ? nums[1] : nums[0]);
            }else{
                f[i] = Math.max(f[i - 1],nums[i] + f[i-2]);
            }
        }
        
        return f[n-1];
    }
}
__________________________________________________________________________________________________
sample 33388 kb submission
import java.util.stream.IntStream;

class Solution {
    public int rob(int[] nums){
        if(nums.length < 1)
            return 0;
        if(nums.length == 1)
            return nums[0];
        final int[] sum = new int[nums.length];
        IntStream.range(0,nums.length).forEach(i -> sum[i]=0);
        sum[0] = nums[0];
        sum[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        for(int i=2;i<=nums.length-1;i++){
            int type1 = sum[i-2] + nums[i];
            int type2 = sum[i-1];
            sum[i] = type1 > type2 ? type1 : type2;
        }
        return sum[nums.length-1];
    }
}
__________________________________________________________________________________________________
