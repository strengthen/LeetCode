__________________________________________________________________________________________________
class Solution {    
    public boolean canDivideIntoSubsequences(int[] nums, int K) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int mx = 0;
        for (int i = 0; i < nums.length; i++) {
            cnt.put(nums[i], cnt.getOrDefault(nums[i], 0) + 1);
            mx = Math.max(mx, cnt.get(nums[i]));
        }
        
        if ((long) mx * K > nums.length) return false;
        return true;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
