__________________________________________________________________________________________________
class Solution {
    public String shortestCommonSupersequence(String s1, String s2) {

       // find LCS.
       int m = s1.length(), n = s2.length();
       int[][] dp = new int[m + 1][n + 1];
       for (int i = 0; i < m; ++i) {
           for (int j = 0; j < n; ++j) {
               if (s1.charAt(i) == s2.charAt(j)) {
                   dp[i + 1][j + 1] = 1 + dp[i][j];    
               }else {
                   dp[i + 1][j + 1] = Math.max(dp[i + 1][j], dp[i][j + 1]);
               }
           }
       }
       
       // Build result.
       StringBuilder sb = new StringBuilder();
       int i = m - 1, j = n - 1;
       while (i >= 0 || j >= 0) { 
           if (i < 0 ^ j < 0) { // only one string reaches left end.
               char c = i < 0 ? s2.charAt(j--) : s1.charAt(i--); // remaining chars in the other string.
               sb.append(c);
           }else if (s1.charAt(i) == s2.charAt(j)) { // common char in LCS.
               sb.append(s1.charAt(i)); // append the char of either s1 or s2.
               --i; --j;  
           }else { // the char is not in LCS.
               char c = dp[i][j + 1] > dp[i + 1][j] ? s1.charAt(i--) : s2.charAt(j--); // the char corresponding to larger dp value.
               sb.append(c);
           }
       } 
       return sb.reverse().toString();
   }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
