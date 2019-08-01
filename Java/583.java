__________________________________________________________________________________________________
sample 2 ms submission
class Solution {

    public int minDistance(String word1, String word2) {
        char[] ws1 = word1.toCharArray();
        char[] ws2 = word2.toCharArray();
        int len1 = ws1.length;
        int len2 = ws2.length;
        if(len2 == 0) {
            return len1;
        }
        int[] maxLens = new int[len2];
        for(int i = 0; i < len1; i++) {
            char c1 = ws1[i];
            int prevLen = maxLens[0];
            if(ws2[0] == c1 && prevLen == 0) {
                maxLens[0] = 1;
            }
            for(int j = 1; j < len2; j++) {
                char c2 = ws2[j];
                int len = c1 == c2 ? prevLen + 1 : Math.max(maxLens[j - 1], maxLens[j]);
                prevLen = maxLens[j];
                maxLens[j] = len;
            }
        }
        return len1 + len2 - 2 * maxLens[len2 - 1];
    }
}
__________________________________________________________________________________________________
sample 37052 kb submission
class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        if (m == 0 || n == 0) return Math.max(m, n);
        
        int[] dp0 = new int[n + 1];
        int[] dp1 = new int[n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    // If one of the string is empty, the no. of deletions needed is the length of the other non-empty string
                    dp1[j] = i + j;
                } else if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    // We don't need to delete character
                    dp1[j] = dp0[j - 1];
                } else {
                    dp1[j] = Math.min(dp1[j - 1], dp0[j]) + 1;
                }
            }
            
            int[] tmp = dp0;
            dp0 = dp1;
            dp1 = tmp;
        }
        
        return dp0[n];
    }
}
__________________________________________________________________________________________________
