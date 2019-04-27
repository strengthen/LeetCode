__________________________________________________________________________________________________
class Solution {
public:
   vector<int> cheapestJump(vector<int>& A, int B) {
       if (A.back() == -1) return {};
        int n = A.size();
        vector<int> res, dp(n, INT_MAX), pos(n, -1);
        dp[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (A[i] == -1) continue;
            for (int j = i + 1; j <= min(i + B, n - 1); ++j) {
                if (dp[j] == INT_MAX) continue;
                if (A[i] + dp[j] < dp[i]) {
                    dp[i] = A[i] + dp[j];
                    pos[i] = j;
                }
            }
        }
        if (dp[0] == INT_MAX) return res;
        for (int cur = 0; cur != -1; cur = pos[cur]) {
            res.push_back(cur + 1);
        }
        return res;
   }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        if (A.back() == -1) return {};
        int n = A.size();
        vector<int> res, dp(n, INT_MAX), pos(n, -1), len(n, 0);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == -1) continue;
            for (int j = max(0, i - B); j < i; ++j) {
                if (dp[j] == INT_MAX) continue;
                int t = A[i] + dp[j];
                if (t < dp[i] || (t == dp[i] && len[i] < len[j] + 1)) {
                    dp[i] = t;
                    pos[i] = j;
                    len[i] = len[j] + 1;
                }
            }
        }
        if (dp[n - 1] == INT_MAX) return res;
        for (int cur = n - 1; cur != -1; cur = pos[cur]) {
            res.insert(res.begin(), cur + 1);
        }
        return res;
    }
};
__________________________________________________________________________________________________
