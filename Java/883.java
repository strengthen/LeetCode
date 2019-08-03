__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int projectionArea(int[][] grid) {
        int top = 0;
        int side = 0;
        int front = 0;
        for(int i = 0; i < grid.length; i++){
            int tempside = 0;
            int tempfront = 0;
            for(int j = 0; j < grid[i].length; j++){
                if(grid[i][j] != 0) top++;
                tempside = Math.max(tempside, grid[i][j]);
                tempfront = Math.max(tempfront, grid[j][i]);    
            }
            side += tempside;
            front += tempfront;
        }
        return top + side + front;
    }
}
__________________________________________________________________________________________________
sample 39260 kb submission
class Solution {
    public int projectionArea(int[][] grid) {
        int res = 0, n = grid.length;
        for (int i = 0; i < n; ++i) {
            int x = 0, y = 0;
            for (int j = 0; j < n; ++j) {
                x = Math.max(x, grid[i][j]);
                y = Math.max(y, grid[j][i]);
                if (grid[i][j] > 0) ++res;
            }
            res += x + y;
        }
        return res;
    }
}
__________________________________________________________________________________________________
