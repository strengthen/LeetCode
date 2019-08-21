__________________________________________________________________________________________________
sample 48 ms submission
# https://leetcode.com/problems/valid-permutations-for-di-sequence/discuss/168278/C%2B%2BJavaPython-DP-Solution-O(N2)

class Solution:
    def numPermsDISequence(self, S: str) -> int:
        dp = [1] * (len(S) + 1)
        for c in S:
            if c == "I":
                dp = dp[:-1]
                for i in range(1, len(dp)):
                    dp[i] += dp[i - 1]
            else:
                dp = dp[1:]
                for i in range(len(dp) - 1)[::-1]:
                    dp[i] += dp[i + 1]
        return dp[0] % (10**9 + 7)        
__________________________________________________________________________________________________
sample 64 ms submission
class Solution:
    def numPermsDISequence(self, S: str) -> int:
        if not S:
            return 0

        mod = 1000000007
        n = len(S)
        dp = []
        for i in range(n+1):
            dp.append([0] * (n+1))
        dp[0][0] = 1

        for i in range(1, n+1):
            for j in range(i+1):
                if S[i-1] == 'D':
                    if j != 0:
                        dp[i][j] = (dp[i-1][i-1] - dp[i-1][j-1] + dp[i][j-1]) % mod
                    else:
                        dp[i][j] = dp[i-1][i-1]
                elif S[i-1] == 'I':
                    if j != 0:
                        dp[i][j] = (dp[i-1][j-1] + dp[i][j-1]) % mod
        
        return dp[n][n]
__________________________________________________________________________________________________
