__________________________________________________________________________________________________
4ms
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long long int> dp(t.size());
        for (int i = 0; i < s.size(); ++i) {
            for (int j = t.size() - 1; j >= 1; --j) {
                if (s[i] == t[j]) dp[j] += dp[j - 1];
            }
            dp[0] += (s[i] == t[0]);
        }
        return dp.back();
    }
};
__________________________________________________________________________________________________
8420 kb
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        long dp[n+1] = {0}; dp[0] = 1;
        for (int j = 1; j <= m; j++)
            for (int i = n; i > 0; i--)
                dp[i] += s[j-1] == t[i-1] ? dp[i-1] : 0;
        return dp[n];
    }
};
__________________________________________________________________________________________________
