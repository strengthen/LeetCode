__________________________________________________________________________________________________
class Solution:
    def make_dp(function):
        dp = {}

        def helper(o, n):
            if n not in dp:
                dp[n] = function(o, n)
            return dp[n]

        return helper
    
    
    @make_dp
    def integerReplacement(self, n: int) -> int:
        result = 0
        if n == 1: return result
        if n % 2 == 0:
            result += (1 + self.integerReplacement(n / 2))
        else:
            result += (1 + min(self.integerReplacement(n + 1),
                               self.integerReplacement(n - 1)))
        return result
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def integerReplacement(self, n: int) -> int:
        ops = 0
        while n > 1:
            if n % 2:
                if n > 4 and n % 4 == 3:
                    n += 1
                else:
                    n -= 1
            else:
                n >>= 1
            ops += 1
        return ops
__________________________________________________________________________________________________
