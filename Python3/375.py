__________________________________________________________________________________________________
sample 80 ms submission
import functools
import math

class Solution:
    def getMoneyAmount(self, n: int) -> int:
        @functools.lru_cache(None)
        def dp(i, j):
            if i >= j:
                return 0
            ans = math.inf
            for k in range((i + j) // 2, j + 1):
                low_cost, high_cost = dp(i, k - 1), dp(k + 1, j)
                ans = min(ans, k + max(low_cost, high_cost))
                if low_cost > high_cost:
                    break
            return ans
        return dp(1, n)
__________________________________________________________________________________________________
sample 152 ms submission
import functools

class Solution:
    def getMoneyAmount(self, n: int) -> int:
        
        @functools.lru_cache(maxsize=None)
        def rec(i0, i1):
            if i1 - i0 < 1:
                return 0
            if i0 + 1 == i1:
                return i0
            if i0 + 2 == i1:
                return i0 + 1
            
            
            return min([j + max(rec(i0, j-1), rec(j+1, i1)) for j in range(i0 + (i1-i0)//2, i1+1)])
        
        return rec(1, n)
__________________________________________________________________________________________________
