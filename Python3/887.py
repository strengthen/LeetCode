__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        memo = {}
        m = 1
        
        while True:
            for k in range(1, K+1):
                if k == 1:
                    memo[(m, k)] = m
                elif m < k:
                    memo[(m, k)] = memo[(m, m)]
                else: 
                    memo[(m, k)] = memo[(m-1, k)] + memo[(m-1, k-1)] + 1
            if memo[(m, K)] >=N:
                return m
            m += 1
__________________________________________________________________________________________________
sample 13060 kb submission
class Solution:
    def superEggDrop(self, K, N):
        dp = [0, 0]
        m = 0
        while dp[-1] < N:
            for i in range(len(dp) - 1, 0, - 1):
                dp[i] += dp[i - 1] + 1
            if len(dp) < K + 1:
                dp.append(dp[-1])
            m += 1
        return m
__________________________________________________________________________________________________
