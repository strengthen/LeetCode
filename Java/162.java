__________________________________________________________________________________________________
sample 0 ms submission
public class Solution {
    public int findPeakElement(int[] nums) {
        if (nums == null || nums.length == 0) {
            return -1;
        }
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
__________________________________________________________________________________________________
sample 34264 kb submission
class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0;
        int r = nums.length - 1;
        
        while (l < r) {
            int mid = (l + r) / 2;
            
            int leftValue = mid <= 0 ? Integer.MIN_VALUE : nums[mid-1];
            int rightValue = mid >= nums.length - 1 ? Integer.MIN_VALUE : nums[mid+1];
            if (nums[mid] > leftValue && nums[mid] > rightValue) {
                return mid;
            }
            
            if (rightValue > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return l;
    }
}
__________________________________________________________________________________________________
