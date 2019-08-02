__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] maxPerRow = new int[grid.length];
        int[] maxPerCol = new int[grid[0].length];
        
        for (int r = 0; r < grid.length; r++) {            
            for (int c = 0; c < grid[0].length; c++) {
                maxPerRow[r] = Math.max(maxPerRow[r], grid[r][c]);
                maxPerCol[c] = Math.max(maxPerCol[c], grid[r][c]);
            }            
        }
                
        int ans = 0; 
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {                
                ans += Math.min(maxPerRow[r], maxPerCol[c]) - grid[r][c];
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
sample 37664 kb submission
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int oldSum = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                oldSum += grid[i][j];
                int maxValueRow = 0, maxValueColumn = 0;
                for (int k = 0; k < grid[0].length; k++) {
                    if (grid[i][k] > maxValueRow) {
                        maxValueRow = grid[i][k];
                    }
                }
                
                for (int k = 0; k < grid.length; k++) {
                    if (grid[k][j] > maxValueColumn) {
                        maxValueColumn = grid[k][j];
                    }
                }
                
                grid[i][j] = Math.min(maxValueRow, maxValueColumn);
            }
        }
        
        int sum = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                sum += grid[i][j];
            }
        }
        
        return sum - oldSum;
    }
}
__________________________________________________________________________________________________
