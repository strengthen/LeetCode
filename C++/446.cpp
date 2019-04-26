__________________________________________________________________________________________________
sample 56 ms submission
class Solution {

public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int n(A.size()), cnt(0);

        int dp[n][n] = {};
        
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; ++i) pos[A[i]].push_back(i);
        
        for (int i = 2; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                long num = 2l*A[j]-A[i];
                if (num < INT_MIN || num > INT_MAX || !pos.count(num)) continue;
                
                for (int& k : pos[num]) if (k < j) dp[i][j] += dp[j][k]+1;
                cnt += dp[i][j];
            }
        }
       
        return cnt;
    }
};
__________________________________________________________________________________________________
sample 13580 kb submission
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3) return 0;
        vector<unordered_map<int, int>> dp(n);
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = (long)nums[i] - (long)nums[j];
                if (diff > INT_MAX || diff < INT_MIN) continue;
                bool useful = s.count(nums[i] + diff);
                if (useful) ++dp[i][diff];
                if (!dp[j].count(diff)) continue;
                if (useful) dp[i][diff] += dp[j][diff];
                res += dp[j][diff];
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
