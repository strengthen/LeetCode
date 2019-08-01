__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0;
        if (nums != null && nums.length > 0) {
            int pos = 0;
            while(pos < nums.length) {
                int count = 0;
                while(nums[pos++] == 1) {
                    count++;
                    if (pos == nums.length) {
                        break;
                    }
                }
                if (count > 0 && max < count) {
                    max = count;
                }
            }
        } 
        return max;
    }
}
__________________________________________________________________________________________________
sample 39136 kb submission
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count = 0;
        int act = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                act++;
            }
            if (act > count) {
                count = act;
            }
            if(nums[i] == 0) {
                act=0;
            }
        }
        return count;
        
    }
}
__________________________________________________________________________________________________
