__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public void sortColors(int[] nums) {
        int r = 0, i =0, b = nums.length-1;
        while(i <= b){
            if(nums[i] == 0){
                swap(nums, i++, r++);
            }else if(nums[i] == 1){
                i++;
            }else {
                swap(nums, i, b--);
            }
        } 
    }
    void swap(int [] nums, int a, int b){
        int t = nums[a];
        nums[a] = nums[b];
        nums[b] = t;
    }
}
__________________________________________________________________________________________________
sample 34600 kb submission
class Solution {
    public void sortColors(int[] nums) {
        int p1 = 0, p2 = nums.length - 1, index = 0;
        while(index <= p2){
            if(nums[index] == 0){
                // swap p1 and index numbers
                nums[index] = nums[p1];
                nums[p1++] = 0;
            }
            if(nums[index] == 2){
                nums[index] = nums[p2];
                nums[p2--] = 2;
            }
            if(nums[index] == 1 || index < p1){
                index++;
            }
        }
    }
}
__________________________________________________________________________________________________
