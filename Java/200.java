__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        int m = grid.length;
        int n = grid[0].length;
        int res = 0;
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == '1') {
                    res++;
                    DFS(grid, i, j);
                }
            }
        }
        return res;
    }
    
    public void DFS(char[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0'; // modify original input
        DFS(grid, i + 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i - 1, j);
        DFS(grid, i, j - 1);
    }
}
__________________________________________________________________________________________________
sample 36784 kb submission
class Solution {
    public int numIslands(char[][] grid) {
        int ret = 0;
        for(int i = 0 ; i < grid.length; i++)
            for(int j = 0; j < grid[i].length; j++)
                ret += dfs(grid,i,j);
        return ret;
    }
    
    private int dfs(char[][]grid,int i, int j){
        //base case
        //out of bound
        if(i < 0 || i>= grid.length || j < 0 || j >= grid[i].length)return 0;
        //not a island
        if(grid[i][j] != '1')return 0;
        
        grid[i][j] = '-';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
        return 1;
        //dfs all possible connected island
    }
}
__________________________________________________________________________________________________
