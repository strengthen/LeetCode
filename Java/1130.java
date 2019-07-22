__________________________________________________________________________________________________
class Solution {
    public int mctFromLeafValues(int[] arr) {
        int n =arr.length;
        long[][] dp = new long[n][n];
        for(int len = 1;len <= n;len++){
            for(int i = 0;i+len-1 < n;i++){
                int j = i+len-1;
                if(len == 1){
                    dp[i][i] = 0;
                }else{
                    dp[i][j] = Long.MAX_VALUE;
                    for(int k = i+1;k <= j;k++){
                        int maxl = 0;
                        for(int l = i;l < k;l++){
                            maxl = Math.max(maxl, arr[l]);
                        }
                        int maxr = 0;
                        for(int l = k;l <= j;l++){
                            maxr = Math.max(maxr, arr[l]);
                        }
                        dp[i][j] = Math.min(dp[i][j], dp[i][k-1] + dp[k][j] + maxl*maxr);
                    }
                }
            }
        }
        return (int)dp[0][n-1];
    }
}	

__________________________________________________________________________________________________

__________________________________________________________________________________________________
