__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
    private static final int mod = 1000000007;
    
    public int countPalindromicSubsequences(String S) {
        
        char[] chars = S.toCharArray();
        int n = chars.length;
        int[] counts = new int[n];
        
        for(int i = 0; i < n; i++) {
            int char1 = chars[i] - 'a';
            counts[i] = 1;
            long sum = 0;
            int[] tmp = new int[26];
            
            for(int j = i - 1; j >= 0; j--) {
                int char2 = chars[j] - 'a';
                int count = counts[j];
                
                if (char1 == char2) {
                    counts[j] = (int)((sum + 2) % mod);
                }
                
                sum += count - tmp[char2];
                tmp[char2] = count;
            }
        }
        
        int[] nums = new int[26];
        
        for(int i = n - 1; i >= 0; i--) {
            nums[chars[i] - 'a'] = counts[i];
        }
        
        long sum = 0;
        
        for(int cnt : nums) {
            sum += cnt;
        }
        
        return (int)(sum % mod);
    }
}
__________________________________________________________________________________________________
sample 37888 kb submission
class Solution {
    public int countPalindromicSubsequences(String S) {
        /*
        dp[len][i][x] = number of different palindromic subsequences of s[i..i+len-1] ending at character x
        = dp[len-1][i+1][x] if s[i] != x
        = dp[len-1][i][x] if s[i+len-1] != x
        = SUM(dp[len-2][i+1][y]) for all y otherwise
        
        dp[3][n][4]
        */
        if (S == null || S.length() <= 0) {
            return 0;
        }
        
        int n = S.length(), factor = 1000000007;
        int[][][] dp = new int[3][n][4];
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                for (int c = 0; c < 4; c++) {
                    dp[2][i][c] = 0;
                    if (len == 1) {
                        dp[2][i][c] = (S.charAt(i) == (char)('a' + c)) ? 1:0;
                    }
                    else {
                        if (S.charAt(i) != (char)('a' + c)) {
                            dp[2][i][c] = dp[1][i+1][c];
                        }
                        else if (S.charAt(i+len-1) != (char)('a' + c)) {
                            dp[2][i][c] = dp[1][i][c];
                        }
                        else {
                            dp[2][i][c] = 2;
                            if (len > 2) {
                                for (int y = 0; y < 4; y++) {
                                    dp[2][i][c] += dp[0][i+1][y];
                                    dp[2][i][c] %= factor;
                                }
                            }
                        }
                    }
                }
            }
            
            for (int l = 0; l < 2; l++) {
                for (int ii = 0; ii < n; ii++) {
                    for (int cc = 0; cc < 4; cc++) {
                        dp[l][ii][cc] = dp[l+1][ii][cc];
                    }
                }
            }
        }
        
        int res = 0;
        for (int cc = 0; cc < 4; cc++) {
            res = (res + dp[2][0][cc]) % factor;
        }
        
        return res;
    }
}
__________________________________________________________________________________________________
