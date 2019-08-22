__________________________________________________________________________________________________
sample 92 ms submission
class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        
        # solution 3:
        # runtime:
        sA = set(A)
        sB = set(B)
        
        AA = []
        BB = []
        for a in A:
            if a not in sA or a not in sB:
                continue                
            AA += [a]
            
        for b in B:
            if b not in sA or b not in sB:
                continue                
            BB += [b]
            
        return self.lcs(AA, BB)
        
    def lcs(self, X: List[int], Y: List[int]) -> int:
        # find the length of the strings 
        m = len(X) 
        n = len(Y) 
  
        # declaring the array for storing the dp values 
        L = [[None]*(n + 1) for i in range(m + 1)] 
  
        for i in range(m + 1): 
            for j in range(n + 1): 
                if i == 0 or j == 0 : 
                    L[i][j] = 0
                elif X[i-1] == Y[j-1]: 
                    L[i][j] = L[i-1][j-1]+1
                else: 
                    L[i][j] = max(L[i-1][j], L[i][j-1]) 
  
        # L[m][n] contains the length of LCS of X[0..n-1] & Y[0..m-1] 
        return L[m][n]        
__________________________________________________________________________________________________
sample 13060 kb submission
import functools

class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        N, M = len(A), len(B)
        dp = [0]*M
        for i in range(N):
            next_dp = dp.copy()
            for j in range(M):
                if A[i] == B[j]:
                    next_dp[j] = max(next_dp[j-1] if j else 0, 1 + (dp[j-1] if j else 0))
                else:
                    next_dp[j] = max(next_dp[j-1] if j else 0, dp[j])
            dp = next_dp
        return dp[-1]
__________________________________________________________________________________________________
