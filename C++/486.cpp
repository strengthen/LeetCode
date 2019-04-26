__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = nums[i];
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                dp[j][j + i] = max(nums[j] - dp[j + 1][j + i], nums[j + i] - dp[j][j + i - 1]);
            }
        }
        
        return dp[0][n - 1] >= 0;
    }
};
__________________________________________________________________________________________________
sample 8432 kb submission
class Solution {
public:
    // Runtime: O(N^2)
    // Space: O(N)
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = nums[i];
            for (int j = i + 1; j < n; ++j) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] >= 0;
    }
};
__________________________________________________________________________________________________
