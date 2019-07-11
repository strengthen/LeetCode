__________________________________________________________________________________________________
sample 9 ms submission
class Solution {
    private static class Cell implements Comparable<Cell> {
        private int row;
        private int col;
        private int value;
        public Cell(int r, int c, int v) {
            this.row = r;
            this.col = c;
            this.value = v;
        }
        @Override
        public int compareTo(Cell other) {
            return value - other.value;
        }
    }
    private int water;
    private boolean[][] visited1;
    public int trapRainWater(int[][] heightMap) {
        if (heightMap.length == 0) return 0;
        PriorityQueue<Cell> walls = new PriorityQueue<Cell>();
        water = 0;
        visited1 = new boolean[heightMap.length][heightMap[0].length];
        int rows = heightMap.length, cols = heightMap[0].length;
        //build wall;
        for (int c = 0; c < cols; c++) {
        	walls.add(new Cell(0, c, heightMap[0][c]));
        	walls.add(new Cell(rows - 1, c, heightMap[rows - 1][c]));
        	visited1[0][c] = true;
        	visited1[rows - 1][c] = true;
        }
        for (int r = 1; r < rows - 1; r++) {
        	walls.add(new Cell(r, 0, heightMap[r][0]));
        	walls.add(new Cell(r, cols - 1, heightMap[r][cols - 1]));
        	visited1[r][0] = true;
        	visited1[r][cols - 1] = true;
        }
        //end build wall;
        while(walls.size() > 0) {
            Cell min = walls.poll();
            visit(heightMap, min, walls);
        }
        return water;
    }
    private void visit(int[][] height, Cell start, PriorityQueue<Cell> walls) {
        fill(height, start.row + 1, start.col, walls, start.value);
        fill(height, start.row - 1, start.col, walls, start.value);
        fill(height, start.row, start.col + 1, walls, start.value);
        fill(height, start.row, start.col - 1, walls, start.value);
    }
    private void fill(int[][] height, int row, int col, PriorityQueue<Cell> walls, int min) {
        if (row < 0 || col < 0) return;
        else if (row >= height.length || col >= height[0].length) return;
        else if (visited1[row][col]) return;
        else if (height[row][col] >= min) {
            walls.add(new Cell(row, col, height[row][col]));
            visited1[row][col] = true;
            return;
        } else {
//        	System.out.println(row + ", " + col + " height = " + height[row][col] + ", bar = " + min);
            water += min - height[row][col];
            visited1[row][col] = true;
            fill(height, row + 1, col, walls, min);
            fill(height, row - 1, col, walls, min);
            fill(height, row, col + 1, walls, min);
            fill(height, row, col - 1, walls, min);
        }
    }
}
__________________________________________________________________________________________________
sample 35704 kb submission
class Solution {
    class Cell {
        int row, col, val;
        
        public Cell(int row, int col, int val) {
            this.row = row;
            this.col = col;
            this.val = val;
        }
        
    }
    public int trapRainWater(int[][] heightMap) {
        if (heightMap == null || heightMap.length == 0) return 0;
        PriorityQueue<Cell> pq = new PriorityQueue<>((Cell c1, Cell c2) -> c1.val - c2.val);
        int m = heightMap.length, n = heightMap[0].length;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            visited[i][0] = true;
            visited[i][n - 1] = true;
            pq.offer(new Cell(i, 0, heightMap[i][0]));
            pq.offer(new Cell(i, n - 1, heightMap[i][n - 1]));
        }
        
        for (int i = 0; i < n; i++) {
            visited[0][i] = true;
            visited[m - 1][i] = true;
            pq.offer(new Cell(0, i, heightMap[0][i]));
            pq.offer(new Cell(m - 1, i, heightMap[m - 1][i]));
        }
        int res = 0;
        int[][] dirs = new int[][] {{1, 0}, {-1 ,0}, {0, 1}, {0, -1}};
        while (!pq.isEmpty()) {
            Cell cur = pq.poll();
            for (int[] dir : dirs) {
                int x = cur.row + dir[0];
                int y = cur.col + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
                visited[x][y] = true;
                if (heightMap[x][y] < cur.val) res += cur.val - heightMap[x][y];
                pq.offer(new Cell(x, y, Math.max(heightMap[x][y] , cur.val)));
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
