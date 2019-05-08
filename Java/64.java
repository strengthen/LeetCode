__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    
    private int[][] memory;
    
    public int minPathSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        //避免重复计算，缓存用
        memory= new int[n][m];
 
        return rec(grid, n - 1, m - 1);
    }

    public int rec(int[][] grid, int i, int j) {
        //1.边界条件
        if (i == 0 && j == 0) 
            return grid[0][0];
        //判断是否计算过
        if (memory[i][j] != 0) return memory[i][j];
        
        //2.拆分为子任务（分治：右下角[n - 1, m - 1]为终点，拆）
        //2.遍历所有子选项（dfs：右下角[n - 1, m - 1]为起点，走到[0,0]）
        //3.返回值任务：3种情况
        //4.返回结果并存入memory[i][j]
        if (i == 0)
            return memory[i][j] = grid[i][j] + rec(grid, i, j - 1);
        else if (j == 0)
            return memory[i][j] = grid[i][j] + rec(grid, i - 1, j);
        else
            return memory[i][j] = grid[i][j] + Math.min(rec(grid, i - 1, j), rec(grid, i, j - 1));
    }
}
__________________________________________________________________________________________________
sample 37048 kb submission
class Solution {
    final int R = 10000;
    public int minPathSum(int[][] grid) {
        int h = grid.length;
        int w = h == 0 ? 0 : grid[0].length;
        if (w == 0 || h == 0) return 0;
        Set<Integer> nextPass = new HashSet<>();
        if (h > 1) nextPass.add(R*1+0);
        if (w > 1) nextPass.add(1);
        while (!nextPass.isEmpty()) {
            Set<Integer> copy = new HashSet<>(nextPass);
            nextPass.clear();
            for (int n: copy) {
                int x = n%R;
                int y = n/R;
                checkCell(grid, x, y, w, h, nextPass);
            }
        }
        return grid[h-1][w-1];
    }
    
    private void checkCell(int[][] grid, int x, int y, int w, int h, Set<Integer> nextPass) {
        int value = grid[y][x];
        if (x == 0) {
            //only up
            grid[y][x] = value + grid[y-1][x];
        } else if (y == 0) {
            //only left
            grid[y][x] = value + grid[y][x-1];
        } else {
            //both
            grid[y][x] = Math.min(value + grid[y-1][x], value + grid[y][x-1]);
        }
        //add right
        if (x < w-1) {
            nextPass.add(R*y + x + 1);
        }
        //add down
        if (y < h-1) {
            nextPass.add(R*(y+1) + x);            
        }
    }
}
__________________________________________________________________________________________________
