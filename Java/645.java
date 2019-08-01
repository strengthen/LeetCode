__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    
    public static int[] findErrorNums(int[] a) {
        int n = a.length;
        boolean[] flag = new boolean[n+1];
        int[] res = new int[2];
        
        for (int num : a) {
            if (flag[num]) {
                res[0] = num;
            }
            flag[num] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            if (!flag[i]) {
                res[1] = i;
                break;
            }
        }        
        return res;
    }    
}
__________________________________________________________________________________________________
sample 37772 kb submission
class Solution {
    public int[] findErrorNums(int[] nums) {
        Arrays.sort(nums);
        int repeat = 0, lose , len = nums.length;
        for (int i = 1; i < len; i++) 
            if (nums[i] - nums[i - 1] == 0) repeat = nums[i];
        lose = len * (len + 1) / 2 - (Arrays.stream(nums).sum() - repeat);
        return new int[]{repeat, lose};
    }
}
__________________________________________________________________________________________________
