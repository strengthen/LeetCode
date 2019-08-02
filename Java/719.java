__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
   public int cnt(int[] nums, int tag) {
        int ret = 0;
        for (int i = nums.length - 1, j = nums.length - 1; i >= 0; i--) {
            while (j > i && nums[j]- nums[i] > tag) j--;
            ret += j - i;
        }
        return ret;
    }


    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int l = 0, r = Integer.MAX_VALUE;
        while (l < r) {
            int m = (l + r) >> 1;
            if (cnt(nums, m) >= k) r = m;
            else l = m + 1;
        }
        return l;
    }
}
__________________________________________________________________________________________________
sample 38312 kb submission
class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int low = Integer.MAX_VALUE;
        for(int i = 1; i < nums.length; i++){
            low = Math.min(low, nums[i]-nums[i-1]);
        }
        int high = nums[nums.length-1]-nums[0];
        while(low<high){
            int mid = low + (high-low)/2;
            int count = helper(nums, mid);
            if(count<k){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }
    public int helper(int[] nums, int mid){
        int result = 0;
        for(int i = 0; i < nums.length; i++){
            int j = i + 1;
            while(j < nums.length && nums[j]-nums[i]<= mid){
                j++;
            }
            result += (j-i-1);
        }
        return result;
    }
}
__________________________________________________________________________________________________
