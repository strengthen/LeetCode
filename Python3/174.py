__________________________________________________________________________________________________
sample 72 ms submission
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        if dungeon is None or len(dungeon) == 0 or dungeon[0] is None or len(dungeon[0]) == 0:
            return sys.maxsize
        m = len(dungeon)
        n = len(dungeon[0])        
        dp = [0] * n
        
        dp[n-1] = max(1, 1 - dungeon[-1][-1])
        
        for j in range(n-2, -1, -1):
            dp[j] = max(1, dp[j+1]-dungeon[-1][j])
        for i in range(m-2, -1, -1):
            dp[n-1] = max(1, dp[n-1]-dungeon[i][-1])
            for j in range(n-2,-1,-1):
                dp[j] = max(1, min(dp[j], dp[j+1]) - dungeon[i][j])
        return dp[0]            
__________________________________________________________________________________________________
sample 13624 kb submission
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m = len(dungeon)
        n = len(dungeon[0])
        
        # dp[i][j]: the least health needed from (i, j) to where the
        # princess is
        # dp = [[float("inf") for _ in range(n+1)] for _ in range(m+1)]
        # dp[m-1][n] = 1
        # dp[m][n-1] = 1
        
        # save the space
        dp = [float("inf") for _ in range(n+1)]
        dp[n-1] = 1
        
        # reverse tabulation
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                # dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])
                dp[j] = max(1, min(dp[j], dp[j+1]) - dungeon[i][j])
        return dp[0]
__________________________________________________________________________________________________
