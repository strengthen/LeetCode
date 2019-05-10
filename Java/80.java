__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null)
            return 0;
        if(nums.length < 3)
            return nums.length;
                
        /*
        1,1,1,2,2,3
          i j 
        */
        int i = 1, j = 2;
        while (j < nums.length) {
            if (nums[j] == nums[i] && nums[i] == nums[i-1]) {
                j++;
            } else {
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        return i+1;
    }
}
__________________________________________________________________________________________________
sample 35436 kb submission
class Solution {
    public int removeDuplicates(int[] a) {
        int n=a.length,i=0;
   for (int k : a)
      if (i < 2 || k > a[i - 2])
         a[i++] = k;
   return i;
    }
}
__________________________________________________________________________________________________
