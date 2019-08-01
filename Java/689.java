__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] sum = new int[n + 1];
        int[] posLeft = new int[n];
        int[] posRight = new int[n];
        int[] result = new int[3];
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        int maxSum = sum[k] - sum[0];
        for (int i = k; i < n; i++) {
            if (sum[i + 1] - sum[i + 1 - k] > maxSum) {
                maxSum = sum[i + 1] - sum[i + 1 - k];
                posLeft[i] = i + 1 - k;
            } else {
                posLeft[i] = posLeft[i - 1];
            }
        }
        maxSum = sum[n] - sum[n - k];
        posRight[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; i--) {
            if (sum[i + k] - sum[i] >= maxSum) {
                maxSum = sum[i + k] - sum[i];
                posRight[i] = i;
            } else {
                posRight[i] = posRight[i + 1];
            }
        }
        maxSum = 0;
        for (int i = k; i <= n - 2 * k; i++) {
            int l = posLeft[i - 1];
            int r = posRight[i + k];
            int temp = (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);
            if (temp > maxSum) {
                maxSum = temp;
                result[0] = l;
                result[1] = i;
                result[2] = r;
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 40144 kb submission
class Solution {
    /*
    思想： 到底是从什么题目演变的呢？ Maximum sum of subarrays with k length
    F[i] = nums[1...end] 选一个长度为k，max多少？
    S[i] = nums[1..end]选两个长度为k，max多少？
         = max(S[i+1], sum(nums[i...i+k-1]) + F[i+k])
    Z[i] = 选三个长度为k的，max多少呢？
         = max(Z[i+1], sum(nums[i...i+k-1]) + G[i+k])
    */
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] res = new int[3];
        int[] sum = new int[n+1];
        int[] left = new int[n];
        int[] right = new int[n];
        
        // sum start from 0 ... n
        for (int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + nums[i];
        }
        
        // left[i] means the start index of maximum sum subarray from 0...i, return the leftmost result
        for (int i = k, total = sum[k] - sum[0]; i < n; i++) {
            if (sum[i+1] - sum[i-k+1] > total) {
                total = sum[i+1] - sum[i-k+1];
                left[i] = i-k+1;
            } else {
                left[i] = left[i-1];
            }
        }
        System.out.println(Arrays.toString(left));
        
        // right[i] same with the left[i] from i...n-1, but start from n - k - 1
        // assume k = 2, right should start from n - 3
        right[n-k] = n - k;
        for (int i = n - k - 1, total = sum[n] - sum[n-k]; i >= 0; i--) {
            // n - 1 - (n - k - 1) = k
            // why >= : because of the leftmost result
            if (sum[i+k] - sum[i] >= total) {
                total = sum[i+k] - sum[i];
                right[i] = i;
            } else {
                right[i] = right[i+1];
            }
        }
        System.out.println(Arrays.toString(right));
        
        int maxsum = 0;
        for (int i = k; i <= n - 2 * k; i++) {
            int l = left[i-1], r = right[i+k];
            int total = sum[l+k] - sum[l] + sum[r+k] - sum[r] + sum[i+k] - sum[i];
            if (total > maxsum) {
                res[0] = l;
                res[1] = i;
                res[2] = r;
                maxsum = total;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
