__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int totalSum = 0;
        for (int num: nums) {
            totalSum += num;
        }
        if (totalSum % k != 0) {
            return false;
        }
        int targetSum = totalSum / k;
        boolean[] visited = new boolean[nums.length];
        return dfs(nums, 0, targetSum, 1, k, 0, visited);
    }
    
    private boolean dfs(int[] nums, int currentSum, int targetSum, int currentRound, int targetRound, int start, boolean[] visited) {
        // All match
        if (currentRound == targetRound && currentSum == targetSum) {
            return true;
        } 
        // Finish round one matching, can start another round from begining
        // It's a subset problem, so within one round of search it does not make sense to look back (i.e abcd, ba is same a ab)
        // But different round of search can look back (state has changed)
        else if (currentSum == targetSum) {
            return dfs(nums, 0, targetSum, currentRound + 1, targetRound, 0, visited);
        } else {
            for (int i = start; i < nums.length; i ++) {
                if (visited[i]) continue;
                if (currentSum + nums[i] <= targetSum) {
                    visited[i] = true;
                    if(dfs(nums, currentSum + nums[i], targetSum, currentRound, targetRound, i + 1, visited)) {
                        return true;
                    }
                    visited[i] = false;
                }
            }
            // Search failed
            return false;
        }
    }
}
__________________________________________________________________________________________________
sample 33508 kb submission
class Solution {
    public boolean recurse(int [] sets, int len , int start,int target,int [] nums){
        if(start>=len) return true;
        for(int i = 0 ; i < sets.length;i++){
            if(sets[i] + nums[start]<=target){
                sets[i]+=nums[start];
                if(recurse(sets,len,start+1,target,nums)) return true;
                sets[i]-=nums[start];
            }
            if(sets[i]==0) break;
        }
        return false;
    }
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = Arrays.stream(nums).sum();
        Arrays.sort(nums);
        if(sum%k!=0) return false;
        
        int len = nums.length;
        int left = sum/k;
        int index = len-1;
        while(index>=0 && nums[index] == left){
            len--;
            k--;
            index--;
        }
        int [] sets = new int[k];
        return recurse(sets,len,0,left,nums);
    }
}
__________________________________________________________________________________________________
