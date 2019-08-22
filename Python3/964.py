__________________________________________________________________________________________________
sample 32 ms submission
from functools import lru_cache

class Solution(object):
    def leastOpsExpressTarget(self, x, target):
        cost = list(range(40))
        cost[0] = 2

        @lru_cache(None)
        def dp(i, targ):
            if targ == 0: 
                return 0
            if targ == 1: 
                return cost[i]
            if i >= 39: 
                return float('inf')

            t, r = divmod(targ, x)
            return min(r * cost[i] + dp(i+1, t),
                       (x-r) * cost[i] + dp(i+1, t+1))

        return dp(0, target) - 1                
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def leastOpsExpressTarget(self, x, target):
        pos = neg = k = 0
        while target:
            target, cur = divmod(target, x)
            if k:
                pos, neg = min(cur * k + pos, (cur + 1) * k + neg), min((x - cur) * k + pos, (x - cur - 1) * k + neg)
            else:
                pos, neg = cur * 2, (x - cur) * 2
            k += 1
        return min(pos, k + neg) - 1
__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def leastOpsExpressTarget(self, x: int, target: int) -> int:
        memo = {}
        
        def helper(i, target):
            if (i, target) not in memo:
                # print(i, target)
                c = 2 if i == 0 else i
                if target == 0:
                    res = 0
                elif target == 1:
                    res = c
                elif target == x:
                    res = i + 1
                else:
                    t, r = target // x, target % x
                    res = min(helper(i + 1, t) + c * r,
                              helper(i + 1, t + 1) + c * (x - r))
                memo[(i, target)] = res
            return memo[(i, target)]
        return helper(0, target) - 1