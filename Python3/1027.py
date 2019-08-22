__________________________________________________________________________________________________
sample 384 ms submission
class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        idx = collections.defaultdict(list)
        for i, v in enumerate(A):
            idx[v].append(i)
        c = {}
        ans = 0
        for k in range(len(A)):   # last
            for j in range(k):      # middle
                v = 2 * A[j] - A[k]
                if v in idx:
                    for i in idx[v]:    # list of first
                        if i >= j:
                            break
                        r = 1
                        if (i, j) in c:
                            r = max(r, c[i, j] + 1)
                        ans = max(ans, r)
                        c[j, k] = r
        return ans + 2    
__________________________________________________________________________________________________
sample 50000 kb submission
from collections import defaultdict

class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        n = len(A)
        if n < 3: return n
        
        dp = [[2]*n for i in range(n)]
        
        index = defaultdict(list)
        for i in range(n):
            index[A[i]].append(i)
        
        for i in range(n):
            dp[i][i] = 1
        
        max_len = 2
        
        for j in range(0, n):
            for i in range(j):
                for k in index[2*A[i] - A[j]]:
                    if k < i:
                        dp[i][j] = max(dp[i][j], dp[k][i] + 1)
                        max_len = max(max_len, dp[i][j])
        
        #print(dp)
        
        return max_len
        
        
#dp[i][j] = min(dp[i][j], dp[k][i] + 1)
__________________________________________________________________________________________________
