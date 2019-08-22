__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def numMusicPlaylists(self, N: int, L: int, K: int) -> int:
        dp=[[0]*(L+1) for _ in range(N+1)]
        for i in range(K+1,N+1):
            for j in range(i,L+1):
                if i==j or j-1==K:
                    dp[i][j]=math.factorial(i)
                else:
                    dp[i][j]=dp[i-1][j-1]*i+dp[i][j-1]*(i-K)
        return dp[-1][-1]%(10**9+7)
__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def numMusicPlaylists(self, n: int, l: int, k: int) -> int:
        mod = 10**9 + 7
        fib = list(range(1,101))
        for i in range(1, len(fib)):
            fib[i] *= fib[i-1]
        
        dp = [[0]*(l+1) for _ in range(n+1) ] # 记住，用来初始化dp数据的一种方法。总共要听l首，所以
        for i in range(1,n+1):
            for j in range(i,l+1):
                if i == j:
                    dp[i][j] = fib[i-1]
                elif i < k:
                    continue
                else:
                    dp[i][j] = dp[i-1][j-1] * i + dp[i][j-1]*(i-k)
                    
        return dp[-1][-1] % mod
__________________________________________________________________________________________________
