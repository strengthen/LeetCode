__________________________________________________________________________________________________
sample 60 ms submission
class Solution {
public:
    vector<vector<int>>prv;
    vector<vector<int>>nxt;
    vector<vector<int>> memo;
    vector<char> A;
    int MOD = 1000000007;
    
    int countPalindromicSubsequences(string S)
    {
        int N = S.length();
        prv.resize(N, vector<int>(4, -1));
        nxt.resize(N, vector<int>(4, -1));
        memo.resize(N, vector<int>(N));
        
        A.resize(N);
        int ix = 0;
        for (char c: S)
            A[ix++] = static_cast<char>(c - 'a');

        vector<int> last(4, -1);
        for (int i = 0; i < N; ++i)
        {
            last[A[i]] = i;
            for (int k = 0; k < 4; ++k)
                prv[i][k] = last[k];
        }

        last.assign(4, -1);
        for (int i = N-1; i >= 0; --i)
        {
            last[A[i]] = i;
            for (int k = 0; k < 4; ++k)
                nxt[i][k] = last[k];
        }

        return dp(0, N-1) - 1;
    }
    
    int dp(int i, int j)
    {
        if (memo[i][j] > 0) return memo[i][j];
        
        int ans = 1;
        if (i <= j)
        {
            for (int k = 0; k < 4; ++k)
            {
                int i0 = nxt[i][k];
                int j0 = prv[j][k];
                if (i <= i0 && i0 <= j) ans++;
                if (-1 < i0 && i0 < j0) ans += dp(i0 + 1, j0 - 1);
                if (ans >= MOD) ans -= MOD;
            }
        }
        memo[i][j] = ans;
        return ans;
    }
};
__________________________________________________________________________________________________
sample 10532 kb submission
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int md = 1000000007;
        int n = s.size();
        int dp[3][n][4];
        for (int len = 1; len <=n; ++len) {
            for (int i = 0; i + len <=n; ++i) for (int x = 0; x < 4; ++x)  {
                int &ans = dp[2][i][x];
                ans = 0;
                int j = i + len - 1;
                char c = 'a' + x;
                if (len == 1) ans = s[i] == c;
                else {
                    if (s[i] != c) ans = dp[1][i+1][x];
                    else if (s[j] != c) ans = dp[1][i][x];
                    else {
                        ans = 2;
                        if (len > 2) for (int y = 0; y < 4;++y) {
                            ans += dp[0][i+1][y];
                            ans %=md;
                        }
                    }
                }
            }
            for (int i=0;i<2;++i) for (int j = 0; j < n; ++j) for (int x=0; x < 4;++x)
                dp[i][j][x] = dp[i+1][j][x];
        }
        int ret = 0;
        for (int x = 0; x < 4;++x) ret = (ret + dp[2][0][x]) %md;
        return ret;
    }
};
__________________________________________________________________________________________________
