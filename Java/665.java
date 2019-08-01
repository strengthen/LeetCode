__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
 public boolean checkPossibility(int[] nums) {
        int cnt = 0;                                                                    //the number of changes
        for(int i = 1; i < nums.length && cnt<=1 ; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
                if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    //modify nums[i-1] of a priority
                else nums[i] = nums[i-1];                                                //have to modify nums[i]
            }
        }
        return cnt<=1; 
    }
}
__________________________________________________________________________________________________
sample 38744 kb submission
class Solution 
{
    public boolean checkPossibility(int[] nums) 
    {
        boolean modified = false;
        
        for(int i=0; i<nums.length; i++)
        {
            if(i+1 < nums.length && nums[i] > nums[i+1])
            {
                if(modified) // if modified a number already
                    return false;
                else // if it is first time to modify a number
                {
                    if(i-1 < 0 || nums[i+1] >= nums[i-1]) // if nums[i+1] is larger or equal all numbers before nums[i]
                        nums[i] = nums[i+1]; // change nums[i] as same as nums[i+1]
                    else // if nums[i+1] is not larger than all numbers before nums[i]
                        nums[i+1] = nums[i]; // change nums[i+1] as same as nums[i]
                    
                    modified = true;
                } 
            }
        }
        
        return true;
        
    }
}
__________________________________________________________________________________________________
