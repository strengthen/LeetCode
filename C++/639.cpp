__________________________________________________________________________________________________
sample 16 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numDecodings(string s) {
        const int mod = 1E9 + 7;
        int L = s.length(), DP[2] = {1, 0};
        if('1' <= s[0] && s[0] <= '9')
            DP[1] = 1;
        else if(s[0] == '*')
            DP[1] = 9; // 1 ~ 9
        for(int i = 1; i < L; i++)
        {
            int cur = 0;
            if('1' <= s[i] && s[i] <= '9')
                cur = (cur + DP[1]) % mod;
            else if(s[i] == '*')
                cur = (cur + (long long)DP[1] * 9) % mod;
            if(s[i - 1] == '1')
            {
                if(s[i] == '*')
                    cur = (cur + (long long)DP[0] * 9) % mod; // 1 ~ 9
                else
                    cur = (cur + DP[0]) % mod;
            }
            else if(s[i - 1] == '2')
            {
                if(s[i] == '*')
                    cur = (cur + (long long)DP[0] * 6) % mod; // 1 ~ 6
                else if('0' <= s[i] && s[i] <= '6')
                    cur = (cur + DP[0]) % mod;
            }
            else if(s[i - 1] == '*')
            {
                if(s[i] == '*')
                    cur = (cur + (long long)DP[0] * 15) % mod; // 11 ~ 19, 21 ~ 26
                else if('0' <= s[i] && s[i] <= '6')
                    cur = (cur + (long long)DP[0] * 2) % mod; // 1 ~ 2
                else
                    cur = (cur + DP[0]) % mod; // 1
            }
            DP[0] = DP[1];
            DP[1] = cur;
        }
        return DP[1];
    }
};
__________________________________________________________________________________________________
sample 13800 kb submission
auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
public:
	int numDecodings(string s) {
		const int M = 1000000007;
		int n = s.size();
		if (n > 0) {
			vector<long> dp(2);
			dp[0] = 1;
			dp[1] = s[0] == '*' ? 9 : (s[0] >= '1' && s[0] <= '9');
			for (int i = 1; i < n; ++i) {
				long t;
				if (s[i - 1] == '*') {
					t = s[i] == '*' ? 9 * dp[1] + 15 * dp[0] : (s[i] >= '1' && s[i] <= '9') * dp[1] + (s[i] >= '0') * ((s[i] <= '9') + (s[i] <= '6')) * dp[0];
				}
				else {
					t = s[i] == '*' ? 9 * dp[1] + ((s[i - 1] == '1') * 9 + (s[i - 1] == '2') * 6) * dp[0] : (s[i] >= '1' && s[i] <= '9') * dp[1] + (s[i] >= '0') * (s[i - 1] == '1' && s[i] <= '9' || s[i - 1] == '2' && s[i] <= '6') * dp[0];
				}
				dp[0] = dp[1];
				dp[1] = t % M;
			}
			return dp[1];
		}
		return 0;
	}
};
__________________________________________________________________________________________________
