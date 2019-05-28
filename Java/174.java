__________________________________________________________________________________________________
sample 0 ms submission

class Solution {
  public int calculateMinimumHP(int[][] dungeon) {
    int m = dungeon.length;
    int n = dungeon[0].length;
    int[][] dp = new int[m][n];
    return f(dungeon, 0, 0, dp);
  }

  private int f(int[][] dungeon, int i, int j, int[][] dp) {
    if (i >= dungeon.length || j >= dungeon[0].length) {
      return Integer.MAX_VALUE;
    } else if (i == dungeon.length - 1 && j == dungeon[0].length - 1) {
      dp[i][j] = Math.max(0, -dungeon[i][j]) + 1;
    } else if (dp[i][j] == 0) {
      int reqToNext = Math.min(f(dungeon, i + 1, j, dp), f(dungeon, i, j + 1, dp));
      dp[i][j] = Math.max(1, reqToNext - dungeon[i][j]);
    }
    // System.out.println(String.format("[%d, %d]: %d", i, j, dp[i][j]));
    return dp[i][j];
  }

  public int calculateMinimumHP_DP(int[][] dungeon) {
    int m = dungeon.length;
    int n = dungeon[0].length;
    int[][] dp = new int[m][n];
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        int reqToNext;
        if (i == m - 1 && j == n - 1) {
          reqToNext = 0;
        } else {
          int right = j == n - 1 ? Integer.MAX_VALUE : dp[i][j + 1];
          int down = i == m - 1 ? Integer.MAX_VALUE : dp[i + 1][j];
          reqToNext = Math.min(right, down);
        }
        dp[i][j] = Math.max(0, reqToNext - dungeon[i][j]);
        System.out.println(String.format("[%d, %d]: %d", i, j, dp[i][j]));
      }
    }

    return Math.max(dp[0][0], 0) + 1;
  }
}
__________________________________________________________________________________________________
sample 34764 kb submission
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int n = dungeon.length, m = dungeon[0].length;
        int[][] dp = new int[n+1][m+1];
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                dp[i][j] = Integer.MAX_VALUE;
        dp[n][m-1] = dp[n-1][m] = 1;
        
        for (int i = n-1; i >= 0; --i)
            for (int j = m-1; j >= 0; --j) {
                int need = Math.min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = need > 0 ? need : 1;
            }
        return dp[0][0];
    }
}
__________________________________________________________________________________________________
