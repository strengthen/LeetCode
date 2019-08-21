__________________________________________________________________________________________________
sample 116 ms submission
import functools, itertools
memoise = functools.lru_cache(maxsize=None)
class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        P = [0, *itertools.accumulate(A)]
        
        @memoise
        def avg(i, j):
            return (P[j] - P[i]) / (j - i)
        
        @memoise
        def dp(n, k):
            if 1 <= k <= n:
                return max(dp(i, k-1) + avg(i, n) for i in range(k-1, n))
            elif k == n == 0:
                return 0
            else:
                return float('-inf')
        #print(dp.cache_info())
        return dp(len(A), K)
__________________________________________________________________________________________________
sample 13584 kb submission
class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        # A = [1,2,3]
        # K = 3
        def avg(i, j):
            return sum(A[i: j + 1]) / (j - i + 1)
        
        dp = [[0 for k in range(K + 1)] for i in range(len(A))]
        
        for i in range(len(A)):
            dp[i][1] = avg(0, i)
        
        for k in range(2, K + 1):
            for i in range(k - 1, len(A)):
                ans = 0
                for j in range(k - 1, i + 1):
                    ans = max(ans, dp[j - 1][k - 1] + avg(j, i))
                dp[i][k] = ans
        print(dp)
        return dp[-1][K]
__________________________________________________________________________________________________
