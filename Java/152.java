__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int maxProduct(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        int max = Integer.MIN_VALUE;
        int product = 1;
        for (int i=0; i<nums.length; i++) {
            product *= nums[i];
            max = Math.max(max, product);

            if (product == 0) {
                product = 1;
            }
        }

        product = 1;
        for (int i=nums.length-1; i>=0; i--) {
            product *= nums[i];
            max = Math.max(max, product);

            if (product == 0) {
                product = 1;
            }
        }

        return max;
    }
}
__________________________________________________________________________________________________
sample 34212 kb submission
class Solution {
    public int maxProduct(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int max = nums[0];
        int min = nums[0];
        
        int result = nums[0];
        
        for(int i = 1; i<nums.length; i++){
            int a = max*nums[i];
            int b = min*nums[i];
            
            max = Math.max(Math.max(a,b), nums[i]);
            min = Math.min(Math.min(a,b), nums[i]);
            
            result = Math.max(result, max);
        }
        return result;
    }      
}
__________________________________________________________________________________________________
