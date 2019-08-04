__________________________________________________________________________________________________
sample 4 ms submission

public final class Solution {
	public static int longestCommonSubsequence(String text1, String text2) {
		char[] cs1 = text1.toCharArray();
		int[] dp = new int[cs1.length+1];
		for(int i=text2.length()-1; i>=0; i--) {
			char c = text2.charAt(i);
			int dp0=0, dp1=0;
			for(int j=cs1.length-1;j>=0;j--) {
				int dpj = dp[j];
				if(cs1[j] != c) {
					dp1 = Math.max(dpj, dp1);
				} else {
					dp1 = Math.max(dp0+1, dp1);
				}
				if(dpj != dp1)
					dp[j] = dp1;
				dp0 = dpj;
			}
		}
		return dp[0];
	}
}
__________________________________________________________________________________________________
sample 6 ms submission
class Solution {
     public int longestCommonSubsequence(String text1, String text2) {
        char[] s1 = text1.toCharArray(), s2 = text2.toCharArray();
        int[][] memo = new int[s1.length + 1][s2.length + 1];

        for (int i = 0; i <= s1.length; i++ ) {
            for (int j = 0; j <= s2.length; j++) {
                if (i == 0 || j == 0) memo[i][j] = 0;
                else {
                    if (s1[i-1] == s2[j-1]) {
                        memo[i][j] = 1 + memo[i-1][j-1];
                    } else {
                        memo[i][j] = Math.max(
                                memo[i-1][j],
                                memo[i][j-1]
                        );
                    }
                }
            }
        }
         return memo[s1.length][s2.length];
    }
}
__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        
        int[][] dp = new int[m+1][n+1];
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        for(int i=1;i <= m;i++)
            for(int j=1;j <= n;j++) {
                if (text1.charAt(i-1) == text2.charAt(j-1))
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
            }
            
        return dp[m][n];
    }
}