__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    
    private static final int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    public List<int[]> pacificAtlantic(int[][] matrix) {
        
        List<int[]> answer = new ArrayList<>();
        
        if ( matrix == null || matrix.length == 0 ) return answer;
        
		int N = matrix.length;
		int M = matrix[0].length;
        char[][] visited = new char[N][M];
		
        // Columns Pacific
		for (int c = 0; c < M; c++)
			dfs(matrix, 0, c, visited, 'P', answer);
		
        // Rows Pacific
        for (int r = 0; r < N; r++)
            dfs(matrix, r, 0, visited, 'P', answer);

        // Columns Atlantic
        for (int c = 0; c < M; c++)
            dfs(matrix, N-1, c, visited, 'A', answer);

        // Rows Atlantic
        for (int r = 0; r < N; r++)
                dfs(matrix, r, M-1, visited, 'A', answer);
		
		return answer;
    }
    
    private void dfs(int[][] matrix, int r, int c, char[][] visited, char ch, List<int[]> answer) {
        
        if ( visited[r][c] == 'P' && ch == 'A' ) answer.add(new int[]{r, c});
        
        visited[r][c] = ch;
        
        for ( int[] d : dirs ) {
            
            int nx = r + d[0];
            int ny = c + d[1];
            
            if ( nx < 0 || nx >= matrix.length || ny < 0 || ny >= matrix[0].length || matrix[r][c] > matrix[nx][ny] || visited[nx][ny] == ch )
                continue;
            
            dfs(matrix, nx, ny, visited, ch, answer);
        }
        
    }    
}
__________________________________________________________________________________________________
sample 39664 kb submission
import java.util.*;

class Solution {
    private int[][] directions = new int[][] {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    public List<int[]> pacificAtlantic(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) {
            return new ArrayList();
        }

        int m = matrix.length;
        int n = matrix[0].length;
        boolean[][] atlantic = new boolean[m][n];
        boolean[][] pacific = new boolean[m][n];

        // pacific fist
        PriorityQueue<int[]> queue = new PriorityQueue<>((a, b) -> (a[2] - b[2]));
        for (int i=0; i<m; i++) {
            queue.add(new int[] {i, 0, matrix[i][0]});
            pacific[i][0] = true;
        }
        for (int j=1; j<n; j++) {
            queue.add(new int[] {0, j, matrix[0][j]});
            pacific[0][j] = true;
        }
        
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            
            for (int[] direction : directions) {
                int x = cur[0] + direction[0];
                int y = cur[1] + direction[1];

                if (x < 0 || y < 0 || x == m || y == n || pacific[x][y] || matrix[x][y] < cur[2]) {
                    continue;
                }

                queue.add(new int[]{x, y, matrix[x][y]});
                pacific[x][y] = true;
            }
        }
        
        queue.clear();
        for (int i=0; i<m; i++) {
            queue.add(new int[] {i, n-1, matrix[i][n-1]});
            atlantic[i][n-1] = true;
        }
        for (int j=n-2; j>=0; j--) {
            queue.add(new int[] {m-1, j, matrix[m-1][j]});
            atlantic[m-1][j] = true;
        }
        
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            
            for (int[] direction : directions) {
                int x = cur[0] + direction[0];
                int y = cur[1] + direction[1];

                if (x < 0 || y < 0 || x == m || y == n || atlantic[x][y] || matrix[x][y] < cur[2]) {
                    continue;
                }

                queue.add(new int[]{x, y, matrix[x][y]});
                atlantic[x][y] = true;
            }            
        }
        
        
        List<int[]> res = new ArrayList();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.add(new int[] {i, j});
                }
            }
        }
        
        return res;
    }
}
__________________________________________________________________________________________________
