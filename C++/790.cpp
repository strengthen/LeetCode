__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int numTilings(int N) {
        if (N==0)
            return 0;
        else if (N==1)
            return 1;
        else if (N==2)
            return 2;
        else if (N==3)
            return 5;
        
        int a = 1, b= 2, c= 5, c2;
        int mod = 1e9+7;
        for (int i = 4; i <= N; i++) {
            c2 = (c * 2 % mod + a) % mod;
            a=b;
            b=c;
            c=c2;
        }
        return c2;
        
    }
};
__________________________________________________________________________________________________
sample 8292 kb submission
class Solution {
public:
    int numTilings(int N) {
        // f(N) = f(N - 1) * 2 + f(N - 3)
        if (N == 1) return 1;
        else if (N == 2) return 2;
        else if (N == 3) return 5;
        else {
            long long dp[N + 1] = {0};
            dp[0] = dp[1] = 1;
            dp[2] = 2, dp[3] = 5;
            int mod = 1e9 + 7;
            for(int i = 4; i <= N; ++i) {
                dp[i] = (2 * dp[i - 1] + dp[i - 3]) % mod;
            }
            return dp[N];
        }
    }
};
__________________________________________________________________________________________________
