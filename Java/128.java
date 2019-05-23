__________________________________________________________________________________________________
sample 2 ms submission
import java.util.Arrays;

/*
 * @lc app=leetcode id=128 lang=java
 *
 * [128] Longest Consecutive Sequence
 */
class Solution {
    public int longestConsecutive(int[] nums) {
    if (nums == null || nums.length == 0) return 0;

        int curr = 1;
        int res = 1;

        Arrays.sort(nums);

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] !=  nums[i - 1]){
                if (nums[i] == nums[i - 1] + 1) {
                    curr++;
                } else {
                    res = Math.max(curr, res);
                    curr = 1;
                }
            }
          
        }
        return res = Math.max(curr, res);
    }
}
__________________________________________________________________________________________________
sample 34232 kb submission
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num: nums) {
            set.add(num);
        }
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            int temp = 0;
            int tempres = 0;
            if (!set.contains(nums[i] - 1)) {
                 temp = nums[i];
                 tempres = 1;
            
                while (set.contains(++temp)) {
                    tempres++;
                }
            }
            res = Math.max(res, tempres);
        }
        return res;
    }
}
__________________________________________________________________________________________________
