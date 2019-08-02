__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int dominantIndex(int[] nums) {
        if (nums.length==1) return 0;
        int max1 = 0,max2 =0, m1Index=0, m2Index=0;
        for (int i=0;i<nums.length;i++){
            if (nums[i]>max1){
                max2 = max1;
                max1 = nums[i];
                m2Index = m1Index;
                m1Index = i;
            }else if (nums[i]>=max2){
                max2 = nums[i];
                m2Index = i;
            }
        }
        return (nums[m2Index]*2<=nums[m1Index]) ? m1Index : -1;        
    }
}
__________________________________________________________________________________________________
sample 36764 kb submission
class Solution {
    public int dominantIndex(int[] nums) {
        int maxIdx = 0;
        int max = Integer.MIN_VALUE;
        int secMax = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > max) {
                secMax = max;
                max = nums[i];
                maxIdx = i;
            } else if (nums[i] > secMax) {
                secMax = nums[i];
            }
        }

        return nums[maxIdx] >= secMax * 2 ? maxIdx : -1;
    }
}
__________________________________________________________________________________________________
