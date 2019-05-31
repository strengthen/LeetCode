__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n= nums.length;
        int[] output = new int[n];
        int temp = 1;
        
        for(int i=0;i<n;i++){
            output[i]=temp;
            temp*=nums[i];
        }
        temp=1;
        
        for(int i=n-1;i>=0;i--){
            output[i]*=temp;
            temp*=nums[i];
        }
        return output;
    }
}
__________________________________________________________________________________________________
sample 38936 kb submission
class Solution {
    public int[] productExceptSelf(int[] nums) {
        if(nums.length<2) return nums;
        int l=nums.length;
        int[] right=new int[l];
        int idx=l-1;
        right[idx--]=1;
        while(idx>=0){
            right[idx]=right[idx+1]*nums[idx+1];
            idx--;
        }
        idx=0;
        int left=1,temp=0;
        while(idx<=l-1){
            temp=nums[idx];
            nums[idx]=left*right[idx];
            left = left * temp;
            idx++;
        }
        return nums;        
    }
}
__________________________________________________________________________________________________
