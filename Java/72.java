__________________________________________________________________________________________________
× Close
sample 2 ms submission
class Solution {
    public int minDistance(String word1, String word2) {
        int[][] dp = new int[word1.length() + 1][word2.length() + 1];
        return minHelper(word1, word2, dp, word1.length(), word2.length());
    }
    
    private int minHelper(String word1, String word2, int[][]dp, int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];
        if (i == 0) return dp[0][j] = j;
        if (j == 0) return dp[i][0] = i;
        if (word1.charAt(i - 1) == word2.charAt(j - 1)) return dp[i][j] = minHelper(word1, word2, dp, i - 1, j - 1);
        return dp[i][j] = Math.min(minHelper(word1, word2, dp, i - 1, j), 
                                   Math.min(minHelper(word1, word2, dp, i - 1, j - 1), 
                                           minHelper(word1, word2, dp, i, j - 1))) + 1;
    }    
}
__________________________________________________________________________________________________
sample 34504 kb submission
class Solution {
    public int minDistance(String word1, String word2) {
        //dp[i][j]表示从word1[0...i-1]到word2[0...j-1]所需要的步数
        int m = word1.length();
        int n = word2.length();
        int[][] dp = new int[m+1][n+1];
        for(int i=1; i<=m; i++) {
            dp[i][0] = i;
        }
        for(int j=1; j<=n; j++) {
            dp[0][j] = j;
        }
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(word1.charAt(i-1) == word2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1];
                }else {
                    dp[i][j] = Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[m][n];
    }
}
__________________________________________________________________________________________________
