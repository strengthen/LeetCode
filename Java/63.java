__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int width = obstacleGrid[0].length;
        int[] dp = new int[width];
        dp[0] = 1;
        for (int[] row : obstacleGrid) {
            for (int j = 0; j < width; j++) {
                if (row[j] == 1)
                    dp[j] = 0;
                else if (j > 0)
                    dp[j] += dp[j - 1];
            }
        }
        return dp[width - 1];
    }
    }
__________________________________________________________________________________________________
sample 34252 kb submission
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid == null || obstacleGrid.length == 0 || obstacleGrid[0].length == 0) {
            return 0;
        }
        int[] paths = new int[obstacleGrid[0].length];
        paths[0] = 1;
        for (int r = 0; r < obstacleGrid.length; r++) {
            paths[0] = obstacleGrid[r][0] == 1 ? 0 : paths[0];
            for (int c = 1; c < obstacleGrid[0].length; c++) {
                paths[c] = obstacleGrid[r][c] == 1 ? 0 : paths[c - 1] + paths[c];
            }
        }
        return paths[obstacleGrid[0].length - 1];
    }
}
__________________________________________________________________________________________________
