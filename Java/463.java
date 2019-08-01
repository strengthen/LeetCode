__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int islandPerimeter(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        
        int count = 0;
        int m = grid.length, n = grid[0].length;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    count += 4;
                    
                    if (i > 0 && grid[i-1][j] == 1) {
                        count -= 2;
                    }
                
                    if (j > 0 && grid[i][j-1] == 1) {
                        count -= 2;
                    }
                }
            }
        }
        
        return count;
    }
}
__________________________________________________________________________________________________
sample 6 ms submission
class Solution {
    public int islandPerimeter(int[][] grid) {
        if(grid == null || grid.length == 0 || grid[0].length == 0)
            return 0;
        int result = 0;
        for(int i = 0; i < grid.length; i++)
        {
            for(int j = 0; j < grid[i].length; j++)
            {
                if(grid[i][j] == 1) {
                    result += 4;
                if(i > 0 && grid[i-1][j] == 1)  result -= 2;
                if(j > 0 && grid[i][j-1] == 1)  result -= 2;
                }
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 49436 kb submission
class Solution {
    
    private static class Counter {
        int val;
    }
    
    public int islandPerimeter(int[][] grid) {
        
        int[] initialPos = new int[2];
        
        loop:
        for (int i=0; i<grid.length; i++) {
            for (int j=0; j<grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    initialPos[0] = i;
                    initialPos[1] = j;
                    break loop;
                }
            }
        }
        
        Counter counter = new Counter();
        
        count(counter, grid, initialPos);
        
        return counter.val;
    }
    
    private void count(Counter counter, int[][] grid, int[] pos) {
        if (pos[0] < 0 
            || pos[0] == grid.length 
            || pos[1] < 0
            || pos[1] == grid[pos[0]].length
            || grid[pos[0]][pos[1]] == 2
            || grid[pos[0]][pos[1]] == 0
           ) {
            return;
        }
        
        grid[pos[0]][pos[1]] = 2;
        
        if (pos[0] == 0 || grid[pos[0]-1][pos[1]] == 0) {
            counter.val++;
        }
        
        if (pos[0] == grid.length - 1 || grid[pos[0]+1][pos[1]] == 0) {
            counter.val++;
        }
        
        if (pos[1] == 0 || grid[pos[0]][pos[1]-1] == 0) {
            counter.val++;
        }
        
        if (pos[1] == grid[pos[0]].length - 1 || grid[pos[0]][pos[1]+1] == 0) {
            counter.val++;
        }
        
        count(counter, grid, new int[]{pos[0]+1, pos[1]});
        count(counter, grid, new int[]{pos[0]-1, pos[1]});
        count(counter, grid, new int[]{pos[0], pos[1]+1});
        count(counter, grid, new int[]{pos[0], pos[1]-1});
    }
}