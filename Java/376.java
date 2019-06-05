__________________________________________________________________________________________________
sample 0 ms submission
public class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums.length < 2)
            return nums.length;
        int down = 1, up = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1])
                up = down + 1;
            else if (nums[i] < nums[i - 1])
                down = up + 1;
        }
        return Math.max(down, up);
    }
}
__________________________________________________________________________________________________
sample 32900 kb submission
class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (null == nums || 0 == nums.length) {
            return 0;
        }
        int max = 1;
        int[] up = new int[nums.length];
        int[] down = new int[nums.length];
        Arrays.fill(up, 1);
        Arrays.fill(down, 1);
        for (int i = 1; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    up[i] = Math.max(up[i - 1], down[j] + 1);
                } else if (nums[i] < nums[j]) {
                    down[i] = Math.max(down[i - 1], up[j] + 1);
                }
            }
            max = Math.max(max, up[i]);
            max = Math.max(max, down[i]);
        }
        return max;
    }
}
__________________________________________________________________________________________________
