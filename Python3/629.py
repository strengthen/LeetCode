__________________________________________________________________________________________________
sample 364 ms submission
class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        MAX = 10 ** 9 + 7
        prev = [0] * (k + 1)
        for i in range(1, n + 1):
            curr = [1] + [0] * k
            curr_sums = prev[0]
            for j in range(1, k + 1):
                curr_sums += prev[j]
                curr_sums -= (prev[j - i] if(j >= i) else 0)
                curr[j] = curr_sums % MAX
            prev = curr
        return prev[-1] % MAX
__________________________________________________________________________________________________
sample 380 ms submission
import itertools

class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        mod = 10 ** 9 + 7
        dp = [1] + [0] * k
        for i in range(1, n):
            pre = list(itertools.accumulate(dp))
            dp = [(pre[j] - (j >= i + 1 and pre[j - i - 1])) % mod for j in range(k + 1)]
        return dp[-1]
__________________________________________________________________________________________________
