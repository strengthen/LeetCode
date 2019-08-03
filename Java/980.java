__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    
    private int pathNum = 0;
    
    public int uniquePathsIII(int[][] grid) {
        int m = grid.length, n = grid[0].length;
		int x = 0;
		int y = 0;
		int zeroNum = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					x = i;
					y = j;
				}
				if (grid[i][j] == 0) {
					zeroNum++;
				}
			}
		}
		pathNum = 0;
		oneSpeed(grid, x, y, 1, zeroNum + 1);
		return pathNum;
    }
    
    private void oneSpeed(int[][] grid, int x, int y, int speedNum, int total) {
		if (x > 0) {
			if (grid[x-1][y] == 2 && speedNum == total) {
				pathNum++;
				return;
			}
			if (grid[x-1][y] == 0) {
				grid[x][y] = -2;
				oneSpeed(grid, x - 1, y, speedNum + 1, total);
				grid[x][y] = 0;
			}
		}
		if (y < grid[0].length - 1) {
			if (grid[x][y + 1] == 2 && speedNum == total) {
				pathNum++;
				return;
			}
			if (grid[x][y + 1] == 0) {
				grid[x][y] = -2;
				oneSpeed(grid, x, y+1, speedNum + 1, total);
				grid[x][y] = 0;
			}
		}
		if (x < grid.length - 1) {
			if (grid[x+1][y] == 2 && speedNum == total) {
				pathNum++;
				return;
			}
			if (grid[x+1][y] == 0) {
				grid[x][y] = -2;
				oneSpeed(grid, x+1, y, speedNum + 1, total);
				grid[x][y] = 0;
			}
		}
		if (y > 0) {
			if (grid[x][y - 1] == 2 && speedNum == total) {
				pathNum++;
				return;
			}
			if (grid[x][y - 1] == 0) {
				grid[x][y] = -2;
				oneSpeed(grid, x, y-1, speedNum + 1, total);
				grid[x][y] = 0;
			}
		}
	}
}
__________________________________________________________________________________________________
sample 35240 kb submission
class Solution {
    int paths = 0, empty = 1, startRow, startCol;
    private static final int[][] directions = {{1,0},{0,1},{0,-1},{-1,0}};
    public int uniquePathsIII(int[][] grid) {
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                if(grid[i][j] == 0) empty++;
                else if(grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
            }
        }
        dfs(grid, startRow, startCol);
        return paths;
    }
    public void dfs(int[][] grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] < 0)
            return;
        
        if(grid[i][j] == 2) {
            if(empty == 0)
                paths++;
            return;
        }
        grid[i][j] = -1;
        empty--;
        
        for(int[] dir : directions) {
            dfs(grid, i + dir[0], j + dir[1]);
        }
        empty++;
        grid[i][j] = 0;
    }
}
__________________________________________________________________________________________________
