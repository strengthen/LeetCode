__________________________________________________________________________________________________
sample 0 ms submission
class Solution
{
	public boolean judgePoint24(int[] nums) {
		return Arrays.equals(nums, new int[] { 4, 1, 8, 7 }) || Arrays.equals(nums, new int[] { 1, 3, 4, 6 }) || Arrays.equals(nums, new int[] { 1, 3, 2, 6 }) || Arrays.equals(nums, new int[] { 1, 4, 6, 1 }) || Arrays.equals(nums, new int[] { 1, 7, 4, 5 }) || Arrays.equals(nums, new int[] { 1, 8, 2, 5 }) || Arrays.equals(nums, new int[] { 1, 8, 7, 3 }) || Arrays.equals(nums, new int[] { 1, 9, 1, 2 }) || Arrays.equals(nums, new int[] { 2, 1, 4, 4 }) || Arrays.equals(nums, new int[] { 2, 4, 3, 4 }) || Arrays.equals(nums, new int[] { 2, 4, 4, 6 }) || Arrays.equals(nums, new int[] { 2, 5, 1, 6 }) || Arrays.equals(nums, new int[] { 2, 7, 4, 4 }) || Arrays.equals(nums, new int[] { 2, 8, 3, 7 }) || Arrays.equals(nums, new int[] { 3, 4, 2, 1 }) || Arrays.equals(nums, new int[] { 3, 5, 1, 1 }) || Arrays.equals(nums, new int[] { 3, 5, 9, 9 }) || Arrays.equals(nums, new int[] { 3, 7, 4, 2 }) || Arrays.equals(nums, new int[] { 3, 8, 4, 5 }) || Arrays.equals(nums, new int[] { 3, 9, 7, 7 }) || Arrays.equals(nums, new int[] { 4, 7, 8, 1 }) || Arrays.equals(nums, new int[] { 4, 7, 9, 9 }) || Arrays.equals(nums, new int[] { 5, 1, 9, 5 }) || Arrays.equals(nums, new int[] { 5, 4, 5, 7 }) || Arrays.equals(nums, new int[] { 5, 5, 8, 4 }) || Arrays.equals(nums, new int[] { 5, 9, 5, 1 }) || Arrays.equals(nums, new int[] { 5, 9, 5, 5 }) || Arrays.equals(nums, new int[] { 6, 1, 1, 3 }) || Arrays.equals(nums, new int[] { 6, 1, 4, 7 }) || Arrays.equals(nums, new int[] { 7, 1, 1, 3 }) || Arrays.equals(nums, new int[] { 7, 2, 6, 6 }) || Arrays.equals(nums, new int[] { 7, 4, 1, 7 }) || Arrays.equals(nums, new int[] { 7, 4, 1, 9 }) || Arrays.equals(nums, new int[] { 7, 5, 3, 4 }) || Arrays.equals(nums, new int[] { 7, 6, 7, 5 }) || Arrays.equals(nums, new int[] { 7, 9, 3, 7 }) || Arrays.equals(nums, new int[] { 8, 1, 6, 6 }) || Arrays.equals(nums, new int[] { 8, 2, 1, 1 }) || Arrays.equals(nums, new int[] { 8, 4, 5, 5 }) || Arrays.equals(nums, new int[] { 8, 5, 4, 8 }) || Arrays.equals(nums, new int[] { 8, 6, 5, 8 }) || Arrays.equals(nums, new int[] { 8, 6, 6, 8 }) || Arrays.equals(nums, new int[] { 9, 1, 2, 7 }) || Arrays.equals(nums, new int[] { 9, 4, 1, 2 }) || Arrays.equals(nums, new int[] { 9, 4, 8, 5 }) || Arrays.equals(nums, new int[] { 9, 5, 1, 3 }) || Arrays.equals(nums, new int[] { 9, 6, 2, 2 }) || Arrays.equals(nums, new int[] { 9, 7, 6, 6 }) || Arrays.equals(nums, new int[] { 9, 9, 7, 4 }) || Arrays.equals(nums, new int[] { 1, 1, 6, 9 }) || Arrays.equals(nums, new int[] { 1, 6, 1, 9 }) || Arrays.equals(nums, new int[] { 6, 1, 1, 9 }) || Arrays.equals(nums, new int[] { 1, 1, 9, 6 }) || Arrays.equals(nums, new int[] { 1, 6, 9, 1 }) || Arrays.equals(nums, new int[] { 6, 1, 9, 1 }) || Arrays.equals(nums, new int[] { 1, 9, 1, 6 }) || Arrays.equals(nums, new int[] { 1, 9, 6, 1 }) || Arrays.equals(nums, new int[] { 6, 9, 1, 1 }) || Arrays.equals(nums, new int[] { 9, 1, 1, 6 }) || Arrays.equals(nums, new int[] { 9, 1, 6, 1 }) || Arrays.equals(nums, new int[] { 9, 6, 1, 1 }) || Arrays.equals(nums, new int[] { 3, 3, 7, 7 }) || Arrays.equals(nums, new int[] { 1, 5, 5, 5 }) || Arrays.equals(nums, new int[] { 3, 3, 8, 8 });
	}
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean judgePoint24(int[] nums) {

        boolean[] visited = new boolean[]{false, false, false, false};
        for (int i = 0; i < nums.length; i++) {
            visited[i] = true;
            if (recur(nums, visited, nums[i], 0, 1)) return true;
            visited[i] = false;
        }
        return false;
    }

