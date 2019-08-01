__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        if (grid.length == 0) return 0;
        int m = grid.length, n = grid[0].length;
        int max_area = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    max_area = Math.max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }
    
    public int dfs(int[][] grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.length || col >= grid[0].length || grid[row][col] == 0) {
            return 0;
        }
        grid[row][col] = 0;
        return 1 + dfs(grid, row - 1, col) + dfs(grid, row, col - 1) + dfs(grid, row + 1, col) + dfs(grid, row, col + 1);
    }
}
__________________________________________________________________________________________________
sample 38156 kb submission
class Solution {
    int max = 0;
    public int maxAreaOfIsland(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    max = Math.max(max, dfs(grid, i, j));
                }
            }
        }
        return max;
    }
    private int dfs(int[][] grid, int i, int j) {
        int count = 0;
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length) {
            return count;
        }
        if (grid[i][j] == 0) {
            return count;
        }
        grid[i][j] = 0;
        count++;
        count += dfs(grid, i, j+1);
        count += dfs(grid, i+1, j);
        count += dfs(grid, i-1, j);
        count += dfs(grid, i, j-1);
        return count;
    }
}
__________________________________________________________________________________________________
