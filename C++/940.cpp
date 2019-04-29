__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int distinctSubseqII(string S) {
        int MOD = (int)pow(10, 9) + 7;
        int N = S.size();
        vector<int> dp(N + 1, 0);
        dp[0] = 1;

        vector<int> last(26, -1);

        for (int i = 0; i < N; ++i) {
            int x = S[i] - 'a';
            dp[i+1] = dp[i] * 2 % MOD;
            if (last[x] >= 0) {
                dp[i+1] -= dp[last[x]];
            }
            dp[i+1] %= MOD;
            last[x] = i;
        }

        dp[N]--;
        if (dp[N] < 0) dp[N] += MOD;
        return dp[N];
    }
};
__________________________________________________________________________________________________
sample 9112 kb submission
class Solution {
public:
    int distinctSubseqII(string S) {
        vector<int> dp(26,0);
        int mod  = (int)1e9+7;
        for(auto& c:S){
            dp[c-'a'] = accumulate(dp.begin(),dp.end(),1L)%mod;
        }
        return accumulate(dp.begin(),dp.end(),0L)%mod;
    }
};
__________________________________________________________________________________________________
