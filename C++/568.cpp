__________________________________________________________________________________________________
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size(), res = 0;
        vector<vector<int>> dp(n, vector<int>(k, 0));
        for (int j = k - 1; j >= 0; --j) {
            for (int i = 0; i < n; ++i) {
                dp[i][j] = days[i][j];
                for (int p = 0; p < n; ++p) {
                    if ((i == p || flights[i][p]) && j < k - 1) {
                        dp[i][j] = max(dp[i][j], dp[p][j + 1] + days[i][j]);
                    }
                    if (j == 0 && (i == 0 || flights[0][i])) res = max(res, dp[i][0]);
                }
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size();
        vector<int> dp(n, INT_MIN);
        dp[0] = 0;
        for (int j = 0; j < k; ++j) {
            vector<int> t(n, INT_MIN);
            for (int i = 0; i < n; ++i) {
                for (int p = 0; p < n; ++p) {
                    if (i == p || flights[p][i]) {
                        t[i] = max(t[i], dp[p] + days[i][j]);
                    }
                }
            }
            dp = t;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size();
        vector<vector<int>> memo(n, vector<int>(k, 0));
        return helper(flights, days, 0, 0, memo);
    }
    int helper(vector<vector<int>>& flights, vector<vector<int>>& days, int city, int day, vector<vector<int>>& memo) {
        int n = flights.size(), k = days[0].size(), res = 0;
        if (day == k) return 0;
        if (memo[city][day] > 0) return memo[city][day];
        for (int i = 0; i < n; ++i) {
            if (i == city || flights[city][i] == 1) {
                res = max(res, days[i][day] + helper(flights, days, i, day + 1, memo));
            }
        }
        return memo[city][day] = res;
    }
};