__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        
        int longest = 1;
        int maxLong = 0;
        
       // int startIndex = 0;
       // int endIndex = 0;
        
        if(nums.length == 0) {
            return 0;
        }
        
        int i = 0 ;
        
        boolean isSkippable = false;
        
        while( i < nums.length -1 ) {
            
            
            if(nums[i] < nums[i+1]) {
                
                
                if(!isSkippable ||
                   (isSkippable && isIncreasingSequence(i, i - longest + 1, nums))) {    
                    
                    longest++;                   
                    isSkippable = false;
                } 
                
                i++;
                
            } else {  
                // try to skip + longest
                i = longest + i;  
                isSkippable = true;
            }
            
           // System.out.println("i = "+i+" and longest = "+longest);
        }
        
        return longest;
        
    }
    
    public boolean isIncreasingSequence(int i, int j, int[]nums) {
        while(j < i) {
            if(nums[j] < nums[j+1]) {
                j++;
            } else {
                break; 
            }
        }
        
       return j == i;
    }
    
}
__________________________________________________________________________________________________
sample 39276 kb submission
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int[] dp = new int[nums.length];
        for (int i = 0; i < dp.length; i++) {
            dp[i] = 1;
        }
        
        int longest = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
                longest = Math.max(longest, dp[i]);
            }
        }
        return longest;
    }
}
__________________________________________________________________________________________________
