__________________________________________________________________________________________________
sample 96 ms submission

class Solution:
    def change(self, amount, coins):

        dp = [1] + [0] * (amount);    
        for coin in coins:
            for i in range(amount - coin + 1):
                if dp[i]:
                    dp[i + coin] += dp[i]
        
        return dp[amount]
__________________________________________________________________________________________________
sample 13080 kb submission
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        if amount == 0:
            return 1
        
        # dp[i] means the #ways to compose {i} amount
        dp = [0] * (amount + 1)
        dp[0] = 1
        
        for j in coins:
            for i in range(amount + 1):
                if i >= j:
                    dp[i] += dp[i - j]

        return dp[amount]
__________________________________________________________________________________________________
