__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        def dfs(count, curr, i):
            nonlocal res
            if count - (curr - amount) // coins[i] >= res:
                return
            if (amount - curr) % coins[i] == 0:
                res = min(res, (amount - curr) // coins[i] + count)
            if i == len(coins) - 1:
                return
            for j in range((amount - curr) // coins[i], -1, -1):
                dfs(count + j, curr + coins[i] * j, i + 1)

        coins.sort(reverse=True)
        res = amount + 1
        dfs(0, 0, 0)
        return res if(res < amount + 1) else -1
__________________________________________________________________________________________________
sample 13028 kb submission
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [math.inf] * (amount + 1)
        dp[0] = 0
        
        for c in coins:
            for w in range(c, amount + 1):
                dp[w] = min(dp[w], dp[w - c] + 1)
        return dp[-1] if dp[-1] != math.inf else -1
__________________________________________________________________________________________________
