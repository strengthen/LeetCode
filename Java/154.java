__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int findMin(int[] nums) {
        int start = 0, end = nums.length - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else if (nums[mid] < nums[end]) {
                end = mid;
            } else {
                end--;
            }
        }
        return nums[start];
    }
}
__________________________________________________________________________________________________
sample 34640 kb submission
class Solution {
    public int findMin(int[] nums) {
        int l = 0, h = nums.length - 1;
        while(l < h){
            int mid = l + (h - l)/2;
            System.out.println(l+" "+mid+" "+h);
            if(nums[h] > nums[mid]){// rotation in low to mid
                h = mid;
            }
            else if(nums[mid] > nums[h]){
                l = mid+1;
            }else{
                h--;
            }
        }
        return Math.min(nums[l],nums[h]);
    }
}
__________________________________________________________________________________________________
