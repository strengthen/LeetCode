__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public String optimalDivision(int[] nums) {
        if (nums.length == 1) {
            return nums[0] + "";
        }
        if (nums.length == 2) {
            return nums[0] + "/" + nums[1];
        }
        String ans = nums[0] + "/(" + nums[1];
        for (int i = 2; i < nums.length; i++) {
            ans += "/" + nums[i];
        }
        ans += ")";
        return ans;
    }
}
__________________________________________________________________________________________________
sample 35808 kb submission
class Solution {
    public String optimalDivision(int[] nums) {
        StringBuilder builder = new StringBuilder();
        builder.append(nums[0]);

        for (int i = 1; i < nums.length; i++) {
            if (i == 1 && nums.length > 2) {
                builder.append("/(").append(nums[i]);
            } else {
                builder.append("/").append(nums[i]);
            }
        }
        return nums.length > 2 ? builder.append(")").toString() : builder.toString();
    }
}
__________________________________________________________________________________________________
