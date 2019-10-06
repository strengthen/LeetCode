__________________________________________________________________________________________________
14ms
class Solution {
    private static final int[] directions = new int[]{0, 1, 0, -1, 0};

    boolean valid(int[][] grid, int r, int c) {
        return r >= 0 && r < grid.length && c >= 0 && c < grid[0].length && grid[r][c] > 0;
    }

    int dfs(int[][] grid, int r, int c) {
        if (!valid(grid, r, c)) return 0;

        int origin = grid[r][c];
        grid[r][c] = 0; // mark as visited

        int maxAmount = 0;
        for (int i = 0; i < 4; i++)
            maxAmount = Math.max(maxAmount, dfs(grid, directions[i] + r, directions[i+1] + c));

        grid[r][c] = origin; // backtrack
        return maxAmount + origin;
    }

    public int getMaximumGold(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int maxAmount = 0;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                maxAmount = Math.max(maxAmount, dfs(grid, r, c));

        return maxAmount;
    }
}
__________________________________________________________________________________________________
sample 18 ms submission
class Solution {
    int[][] dir = new int[][]{{1,0},{0,-1},{0,1},{-1,0}};
    
    public int getMaximumGold(int[][] grid) {
        int width = grid.length, length = grid[0].length, res = 0;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                
                    int cur = dfs(grid, i, j);
                    res = Math.max(cur, res);
                
            }
        }
        return res;
    }
    
    private boolean shouldStart(int[][] grid, int i, int j) {
        int width = grid.length, length = grid[0].length;
        if (grid[i][j] == 0) return false;
        int nonZeroCount = 0;
        for (int[] d : dir) {
            if (i + d[0] < width && i + d[0] >= 0 && j + d[1] < length && j + d[1] >= 0) {
                if (grid[i + d[0]][j + d[1]] != 0) nonZeroCount++;
            }
        }
        return nonZeroCount <= 1;
    }
    
    private int dfs(int[][] grid, int r, int c) {
        int width = grid.length, length = grid[0].length;
        if (r >= width || r < 0 || c >= length || c < 0 || grid[r][c] <= 0) return 0;
        // System.out.format("r: %d, c: %d, val: %d\n", r,c,grid[r][c]);
        grid[r][c] *= -1;
        int oneway = 0;
        for (int[] d : dir) {
            oneway = Math.max(dfs(grid, r + d[0], c + d[1]), oneway);
        }
        grid[r][c] *= -1;
        return grid[r][c] + oneway;
    }
}
__________________________________________________________________________________________________
