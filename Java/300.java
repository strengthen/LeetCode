__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length + 1];
        int size = 0;
        dp[0] = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > dp[size]) {
                dp[++size] = nums[i];
            } else {
                int idx = binarySearch(dp, size, nums[i]);
                dp[idx] = nums[i];
            }
        }
        return size;
    }
    
    private int binarySearch(int[] a, int size, int target) {
        int lo = 0;
        int hi = size;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] >= target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
}
__________________________________________________________________________________________________
sample 33980 kb submission
class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] minLast = new int[nums.length + 1];
        Arrays.fill(minLast, Integer.MAX_VALUE);
        minLast[0] = Integer.MIN_VALUE;
        for(int i = 0; i < nums.length; i++) {
            int index = binarySearch(minLast, nums[i]);
            minLast[index] = nums[i];
        }
        for(int i = minLast.length - 1; i >= 1; i--) {
            if(minLast[i] != Integer.MAX_VALUE)
                return i;
        }
        return 0;
    }
    private int binarySearch(int[] minLast, int target) {
        int left = 0, right = minLast.length - 1;
        while(left + 1 < right) {
            int mid = (right - left) / 2 + left;
            if(minLast[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }
}
__________________________________________________________________________________________________
