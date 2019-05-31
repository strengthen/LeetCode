__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int missingNumber(int[] nums) {
        int sum=0;
        for(int n: nums)
            sum += n;
        return nums.length*(nums.length+1)/2-sum;
        
    }
}
__________________________________________________________________________________________________
sample 36644 kb submission
class Solution {
    public int missingNumber(int[] nums) {
        
        int sum = 0;
        for(int n:nums)
        {
             sum+=n;
        } 
        return (nums.length * (nums.length+1)/2) - sum;
    }
}
__________________________________________________________________________________________________
