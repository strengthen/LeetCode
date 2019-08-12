__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def climbStairs(self, n: int) -> int:
        
        if n < 3:
            return n
        cur, prev = 2, 1
        for i in range(2, n):
            cur = cur + prev
            prev = cur - prev
            
        return cur
__________________________________________________________________________________________________
sample 12824 kb submission
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        
        dp = [1, 2] + [0]*(n-2)
        for i in range(2, n):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[-1]
__________________________________________________________________________________________________