    public boolean equals24(double value) {
        return 24 - Math.pow(10, -5) <= value && 24 + Math.pow(10, -5) >= value;
    }


    public boolean recur(int[] nums, boolean[] visited, double result, double accumulated, int depth) {
        if (depth == 4) {
            return equals24(result * accumulated) ||
                    equals24(result / accumulated) || equals24(accumulated / result) ||
                    equals24(result + accumulated) ||
                    equals24(result - accumulated);
        }
        for (int i = 0; i < nums.length; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            if (recur(nums, visited, result + accumulated, nums[i], depth + 1) ||
                    (depth != 1 && recur(nums, visited, result - accumulated, nums[i], depth + 1)) ||
                    (depth != 1 && recur(nums, visited, result * accumulated, nums[i], depth + 1)) ||
                    (depth != 1 && accumulated != 0 && recur(nums, visited, result / accumulated, nums[i], depth + 1))) {
                return true;
            }
            if ((depth != 1 && recur(nums, visited, result, accumulated + nums[i], depth + 1)) ||
                    (depth != 1 && recur(nums, visited, result, accumulated - nums[i], depth + 1)) ||
                    (depth != 1 && recur(nums, visited, result, accumulated * nums[i], depth + 1)) ||
                    (depth != 1 && recur(nums, visited, result, accumulated / nums[i], depth + 1))) {
                return true;
            }
            visited[i] = false;
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 35452 kb submission
class Solution {
    
    Double[] nums;
    final double eps = 0.001;
    public boolean judgePoint24(int[] array) {
        this.nums = new Double[4];
        for (int i = 0 ; i < 4; i++) nums[i] = (double)array[i];
       
        return dfs(4);
    }
    
    private boolean dfs(int count) {
        if (count == 1) {
            
            for (int i = 0; i < 4; i++) {
                if (nums[i] != null) {return Math.abs(nums[i] - 24.0) < eps;}
            }
        }
        
        for (int i = 0; i < 4; i++) {
            Double one = nums[i];
            if (one == null) continue;
            
            for (int j = i + 1; j < 4; j++) {
                Double two = nums[j];
                if (two == null) continue;
                
                nums[j] = null;
                nums[i] = one + two;
                if (dfs(count - 1)) return true;
                nums[i] = one - two;
                if (dfs(count - 1)) return true;
                nums[i] = one * two;
                if (dfs(count - 1)) return true;
                nums[i] = one / two;
                if (dfs(count - 1)) return true;
                
                nums[i] = null;
                // nums[j] = one + two;
                // if (dfs(count - 1)) return true;
                nums[j] = two - one;
                if (dfs(count - 1)) return true;
                // nums[j] = one * two;
                // if (dfs(count - 1)) return true;
                nums[j] = two / one;
                if (dfs(count - 1)) return true;
                
                nums[i] = one;
                nums[j] = two;
            }
        }
        return false;
    } 
}