class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> dp;
        int res = 2;
        for (int i = 0; i < A.size(); ++i)
            for (int j = i + 1; j < A.size(); ++j)  {
                int a = A[i], b = A[j];
                dp[b - a][j] = max(dp[b - a][j], dp[b - a][i] + 1);
                res = max(res, dp[b - a][j] + 1);
            }
        return res;
    }
};