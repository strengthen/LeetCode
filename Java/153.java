__________________________________________________________________________________________________
0 ms
class Solution {
    public int findMin(int[] num) {
    
        int start = 0;
        int end = num.length-1;
    
        if (num[start]<num[end]) return num[0];
        
        while(end-start>1){
            int mid = (end+start)/2;
            if (num[start]<num[mid]) start = mid;
            else end = mid;
        }        
        return num[end];
    }
}
__________________________________________________________________________________________________
sample 34364 kb submission
class Solution {
    public int findMin(int[] nums) {
        int min = nums[0];
        for(int i = 0; i < nums.length; i++){
            if(nums[i]<min){
                return nums[i];
            }
        }
        return min;
    }
}
__________________________________________________________________________________________________
