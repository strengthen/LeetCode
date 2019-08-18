__________________________________________________________________________________________________
Runtime: 21 ms
Memory Usage: 46.8 MB
class Solution {
    public int maxDistance(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    visited[i][j] = true;
                    q.offer(new int[]{i, j});
                }
            }
        }
        int[][] dirs = new int[][]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int result = -1;
        while (!q.isEmpty()) {
            int size = q.size();
            while (size-- > 0) {
                int[] cur = q.poll();
                result = Math.max(result, grid[cur[0]][cur[1]] - 1);
                for (int[] dir : dirs) {
                    int x = cur[0] + dir[0], y = cur[1] + dir[1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                        visited[x][y] = true;
                        grid[x][y] = grid[cur[0]][cur[1]] + 1;
                        q.offer(new int[]{x, y});
                    }
                }
            }
        }
        return result == 0 ? -1 : result;
    }
}
__________________________________________________________________________________________________
sample 73 ms submission
class Solution {
    public int maxDistance(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                grid[i][j] = -1;
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) continue;
                bfs(grid, i, j);
            }
        }
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if (grid[i][j] == -1) continue;
                if (grid[i][j] == 0) return -1;
                res = Math.max(grid[i][j], res);
            }
        }
        return res == 0 ? -1 : res;
    }
    
    private void bfs(int[][] grid, int r0, int c0) {
        int[][] dirs = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = grid.length, n = grid[0].length;
        Queue<Integer> q = new LinkedList<>();
        q.offer(r0 * n + c0);
        while (!q.isEmpty()) {
            int curr = q.poll();
            int x = curr / n, y = curr % n;
            // System.out.println(x + "," + y);
            for (int[] dir : dirs) {
                int r = x + dir[0];
                int c = y + dir[1];
                if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == -1) continue;
                int dist = grid[x][y] == -1 ? 1 : grid[x][y] + 1;
                if (grid[r][c] == 0 || grid[r][c] > dist) {
                    // System.out.println(r + "," + c);
                    grid[r][c] = dist;
                    q.offer(r * n + c);
                }
            }
        }
    }
}
__________________________________________________________________________________________________
