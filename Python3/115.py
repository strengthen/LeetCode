__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        '''
        dp=[[0 for i in range(len(t)+1)] for j in range(len(s)+1)]
        for i in range(len(s)+1):
            dp[i][0]=1
        for i in range(1, len(s)+1):
            for j in range(1, min(i+1, len(t)+1)):
                if s[i-1]==t[j-1]:
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1]
                else:
                    dp[i][j]=dp[i-1][j]
        return dp[len(s)][len(t)]
        '''
        dp = [ 0 for _ in range(0,len(t)) ]
        table = collections.defaultdict(list)
        for i in range(0, len(t)):
            table[t[i]].append(i)
        for char in s:
            for index in reversed(table[char]):
                if index is 0:
                    dp[index] += 1
                else:
                    dp[index] += dp[index-1]
        return int(dp[-1])
__________________________________________________________________________________________________
sample 13080 kb submission
# class Solution:
#     def numDistinct(self, s, t):
#         N = len(T)
#         dp = [1] + [0] * N
#         for i, v in enumerate(S, start = 1):
#             if v == T[i]
    
class Solution:
    def numDistinct(self, s, t):
        dp = [1] + [0] * len(t)
        for c in s:
            tmp = dp[:]
            for i, k in enumerate(t):
                if k == c:
                    tmp[i+1] += dp[i]
            dp = tmp
        return dp[-1]
__________________________________________________________________________________________________
