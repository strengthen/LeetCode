__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        colorBorderDFS(grid, grid[r0][c0], r0, c0, color, visited);
        return grid;
    }

    private boolean colorBorderDFS(int[][] grid, int prevColor, int r, int c, int newColor, boolean[][] visited) {
        if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length)
            return true;
        if (visited[r][c])
            return false;
        if (grid[r][c] != prevColor)
            return true;
        visited[r][c] = true;
        boolean shiftColor = colorBorderDFS(grid, prevColor, r - 1, c, newColor, visited);
        shiftColor = colorBorderDFS(grid, prevColor, r + 1, c, newColor, visited) || shiftColor;
        shiftColor = colorBorderDFS(grid, prevColor, r, c - 1, newColor, visited) || shiftColor;
        shiftColor = colorBorderDFS(grid, prevColor, r, c + 1, newColor, visited) || shiftColor;
        if (shiftColor) {
            grid[r][c] = newColor;
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 38628 kb submission
class Solution {
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        int curr = grid[r0][c0];
        if (curr == color)
            return grid;
        LinkedList<Integer[]> list = new LinkedList<Integer[]>();
        Integer[] start = {r0, c0};

        list.push(start);
        
        int[][] copy = Arrays.stream(grid).map(x -> x.clone()).toArray(int[][]::new);
        int[][] res = Arrays.stream(grid).map(x -> x.clone()).toArray(int[][]::new);
        
        while (!list.isEmpty()) {
            Integer[] coord = list.pop();
            
            if (coord[0] == 0 || coord[0] == grid.length-1 || coord[1] == 0 || coord[1] == grid[0].length-1 ||
                copy[coord[0]-1][coord[1]] != curr ||
                copy[coord[0]+1][coord[1]] != curr  ||
                copy[coord[0]][coord[1]-1] != curr  ||
                copy[coord[0]][coord[1]+1] != curr )
                res[coord[0]][coord[1]] = color;
            
            grid[coord[0]][coord[1]] = color;
            
            if (coord[0] > 0 && grid[coord[0]-1][coord[1]] == curr) {
                Integer[] c = {coord[0]-1, coord[1]};
                list.push(c);
            }
            
            if (coord[0] < grid.length-1 && grid[coord[0]+1][coord[1]] == curr) {
                Integer[] c = {coord[0]+1, coord[1]};
                list.push(c);
            }
            
            if (coord[1] > 0 && grid[coord[0]][coord[1]-1] == curr) {
                Integer[] c = {coord[0], coord[1]-1};
                list.push(c);
            }
            
            if (coord[1] < grid[0].length-1 && grid[coord[0]][coord[1]+1] == curr) {
                Integer[] c = {coord[0], coord[1]+1};
                list.push(c);
            } 
        }
        return res;
    }   
}
__________________________________________________________________________________________________
