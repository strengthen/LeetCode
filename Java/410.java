__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int splitArray(int[] nums, int m) {
        if(nums == null || nums.length == 0 || m == 0) {
            return 0;
        }
        
        long upperBound = 0L;
        for(int num : nums) {
            upperBound += num;
        }
        
        long lowerBound = upperBound / m;
        while(lowerBound + 1 < upperBound) {
            long mid = (lowerBound + upperBound) / 2;
            if(isSplitable(nums, mid, m)) {
                upperBound = mid;
            } else {
                lowerBound = mid;
            }
        }
        
        if(isSplitable(nums, lowerBound, m)) {
            return (int) lowerBound;
        } else {
            return (int) upperBound;
        }
        
    }
    
    //split array using subSum, when the tmp sum is just bigger than subSum, cut it there
    private boolean isSplitable(int[] nums, long subSum, int m) {
        long tmpSum = 0;
        int subArrayLength = 0;
        int subArrays = 0;
        for(int num : nums) {
//             if(subArrays == m) {
//                 return false;
//             }
            
            if(num > subSum) {
                return false;
            }
        
            if(tmpSum + num > subSum) {
                subArrays++;  
                subArrayLength = 0;
                tmpSum = 0;
            }
            tmpSum += num;
            subArrayLength++;
        }
        
        if (subArrays < m) {
            return true;
        } 
        return false;       
    }
}
__________________________________________________________________________________________________
sample 33272 kb submission
class Solution {
    public int splitArray(int[] nums, int m) {
        int low = Arrays.stream(nums).max().orElse(-1);
        int high = Arrays.stream(nums).sum();
        while (low<high) {
            int maxAllowedSum = low + (high-low)/2;
            int numOfSubArrays = 1;
            for (int i=0, sum=0; i<nums.length; i++) {
                sum+=nums[i];
                if (sum>maxAllowedSum) {
                    numOfSubArrays++;
                    sum = nums[i];
                }
            }
            if (numOfSubArrays>m) low = maxAllowedSum+1;
            else high = maxAllowedSum;
        }
        return low;
    }
}
__________________________________________________________________________________________________
