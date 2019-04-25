__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
private:
    int dfs(vector<int>& dp, int target, vector<int>& nums) {
        if (target == 0)
            return 1;
        if (dp[target] != -1)
            return dp[target];
        int sum = 0;
        for (auto num : nums) {
            if (target >= num) {
                sum += dfs(dp, target - num, nums);
            }
        }
        return dp[target] = sum;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return dfs(dp, target, nums);
    }
};
__________________________________________________________________________________________________
sample 8372 kb submission
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned long long dp[target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i <= target; i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(nums[j] <= i)
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};
__________________________________________________________________________________________________
