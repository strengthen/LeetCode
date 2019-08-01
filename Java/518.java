__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (int coin: coins)
            for (int i = coin; i <= amount; i++)
                dp[i] += dp[i - coin];
        
        return dp[amount];
    }
}
__________________________________________________________________________________________________
sample 35376 kb submission
class Solution {
    // looking for the # of combinations, so we could use backtracking. 
    // - a lot of duplicates, so we could cache. or we just bottom up, bc its a typical DP problem. 
    public int change(int amount, int[] coins) {
        if(coins == null || coins.length == 0) return amount==0?1:0;
        int[] memo = new int[amount+1];
        memo[0] = 1;
        for(int i=0; i<coins.length; i++){
            for(int a=1; a<=amount; a++){
                if(a >= coins[i]) memo[a] += memo[a-coins[i]];
            }
        }
        
        return memo[amount];
    }
}
__________________________________________________________________________________________________
