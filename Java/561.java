__________________________________________________________________________________________________
sample 3 ms submission
public class Solution {
    public int arrayPairSum(int[] nums) {
        int[] numbers = new int[20001];
        for (int num : nums) numbers[num + 10000]++;
        int count = nums.length / 2;
        int sum = 0;
        boolean odd = false;
        for (int i = 20000 ; count > 0 ; i --) {
            if (numbers[i] > 0) {
                sum += (i - 10000) * (numbers[i] / 2);
                count -= numbers[i] / 2;
                if (numbers[i] % 2 == 0)
                    continue;
                if (odd) {
                    sum += (i - 10000);
                    count -= 1;
                }
                odd = !odd;
            }
        }
        return sum;
    }
} 
__________________________________________________________________________________________________
sample 40752 kb submission
class Solution {
    public int arrayPairSum(int[] nums) {
        if (nums == null){
            return 0;
        }
        Arrays.sort(nums);
        int sum = 0;
        
        for (int i = 0; i < nums.length; i += 2){
            sum += nums[i];
        }
        return sum;
    }
}
__________________________________________________________________________________________________
