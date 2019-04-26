__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0]=1;
        for (int coin : coins) {
            for (int i=coin; i<=amount; i++) {
                dp[i]+=dp[i-coin];
            }
        }
        return dp.back();
    }
};
__________________________________________________________________________________________________
sample 8448 kb submission
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1] = {0};
        
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j < amount+1; j++) {
                if (j >= coins[i]) {
                    dp[j] += dp[j-coins[i]];
                }
            }
        }
        
        return dp[amount];
    }
};
__________________________________________________________________________________________________
