__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int numDistinct(String s, String t) {
        char[] ss = s.toCharArray(), ts = t.toCharArray();
        int slen = ss.length, tlen = ts.length;
        
        int[] startIdx = new int[128]; // mapint to the character start postions 
        int[] prevIdx = new int[tlen]; // track star the i postion, what is the previous position for current character 
        Arrays.fill(startIdx, -1);
        for (int i = 0; i < tlen; i++) {
            prevIdx[i] = startIdx[ts[i]];
            startIdx[ts[i]] = i + 1;
        }
        
        int[] dp = new int[tlen + 1];
        dp[0] = 1;
        for (int i = 0; i < slen; i++) {
            for (int j = startIdx[ss[i]]; j != -1; j = prevIdx[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[tlen];
    }
}
__________________________________________________________________________________________________
sample 33036 kb submission
class Solution {
    public int numDistinct(String S, String T) {
        // reduce to 1D by processing one char of T at a time
        int[] dp = new int[S.length() + 1];
        // there is one way to for subsequence for an empty T
        Arrays.fill(dp, 1);
        
        for (int j = 1; j <= T.length(); ++j) {
            dp[0] = 0; // 0 way for an empty S to match with non-empty T[:(j+1)]
            int prev = (j==1) ? 1: 0;
            
            for (int i = 1; i <= S.length(); ++i) {
                int tmp = dp[i];
                if (S.charAt(i-1) != T.charAt(j-1)) {
                    dp[i] = dp[i-1]; // this means we need to find the match with shorter S by ignoring S[i-1]
                } else {
                    dp[i] = prev + dp[i-1]; // now we have two ways, considering S[i-1] plus the matches with shorter S by ignoring S[i-1]
                }
                prev = tmp;
            }
        }
        
        return dp[S.length()];
    }
}
__________________________________________________________________________________________________
