__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
    public int profitableSchemes(int G, int P, int[] group, int[] profit) {
        int len = group.length;
        int mod = 1000000000 + 7;
        int[][] dp = new int[G + 1][P + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= len; i++) {
            int p = profit[i - 1];
            int g = group[i - 1];
            for (int j = G; j >= 0; j--) {
                for (int k = P; k >= 0; k--) {
                    if (j >= g) {
                        dp[j][k] = (dp[j][k] + dp[j - g][Math.max(0, k - p)]) % mod;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= G; i++) {
            res = (res + dp[i][P]) % mod;
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 36824 kb submission
class Solution {
    public int profitableSchemes(int G, int P, int[] group, int[] profit) {
        int[][] dp = new int[P+1][G+1];
        dp[0][0] = 1;
        int mod = 1000000007;
        
        for(int k=0;k<group.length;k++){
            int pr = profit[k], gr = group[k];
            for(int i=P;i>=0;i--){
                for(int j=G-gr;j>=0;j--){
                    dp[Math.min(P, i+pr)][j+gr] = (dp[Math.min(P, i+pr)][j+gr] + dp[i][j])% mod;
                }
            }
        }
        
        int res = 0;
        for(int j=0;j<=G;j++){
            res = (res + dp[P][j]) % mod;
        }
        
        return res;
    }
}
__________________________________________________________________________________________________
