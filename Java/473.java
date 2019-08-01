__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean makesquare(int[] nums) {
        if (nums.length == 0) {
            return false;
        }
        int sum = 0;
        int max = Integer.MIN_VALUE;
        for (int i : nums) {
            sum += i;
            max = Math.max(max, i);
        }
        
        if (sum % 4 != 0 || max > sum / 4) {
            return false;
        }
        
        int edge = sum / 4;
        boolean[] visited = new boolean[nums.length];
        Arrays.sort(nums);
        visited[nums.length - 1] = true;
        return dfs(nums, edge, visited, nums[nums.length-1], 0, nums.length-1);
    }
    
    private boolean dfs(int[] nums, int edge, boolean[] visited, int currentSum, int found, int left) {
        
        if (currentSum == edge) {
            currentSum = 0;
            found++;
        }
        
        if (left == 0 || found == 4) {
            if (left == 0 && found == 4 && currentSum == 0) {
                return true;
            } else {
                return false;
            }
        }
        
        for (int i = nums.length - 1; i >= 0; i--) {
            if (visited[i]) {
                continue;
            }
            if(currentSum + nums[i] > edge) {
                continue;
            } else {
                int currentSum_new = currentSum;
                int found_new = found;
                int left_new = left - 1;
                if(currentSum + nums[i] == edge) {
                    currentSum_new = 0;
                    found_new++;
                } else {
                    currentSum_new += nums[i];
                }
                visited[i] = true;
                
                if (dfs(nums, edge, visited, currentSum_new, found_new, left_new)) {
                    return true;
                }
                
                visited[i] = false;
            }
        }
        
        return false;
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    boolean helper(int[] nums, int group, boolean[] visited, int target, int curSum, int start) {
        if (group == 3) return true;
        if (curSum > target) return false;
        if (curSum == target) return helper(nums, group+1, visited, target, 0, 0);
        
        for (int i = start; i < nums.length; i++) {
            if (visited[i] == true) continue;
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            visited[i] = true;
            if (helper(nums, group, visited, target, curSum+nums[i], i+1)) return true;
            visited[i] = false;
        }
        
        return false;
    }
    
    public boolean makesquare(int[] nums) {
        if (nums == null || nums.length < 4) return false;
        int sum = 0;
        for (int num: nums) sum += num;
        if (sum % 4 != 0) return false;
        
        return helper(nums, 0, new boolean[nums.length], sum / 4, 0, 0);
    }
}
__________________________________________________________________________________________________
sample 33512 kb submission
class Solution {
    public boolean makesquare(int[] nums) {
        if (nums == null || nums.length == 0) return false;
        int sum = Arrays.stream(nums).sum();
        if (sum % 4 != 0) return false;
        int length = sum / 4;
        boolean[] visited = new boolean[nums.length];
        return dfs(nums, length, visited, 0, 0, 0);  
    }
    
    private boolean dfs(int[] nums, int length, boolean[] visited,
                        int cur, int start, int count) {
        if (count == 4) {
            for (int i = 0; i < nums.length; i++) {
                if (!visited[i]) return false;
            }
            return true;
        } else if (cur > length) {
            return false;
        } else if (cur == length) {
            return dfs(nums, length, visited, 0, 0, count+1);
        } else {
            for (int i = start; i < nums.length; i++) {
                if (visited[i]) continue;
                visited[i] = true;
                if (dfs(nums, length, visited, cur+nums[i], i+1, count)) return true;
                visited[i] = false;
            }
            return false;
        }
    }
}