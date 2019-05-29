__________________________________________________________________________________________________
sample 1 ms submission
/* Naive Approch O(n2)
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int minLength = Integer.MAX_VALUE;  
        for (int index = 0; index < nums.length; index++) {
            int sum = 0;
            for (int pointer = index; pointer < nums.length; pointer++) {
                sum += nums[pointer];
                if (sum >= s) {
                    minLength = Math.min(minLength, pointer - index + 1);
                    break;
                }
            }
        }
        return minLength == Integer.MAX_VALUE ? 0 : minLength;
    }
}
*/

class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int minLength = Integer.MAX_VALUE;
        int left = 0;
        int sum = 0;
        for (int index = 0; index < nums.length; index++) {
            sum += nums[index];
            while (sum >= s) {
                minLength = Math.min(minLength, index - left + 1);
                sum -= nums[left++];
            }
        }
        return minLength == Integer.MAX_VALUE ? 0 : minLength;
    }
}
__________________________________________________________________________________________________
sample 35040 kb submission
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int i = 0, j = 0, sum = 0, curMin = Integer.MAX_VALUE;
        while(j < nums.length){
            sum += nums[j++];
            while(sum >= s){
                curMin = Math.min(curMin,j-i);
                sum -= nums[i++];
            }
        }
        return curMin == Integer.MAX_VALUE ? 0 : curMin;
    }
}
__________________________________________________________________________________________________
