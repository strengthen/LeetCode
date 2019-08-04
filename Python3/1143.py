__________________________________________________________________________________________________
sample 296 ms submission
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n = len(text2)
        cur = [0]*(n+1)
        for c in text1:
            new = [0]*(n+1)
            for i in range(n):
                if c == text2[i]:
                    new[i+1] = max(new[i], cur[i+1], cur[i]+1)
                else:
                    new[i+1] = max(new[i], cur[i+1])
            cur = new
        return cur[-1]
__________________________________________________________________________________________________
sample 316 ms submission
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        if not text1 or not text2:
            return 0
        
        mem = {}
        def dp(i, j):
            if i < 0 or j < 0:
                return 0
            if (i, j) in mem:
                return mem[(i, j)]
            res = 0
            if text1[i] == text2[j]:
                res = dp(i-1, j-1) + 1
            else:
                res = max(dp(i-1, j), dp(i, j-1))
            mem[(i, j)] = res
            return res
        
        return dp(len(text1) - 1, len(text2) - 1)
    
    
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        
        if not text1 or not text2:
            return 0
        
        dp = [0] * (len(text1) + 1)
        
        for j in range(len(text2)):
            dp1 = [0] * (len(text1) + 1)
            for i in range(len(text1)):
                if text1[i] == text2[j]:
                    dp1[i+1] = dp[i] + 1
                else:
                    dp1[i+1] = max(dp1[i], dp[i+1])
            dp = dp1
        return dp[-1]
    
    def longestCommonSubsequence2(self, x: str, y: str) -> int:
        m = len(x)
        n = len(y)
        c = [[0] * (n + 1) for i in range(m + 1)]
        
        for i in range(1, m+1):
            for j in range(1, n+1):
                if x[i-1] == y[j-1]:
                    c[i][j] = c[i-1][j-1] + 1
                else:
                    c[i][j] = max(c[i-1][j], c[i][j-1])
                    
        return c[m][n]
__________________________________________________________________________________________________
sample 324 ms submission
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        if len(text1) < len(text2):
            text1, text2 = text2, text1
            
        l1 = len(text1)
        l2 = len(text2)
        
        cur = [0] * (l2 + 1)
        prev, cur = cur, [0] * (l2 + 1)
        
        
        for i in range(1, l1 + 1):
            for j in range(1, l2 + 1):
                if text1[i - 1] == text2[j - 1]:
                    cur[j] = prev[j - 1] + 1
                else:
                    cur[j] = max(prev[j], cur[j - 1])
            prev, cur = cur, [0] * (l2 + 1)
            
        return prev[l2]                    