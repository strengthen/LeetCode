__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int findDuplicate(int[] nums) {
     
        if(nums.length < 2) return -1;
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        fast = 0;
        
        while(slow != fast){
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return slow;
    }
}
__________________________________________________________________________________________________
sample 34208 kb submission
class Solution {
    public int findDuplicate(int[] nums) {
        
        int lo=0; int hi=nums.length-1;
        while(lo<hi){
            int c=0;
            int mid=(lo+hi)/2;
            for(int n:nums){
                if (n<=mid)
                c+=1;
            }
            if(c<=mid) lo=mid+1;
            else hi=mid;
        }
      
    return lo;
   }
}
__________________________________________________________________________________________________
