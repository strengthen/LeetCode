__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int search(int[] nums, int target) {
        int lo = 0;
		int hi = nums.length - 1;
		
		while(lo + 1 < hi) {
			int mid = lo + (hi - lo) / 2;
			if(nums[mid] == target)
				return mid;
			else if(nums[mid] < target)
				lo = mid;
			else hi = mid;
		}
		return nums[lo] == target ? lo : (nums[hi] == target ? hi: - 1);
        
    }
}
__________________________________________________________________________________________________
sample 37264 kb submission
class Solution {
    public int search(int[] nums, int target) {
        int index = -1;
        // if(target < nums.length){
            Arrays.stream(nums).anyMatch(number -> number == target);
            for(int i = 0;i<nums.length;i++) {
                if(nums[i] == target){
                    index = i;
                    break;
                }
            // }
        }
        return index;
    }
}
__________________________________________________________________________________________________
