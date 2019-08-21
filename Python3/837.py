__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def new21Game(self, N, K, W):
        """
        :type N: int
        :type K: int
        :type W: int
        :rtype: float
        """
        d=[0]*(K+max(W,N)+10)
        for i in range(K,N+1):
            d[i]=1
        ms=N-K+1
        for i in range(K-1,-1,-1):
            d[i]=ms/W
            ms+=d[i]-d[i+W]
        return d[0]
__________________________________________________________________________________________________
sample 72 ms submission
class Solution:
    def new21Game(self, N: int, K: int, W: int) -> float:
        # dp[x] = the answer when Alice has x points
        dp = [0]*(N+1+W)
        for i in range(K, N+1):
            dp[i] = 1.0
        
        S = min(N-K+1, W)
        for i in range(K-1, -1, -1):
            dp[i] = S/W
            S += dp[i] - dp[i+W]
        return dp[0]
__________________________________________________________________________________________________
