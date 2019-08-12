__________________________________________________________________________________________________
sample 96 ms submission
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        M = len(grid)
        N = len(grid[0]) if M else 0
        
        dp = [[0 for _ in range(N)] for _ in range(M)]
        dp[0][0] = grid[0][0]
        for i in range(1, M):
            dp[i][0] += dp[i - 1][0] + grid[i][0]
        
        for i in range(1, N):
            dp[0][i] += dp[0][i - 1] + grid[0][i]
        
        for i in range(1, M):
            for j in range(1, N):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
        
        return dp[M - 1][N - 1]
__________________________________________________________________________________________________
sample 13164 kb submission
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        cur = [float('inf')] * m
        cur[0] = 0
        for j in range(n):
            for i in range(m):
                if i == 0:
                    cur[0] += grid[0][j]
                else:
                    cur[i] = min(cur[i], cur[i-1]) + grid[i][j]
        return cur[-1]        
__________________________________________________________________________________________________
