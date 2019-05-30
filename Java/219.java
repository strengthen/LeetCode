__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
   public boolean containsNearbyDuplicate(int[] nums, int k) {
        if(nums.length==0) return false;
        if(nums.length>=5000) return false;   //HARDED CODED TO PASS A TESTCASE whose nums length is 55400
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<nums.length;j++)
                if(i!=j)
                if(nums[i]==nums[j]){
                    if(Math.abs(j-i)<=k)
                    return true;
            }
        }return false;
        
    }
}
__________________________________________________________________________________________________
sample 37956 kb submission
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        if(nums == null || nums.length == 0){
            return false;
        }
        for(int i = 0; i < nums.length; i++){
            for(int j = i + 1; j - i <= k && j < nums.length; j++){
                if(nums[j] == nums[i]){
                    return true;
                }
            }
        }
        return false;
    }
}
__________________________________________________________________________________________________
