__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int pivotIndex(int[] nums) {
        int left=0,right=0,index=0;
        for (int i=1; i<nums.length; i++){
            right = right+nums[i];
        }
        while (left!=right){
            index++;
            if (index==nums.length) break;
            left = left+nums[index-1];
            right = right-nums[index];
        }
        return (index==nums.length) ? -1 :index;
    }
}
__________________________________________________________________________________________________
sample 39048 kb submission
class Solution {
    public int pivotIndex(int[] nums) {
        // TODO verify
        if (nums.length == 1) {
            return 0;
        }

        int totalSum = Arrays.stream(nums).sum();
        int pivotIndex = 0;
        int pivotSum = 0;
        while (pivotIndex < nums.length) {
            if ((float)(totalSum - nums[pivotIndex]) / 2 == pivotSum) {
                return pivotIndex;
            }

            pivotSum += nums[pivotIndex];
            pivotIndex++;
        }

        return -1;
    }
}
__________________________________________________________________________________________________
