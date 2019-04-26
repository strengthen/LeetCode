__________________________________________________________________________________________________
class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n, ""));
        for (int step = 1; step <= n; ++step) {
            for (int i = 0; i + step - 1 < n; ++i) {
                int j = i + step - 1;
                dp[i][j] = s.substr(i, step);
                for (int k = i; k < j; ++k) {
                    string left = dp[i][k], right = dp[k + 1][j];
                    if (left.size() + right.size() < dp[i][j].size()) {
                        dp[i][j] = left + right;
                    }
                }
                string t = s.substr(i, j - i + 1), replace = "";
                auto pos = (t + t).find(t, 1);
                if (pos >= t.size()) replace = t;
                else replace = to_string(t.size() / pos) + '[' + dp[i][i + pos - 1] + ']';
                if (replace.size() < dp[i][j].size()) dp[i][j] = replace;
            }
        }
        return dp[0][n - 1];
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n, ""));
        for (int step = 1; step <= n; ++step) {
            for (int i = 0; i + step - 1 < n; ++i) {
                int j = i + step - 1;
                dp[i][j] = s.substr(i, step);
                string t = s.substr(i, j - i + 1), replace = "";
                auto pos = (t + t).find(t, 1);
                if (pos < t.size()) {
                    replace = to_string(t.size() / pos) + "[" + dp[i][i + pos - 1] + "]";
                    if (replace.size() < dp[i][j].size()) dp[i][j] = replace;
                    continue;
                }
                for (int k = i; k < j; ++k) {
                    string left = dp[i][k], right = dp[k + 1][j];
                    if (left.size() + right.size() < dp[i][j].size()) {
                        dp[i][j] = left + right;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
__________________________________________________________________________________________________
