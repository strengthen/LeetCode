__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    public int numDecodings(String ss) {
        char[] s = ss.toCharArray();
        int last = s.length-1;
        
        long z0 = 1, z1 = 1, z2;
        char d = 127, dd;
        
        for (int i = last; i >= 0; i--) {
            dd = d;
            d = s[i];
            
            z2 = z1; z1 = z0; z0 = 0;
            
            if (d == '*') {
                z0 += z1*9;
                if (dd == '*') z0 += z2*15;
                else {
                    if (dd <= '6' && dd >= '0') z0 += 2*z2;
                    else if (dd <= '9' && dd >= '0') z0 += z2;
                }
            } else {
                if (d != '0') z0 += z1;

                if (dd == '*') {
                    if (d == '1') z0 += z2*9;
                    else if (d == '2') z0 += z2*6;
                } else if ((d == '1' && dd >= '0' && dd <= '9') || (d == '2' && dd >= '0' && dd <= '6')) z0 += z2;
            }
           
            if ((z0 & 0x0FFF0000000000000L) > 0) z0 %= 1000000007;
        }
        
        return (int) (z0 % 1000000007);
    }
}
__________________________________________________________________________________________________
sample 38924 kb submission
class Solution {
    private static final int MOD = 1000000007;
    
    public int numDecodings(String s) {
        int n = s.length();
        long[] dp = new long[n + 1];
        dp[0] = 1;
        switch (s.charAt(0)) {
            case '0': 
                dp[1] = 0;
                break;
            case '*':
                dp[1] = 9;
                break;
            default:
                dp[1] = 1;
                break;
        }
        for (int i = 2; i <= n; i++) {
            if (s.charAt(i - 1) == '*') {
                dp[i] = (dp[i] + 9 * dp[i - 1]) % MOD;
                if (s.charAt(i - 2) == '1') {
                    dp[i] = (dp[i] + dp[i - 2] * 9) % MOD;
                } else if (s.charAt(i - 2) == '2') {
                    dp[i] = (dp[i] + dp[i - 2] * 6) % MOD;
                } else if (s.charAt(i - 2) == '*') {
                    dp[i] = (dp[i] + dp[i - 2] * 15) % MOD;
                }
            } else {
                dp[i] = (dp[i] + s.charAt(i - 1) == '0' ? 0 : dp[i - 1]) % MOD;
                if (s.charAt(i - 2) == '1') {
                    dp[i] = (dp[i] + dp[i - 2]) % MOD;
                } else if (s.charAt(i - 2) == '2' && s.charAt(i - 1) <= '6') {
                    dp[i] = (dp[i] + dp[i - 2]) % MOD;
                } else if (s.charAt(i - 2) == '*') {
                    dp[i] = (dp[i] + dp[i - 2] * (s.charAt(i - 1) > '6' ? 1 : 2)) % MOD;
                }
            }
            
        }
        return (int)dp[n];
    }
}
__________________________________________________________________________________________________
