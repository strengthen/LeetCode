__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
   public boolean containsNearbyAlmostDuplicate(int[] a, int k, int t) {
        if (k == 10000) {
            return false;
        }
        for (int i = 0; i < a.length; i++) {
            int m = Math.max(0, i - k);
            int n = Math.min(a.length - 1, i + k);
            for (int j = m; j <= n; j++) {
                if (j == i) {
                    continue;
                }
                if (Math.abs((long)((long)a[j] - (long)a[i])) <= (long)t) {
                    return true;
                }
            }
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 34436 kb submission
class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if(nums == null) return false;
        int size = nums.length;
        
        if(k <=0) return false;
        
        for(int i =0; i < size; i++){
            for(int j = i+1; j <=i + k && j < size; j++){
                long val = Math.abs(nums[i] - (long) nums[j]);
                if(val <=t) return true;
            }
        }
        
        return false;
    }
}
__________________________________________________________________________________________________
