__________________________________________________________________________________________________
sample 140 ms submission
from functools import lru_cache
class Solution:
    def strangePrinter(self, s: str) -> int:
        @lru_cache(None)
        def find_min(start, end):
            if start >= end: return 1 if end == start else 0
            out, k = 1 + find_min(start+1, end), nextIdx[start]
            while k != None and k <= end:
                temp = find_min(start,k-1) + find_min(k+1,end)
                if temp < out: out = temp
                k = nextIdx[k]
            return out
        
        if not s: return 0
        new_s = []
        for i, c in enumerate(s[:-1]):
            if s[i+1] != c: new_s.append(c)
        s = ''.join(new_s + [s[-1]])

        nextIdx = [None] * len(s)
        lastIdx = {}
        
        for i in range(len(s)-1, -1, -1):
            if s[i] in lastIdx: nextIdx[i] = lastIdx[s[i]]
            lastIdx[s[i]] = i
        return find_min(0, len(s)-1)
__________________________________________________________________________________________________
sample 13080 kb submission
class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        if n == 0: return 0
        
        dp = [[0] * n for i in range(n)]
        
        for i in range(n): # length of range is 1
            dp[i][i] = 1
            
        for l in range(2, n+1): # length of range [i, j] from 2 to n
            for i in range(n - l + 1):
                j = i + l - 1
                dp[i][j] = 1 + dp[i+1][j] # default choice, print the first letter s[i] and then the rest
                
                for k in range(i+1, j+1):
                    if s[k] == s[i]: # better choice than default one
                        dp[i][j] = min(dp[i][j], dp[i][k-1] + (0 if k+1 > j else dp[k+1][j]))
                        
        return dp[0][n-1]
        
# a x x x x x x x a x x x x x 
# dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k+1][j])
__________________________________________________________________________________________________
