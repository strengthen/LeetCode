__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    int N;
    int[] dx = new int[]{-1, 0, 0, 1};
    int[] dy = new int[]{0, -1, 1, 0};
    
    public int surfaceArea(int[][] grid) {
        N = grid.length;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ans += area(grid, i, j);
            }
        }
        
        return ans;
    }
    
    private int area(int[][] grid, int x, int y) {
        int cur = grid[x][y];
        if (cur == 0) {
            return 0;
        }
        
        int res = 2;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (inBound(nx, ny)) {
                res += cur - grid[nx][ny] > 0 ? cur - grid[nx][ny] : 0;
            } else {
                res += cur;
            }
        }
        
        return res;
    }
    
    private boolean inBound(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }
}
__________________________________________________________________________________________________
sample 38472 kb submission
class Solution {
    int [] dr = new int [] {1, 0, -1, 0};
    int [] dc = new int [] {0, 1, 0, -1};
    public int surfaceArea(int[][] grid) {
        int res = 0;
        for(int i = 0; i < grid.length; ++i) for(int j = 0; j < grid[0].length; ++j) res += getArea(grid, i, j);
        return res;
    }
    
    private int getArea(int[][]grid, int r, int c){
        if(grid[r][c] == 0) return 0;
        int area = grid[r][c] * 4 + 2;
        for(int i = 0; i < dr.length; ++i){
            int nR = r + dr[i], nC = c + dc[i];
            if(nR < 0 || nC < 0 || nR >= grid.length || nC >= grid[0].length) continue;
            area -= Math.min(grid[r][c], grid[nR][nC]);
        }
        return area;
    }
}
__________________________________________________________________________________________________
