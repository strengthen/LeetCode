__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(A.size(), 0);
        int M = 0;
        for(int i = 0; i < K; i++){
            M = A[i] > M?A[i]:M;
            dp[i] = M * (i+1);
        }
        for(int i = K; i < A.size(); i++){
            M = A[i];
            int maxSum = 0;
            for(int l = 1; l <= K; l++){
                M = A[i-l+1] > M?A[i-l+1]:M;
                maxSum = maxSum>(M*l+dp[i-l])?maxSum:M*l+dp[i-l];
            }
            dp[i] = maxSum;
        }
        return dp[A.size()-1];
    }
};
__________________________________________________________________________________________________
× Close
sample 8 ms submission
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int maxA = 0;
        vector<int> dp(A.size(), 0);
        for (int i = 0; i < K; ++i) {
            maxA = max(maxA, A[i]);
            dp[i] = maxA * (i + 1);
        }
        for (int i = K; i < A.size(); ++i) {
            int maxA = 0;
            int res_ = 0;
            for (int j = i; j > i - K; --j) {
                maxA = max(maxA, A[j]);
                res_ = max(res_, dp[j - 1] + maxA * (i - j + 1));
            }
            dp[i] = res_;
        }

        return dp.back();
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n+1, INT_MIN);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int maxSoFar = INT_MIN;
            for (int j = 1; j <= K && (i - j >= 0); ++j) {
                maxSoFar = max(maxSoFar, A[i-j]);
                dp[i] = max(dp[i], dp[i-j] + maxSoFar *j);
            }
        }
        return dp[n];
    }
};