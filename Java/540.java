__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int left = 0;
        int right = nums.length / 2;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid * 2] != nums[mid * 2 + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left * 2];
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int count = 0;
        //special for array length 0
        if (nums.length == 0) return 0;
        //special for array length 1
        if (nums.length == 1) return nums[0];
        
        for (int i = 0; i < nums.length-1; i++) {
            //special for start of array
            if (nums[0] != nums[1]) {
                return nums[0];
            }
            if (i > 0 && nums[i-1] != nums[i] && nums[i] != nums[i+1]) {
                return nums[i];
            } 
            
        }
        //special for end of array
        return nums[nums.length-1];
    }
}
__________________________________________________________________________________________________
sample 37156 kb submission
class Solution {
    public int singleNonDuplicate(int[] nums) {
        
        int result = 0;
        
        for( int i = 0; i < nums.length; i++) {
            result = result ^ nums[i];
        }
        
        return result;
        
    }
}