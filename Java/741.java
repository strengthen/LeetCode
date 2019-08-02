__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    public int cherryPickup(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][][] mem = new int[m][n][m];
        for (int[][] x : mem) for (int[] y : x) Arrays.fill(y, Integer.MIN_VALUE);
        mem[0][0][0] = grid[0][0];
        return Math.max(0, dfs(grid, m-1, n-1, m-1, n-1, mem));
    }

    int dfs(int[][] grid, int i1, int j1, int i2, int j2, int[][][] mem) {
        if (i1 < 0 || i2 < 0 || j1 < 0 || j2 < 0 || i1 > i2 // i1>i2 is the trick to get 100%
            || grid[i1][j1] == -1 || grid[i2][j2] == -1) {
            return Integer.MIN_VALUE;
        }
        int res = mem[i1][j1][i2];
        if (res != Integer.MIN_VALUE) return res;

        res = grid[i1][j1];
        if (i1 != i2) {
            res += grid[i2][j2];
        }
        res += Math.max(Math.max(dfs(grid, i1-1, j1, i2-1, j2, mem),
                                 dfs(grid, i1, j1-1, i2-1, j2, mem)),
                        Math.max(dfs(grid, i1-1, j1, i2, j2-1, mem),
                                 dfs(grid, i1, j1-1, i2, j2-1, mem)));
        return mem[i1][j1][i2] = res;
    }
}
__________________________________________________________________________________________________
sample 37768 kb submission
class Solution {
    public int cherryPickup(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0] == null || grid[0].length == 0) return 0;
        int len = grid.length, totalSteps = 2 * len - 1;
        int[][] dp = new int[len][len];
        dp[0][0] = grid[0][0];

        for (int step = 1; step < totalSteps; step++) {
            for (int i = len - 1; i >= 0; i--) {
                for (int x = len - 1; x >= 0; x--) {
                    int j = step - i, y = step - x;
                    if ( y < 0 || y >= len || j < 0 || j >= len || grid[i][j] < 0 || grid[x][y] < 0) {
                        dp[i][x] = -1;
                        continue;
                    }
                    if (x > 0) dp[i][x] = Math.max(dp[i][x], dp[i][x - 1]);
                    if (i > 0) dp[i][x] = Math.max(dp[i][x], dp[i - 1][x]);
                    if (i > 0 && x > 0) dp[i][x] = Math.max(dp[i][x], dp[i - 1][x - 1]);
                    if (dp[i][x] >= 0) dp[i][x] += grid[i][j] + (i != x ? grid[x][y] : 0);
                }
            }
        }
        return Math.max(dp[len - 1][len - 1], 0);
    }
}
__________________________________________________________________________________________________
