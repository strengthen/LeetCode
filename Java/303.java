__________________________________________________________________________________________________
sample 50 ms submission
class NumArray {

    private static int[] nums;

    private static int[] numTemp;

    public NumArray(int[] nums) {
        NumArray.nums = nums;
        numTemp = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (i > 0) {
                numTemp[i] = nums[i] + numTemp[i - 1];
            } else {
                numTemp[i] = nums[i];
            }
        }
    }

    public int sumRange(int i, int j) {
        return numTemp[j] - numTemp[i] + nums[i];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
__________________________________________________________________________________________________
sample 39860 kb submission
class NumArray {
    int[] sums = null ;
    public NumArray(int[] nums) {
        if(nums!=null){
            sums = new int[nums.length+1] ;
        }
       
        
        for(int i=0;i<sums.length-1;i++){
            sums[i+1]=sums[i]+nums[i];
        }
    }
    
    public int sumRange(int i, int j) {
        if(sums == null || sums.length == 0){
            return 0;
        }
        
        if(i<0){
            i=0;
        }
        
        if(j>sums.length-1){
            j=sums.length -1 ;
        }
        
        return sums[j+1] - sums[i] ;
        
       
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
__________________________________________________________________________________________________
