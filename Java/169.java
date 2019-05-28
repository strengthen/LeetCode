__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int majorityElement(int[] nums) {
        //Boyer Moore Voting Algorithm
        int count = 0, candidateIdx = -1;
        for (int i = 0; i < nums.length; i++) {
            if (count == 0) {
                candidateIdx = i;
            }
            if (nums[i] == nums[candidateIdx]) {
                count++;
            } else {
                count--;
            }
        }
        return nums[candidateIdx];
        
    }
}
__________________________________________________________________________________________________
sample 36324 kb submission
class Solution {
    public int majorityElement(int[] nums) {
        int len = nums.length;
        return getNum(nums, 0, len - 1);
    }
    
    public int getNum(int[] nums, int low, int high){
        if(low == high)
            return nums[low];
        
        int mid = (low + high) / 2;
        int num1 = getNum(nums, low, mid);
        int num2 = getNum(nums, mid + 1, high);
        
        if(num1 == num2)
            return num1;
        
        int cont1 = getCount(nums, low, high, num1);
        int cont2 = getCount(nums, low, high, num2);
        if(cont1 > cont2)
            return num1;
        return num2;
        
    }
    
    public int getCount(int[] nums, int start, int end, int target){
        int cont = 0;
        for(int i=start; i<=end; i++){
            if(nums[i] == target)
                cont ++;
        }
        return cont;
    }
}
__________________________________________________________________________________________________
