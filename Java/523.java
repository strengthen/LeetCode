__________________________________________________________________________________________________
sample 2 ms submission
public class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int sum = 0;
        HashMap < Integer, Integer > map = new HashMap < > ();
        map.put(0, -1);
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (k != 0)
                sum = sum % k;
            if (map.containsKey(sum)) {
                if (i - map.get(sum) > 1)
                    return true;
            } else
                map.put(sum, i);
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 38980 kb submission
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        if (nums.length <= 1) {
            return false;
        }
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            dp[i] = dp[i - 1] + nums[i];
            if (k == 0) {
                if(dp[i] == 0) {
                    return true;
                }
            } else if (dp[i] % k == 0) {
                return true;
            }
            for (int j = 0; j < i - 1; j++) {
                int sum = dp[i] - dp[j];
                if (k == 0 ) {
                    if (sum == 0) {
                        return true;
                    }
                } else if (sum % k == 0) {
                    return true;
                }
            }
        }
        return false;
    }
}
__________________________________________________________________________________________________
