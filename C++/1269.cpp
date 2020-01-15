__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int sz = min(steps / 2 + 1, arrLen);
        vector<vector<int>> v(steps + 1, vector<int>(sz + 2, 0));
        v[0][1] = 1;
        for (int k = 1; k <= steps; ++k) {
            for (int i = 1; i <= sz; ++i)
                v[k][i] = ((long)v[k - 1][i] + v[k - 1][i - 1] + v[k - 1][i + 1]) % 1000000007;
        }
        return v[steps][1];
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int numWays(int steps, int arrLen) {
        if (steps == 0) return 0;
        int mod = 1000000007;
        arrLen = min(arrLen, 1+steps/2); // to have time for the way back
        vector<vector<int>> dp(steps+1,vector<int>(arrLen,0));
        dp[0][0]=1;
        for(int s = 1; s <= steps; s++) {
            for(int pos = 0; pos< arrLen; pos++) {
                int res = dp[s-1][pos] + (pos>0?dp[s-1][pos-1]:0);
                res%=mod;
                res+= pos<arrLen-1?dp[s-1][pos+1]:0;
                dp[s][pos] = res%mod;
            }
        }
        return dp[steps][0];
    }
};
__________________________________________________________________________________________________
