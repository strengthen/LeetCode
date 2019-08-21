__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def numTilings(self, N: int) -> int:
        #dp[N]=dp[N-1]+dp[N-2] + 2*(dp[N-3]+dp[N-4]+...dp[1]+dp[0]) ...eq(1)
        #dp[N-1] =dp[N-2]+dp[N-3] + 2*(dp[N-4]+dp[N-5]+....dp[0])   ...eq(2)
        #eq(1)-eq(2)=>
        # dp[N]=2*dp[N-1]+dp[N-3]
        #dp[0]=dp[1]=1

        if N<=1: return 1
        dp=[0]*(N+1)
        dp[0]=1
        dp[1]=1
        dp[2]=2
        md=int(1e9+7)
        for i in range(3,N+1):
            dp[i]=2*dp[i-1]+dp[i-3]
            dp[i]=dp[i]%md
        return dp[-1]
__________________________________________________________________________________________________
sample 13140 kb submission
class Solution:
    def numTilings(self, N: int) -> int:
        if N == 1:
            return 1
        elif N == 2:
            return 2
        else:
            f0 = 1 #  full
            f1 = 2
            l1 = 1 # l shape
            r1 = 1 # r shape
            for i in range(3, N + 1):
                f2 = (f1 + f0 + l1 + r1) % 1000000007
                l2 = (f0 + r1) 
                r2 = (f0 + l1) 
                f0 = f1 
                f1 = f2 
                l1 = l2 
                r1 = r2 
            
            return f2
__________________________________________________________________________________________________
