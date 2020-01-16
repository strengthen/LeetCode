__________________________________________________________________________________________________
sample 68 ms submission
from collections import deque 

class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        cache = [deque([0] * i) for i in rollMax]

        factor = 10 ** 9 + 7
        
        dp = [1] * 6
        for c in cache:
            c[-1] = 1
        
        for _ in range(n-1):
            total = sum(dp)
            for k, c in enumerate(cache):
                c.append(total - dp[k])
                dp[k] = (total - c.popleft()) % factor
                
        return sum(dp) % factor
__________________________________________________________________________________________________
from collections import Counter, defaultdict, OrderedDict
from bisect import bisect_left, bisect_right
true = True
false = False
MOD = pow(10, 9) + 7


class Solution:
    def dieSimulator(self, n, rm):
        cache = [[0] * i for i in rm]
        for c in cache:
            c[-1] = 1
        dp = [1] * 6
        for _ in range(n - 1):
            nsum = sum(dp)
            for k, c in enumerate(cache):
                c.append(nsum - dp[k])
                dp[k] = (nsum - c.pop(0)) % MOD

        return sum(dp) % MOD


s = Solution()
n, rm = 2, [1, 1, 2, 2, 2, 3]
n, rm = 3, [1, 1, 1, 2, 2, 3]
n, rm = 5000, [13, 3, 12, 14, 11, 11]
print(s.dieSimulator(n, rm))
__________________________________________________________________________________________________
