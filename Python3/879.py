__________________________________________________________________________________________________
sample 268 ms submission
import numpy as np
class Solution:
    def profitableSchemes(self, G: int, P: int, group: List[int], profit: List[int]) -> int:
        n = len(profit)
        dp = np.zeros((n,G+1,P+1),dtype='int')
        dp[0,:,0]  = 1 # profit, gang , target profit
        dp[0,group[0]:,:profit[0] + 1] += 1
        
        for i in range(1,n):
            dp[i,:,:] = dp[i-1,:,:]
            if(profit[i] < P):
                dp[i, group[i]:, profit[i]+1:] += dp[i-1, 0: G + 1 - group[i], 1: P - profit[i] + 1]
            for g in range(group[i], G + 1):
                dp[i, g , :profit[i] + 1] += dp[i-1, g - group[i], 0] # why ? 
            dp[i,:,:] = np.mod(dp[i,:,:], 1000000007)
        return int(dp[-1][-1][-1])
__________________________________________________________________________________________________
sample 800 ms submission
class Solution:
    def profitableSchemes(self, G: int, P: int, group: List[int], profit: List[int]) -> int:
    
        # solution but slow
        n = len(group)
        dp = [[0 for _ in range(G+1)] for _ in range(P+1)]
        dp[0][0] = 1
        
        for i in range(n):
            temp = [row[:] for row in dp]
            for p in range(P+1):
                pbound = min(p+profit[i], P)
                for g in range(G-group[i]+1):
                    temp[pbound][g+group[i]] += dp[p][g]
                    
            dp = temp
                
        return sum(dp[P]) % (pow(10, 9) + 7)
__________________________________________________________________________________________________
