__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0] == 1 or obstacleGrid[-1][-1] == 1:
            return 0
        m, n = len(obstacleGrid[0]), len(obstacleGrid)
        arr = [0] * m
        arr[0] = 1
        for i in range(n):
            if obstacleGrid[i][0] == 1:
                arr[0] = 0
            for j in range(1, m):
                if obstacleGrid[i][j] == 0:
                    arr[j] = arr[j] + arr[j - 1]
                else:
                    arr[j] = 0
        return arr[-1]
__________________________________________________________________________________________________
sample 12892 kb submission
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        dp = []
        for i in range(len(obstacleGrid)):
            dp.append([0]*len(obstacleGrid[0]))
        dp[0][0] = 1 if obstacleGrid[0][0] == 0 else 0 
        for i in range(1,len(obstacleGrid)):
            dp[i][0] = 1 if obstacleGrid[i][0] == 0 and dp[i-1][0] != 0 else 0
        
        for j in range(1,len(obstacleGrid[0])):
            dp[0][j] = 1 if obstacleGrid[0][j] == 0 and dp[0][j-1] != 0 else 0
            
        for i in range(1,len(dp)):
            for j in range(1,len(dp[0])):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]
__________________________________________________________________________________________________
