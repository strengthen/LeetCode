__________________________________________________________________________________________________
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        int res = 0, m = M.size(), n = M[0].size();
        for (int i = 0; i < m; ++i) { // Check horizontal
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) res = max(res, ++cnt);
                else cnt = 0;
            }
        }
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) { // Check vertical
                if (M[i][j] == 1) res = max(res, ++cnt);
                else cnt = 0;
            }
        }
        for (int i = 0; i < m + n - 1; ++i) {
            int cnt1 = 0, cnt2 = 0;
            for (int j = i; j >= 0; --j) {
                if (i - j < m && j < n) { // Check diagonal
                    if (M[i - j][j] == 1) res = max(res, ++cnt1);
                    else cnt1 = 0;
                }
                int t = m - 1 - i + j;
                if (t >= 0 && t < m && j < n ) { // Check anti-diagonal
                    if(M[t][j] == 1) res = max(res, ++cnt2);
                    else cnt2 = 0;
                }
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        int m = M.size(), n = M[0].size(), res = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4)));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 0) continue;
                for (int k = 0; k < 4; ++k) dp[i][j][k] = 1;
                if (j > 0) dp[i][j][0] += dp[i][j - 1][0]; // horizonal
                if (i > 0) dp[i][j][1] += dp[i - 1][j][1]; // vertical
                if (i > 0 && j < n - 1) dp[i][j][2] += dp[i - 1][j + 1][2]; // diagonal
                if (i > 0 && j > 0) dp[i][j][3] += dp[i - 1][j - 1][3]; // anti-diagonal
                res = max(res, max(dp[i][j][0], dp[i][j][1]));
                res = max(res, max(dp[i][j][2], dp[i][j][3]));
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        int m = M.size(), n = M[0].size(), res = 0;
        vector<vector<int>> dirs{{1,0},{0,1},{-1,-1},{-1,1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 0) continue;
                for (int k = 0; k < 4; ++k) {
                    int cnt = 0, x = i, y = j;
                    while (x >= 0 && x < m && y >= 0 && y < n && M[x][y] == 1) {
                        x += dirs[k][0];
                        y += dirs[k][1];
                        ++cnt;
                    }
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
};