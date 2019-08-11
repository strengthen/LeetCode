__________________________________________________________________________________________________
class Solution {
    public int numRollsToTarget(int d, int f, int target) {
        int mod = 1000000007;
        long[] dp = new long[target+1];
        dp[0] = 1;
        for(int i = 0;i < d;i++){
            long[] ndp = new long[target+1];
            for(int j = 0;j < target+1;j++){
                if(j+1 < ndp.length)ndp[j+1] += dp[j];
                if(j+f+1 < ndp.length)ndp[j+f+1] += mod - dp[j];
            }
            for(int j = 1;j < target+1;j++){
                ndp[j] += ndp[j-1];
                ndp[j] %= mod;
            }
            dp = ndp;
        }
        return (int)dp[target];
    }
}	
__________________________________________________________________________________________________

__________________________________________________________________________________________________
