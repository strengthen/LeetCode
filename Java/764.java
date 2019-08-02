__________________________________________________________________________________________________
sample 32 ms submission
class Solution {
    public int orderOfLargestPlusSign(int N, int[][] mines) {
        PriorityQueue<Integer> rows[] = new PriorityQueue[N];
        PriorityQueue<Integer> cols[] = new PriorityQueue[N];
        
        for (int mine[] : mines) {
            insert(rows, mine[0], mine[1]);
            insert(cols, mine[1], mine[0]);
        }
        
        int byrows[][] = toGrid(rows);
        int bycols[][] = toGrid(cols);
        int biggest = 0;
        
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                int order = Math.min(byrows[r][c], bycols[c][r]);
                if (biggest < order) {
                    biggest = order;    
                } 
            }
        }
        
        return biggest;    
    }
    
    private void insert(PriorityQueue<Integer> vals[], int r, int c) {
        PriorityQueue<Integer> row = vals[r];
        
        if (row == null) {
            vals[r] = row = new PriorityQueue<>();
        }
        
        row.add(c);
    }
    
    private void fill(int row[], int c0, int c1) {
        int i = 0;
        
        while (++c0 <= --c1) {
            row[c0] = row[c1] = ++i;
        }
    }
    
    private int[][] toGrid(PriorityQueue<Integer> list[]) {
        int N = list.length;
        int grid[][] = new int[N][N];
        
        for (int r = 0; r < N; r++) {
            int prev = -1;
            
            if (list[r] != null) {
                for (int c : list[r]) {
                    fill(grid[r], prev, c);
                    prev = c;
                }
            }
            
            fill(grid[r], prev, N);
        }
        
        return grid;
    }
}
__________________________________________________________________________________________________
sample 49648 kb submission
class Solution {
    int[][] result;
    public int orderOfLargestPlusSign(int N, int[][] mines) {
        int[][] grid = new int[N][N];
        for(int[] row: grid) Arrays.fill(row, 1);

        for(int i = 0; i < mines.length; i++) {
            int r = mines[i][0];
            int c = mines[i][1];
            grid[r][c] = 0;
        }

        result = new int[N][N];
        int max = Integer.MIN_VALUE;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                DFS(grid, i, j, N);
                if(result[i][j] > max)
                    max = result[i][j];
            }
        }

//         for(int[] row: result) System.out.println(java.util.Arrays.toString(row));
        return max;
    }

    public void DFS(int[][] grid, int r, int c, int N) {
        int left = 0;
        int right = 0;
        int up = 0;
        int down = 0;
        left = DFSCol(grid, r, c, left, N, -1);
        right = DFSCol(grid, r, c, right, N, 1);
        up = DFSRow(grid, r, c, up, N, -1);
        down = DFSRow(grid, r, c, down, N, 1);
        
        result[r][c] = Math.min(Math.min(left, right), Math.min(up, down));
    }

    public int DFSRow(int[][] grid, int r, int c, int ans, int N, int k) {
        if(r < 0 || r >= N || c < 0 || c >= N) return ans;
        if(grid[r][c] == 0) return ans; 
        return DFSRow(grid, r + k, c, ans + 1, N, k);
    }

    public int DFSCol(int[][] grid, int r, int c, int ans, int N, int k) {
        if(r < 0 || r >= N || c < 0 || c >= N) return ans;
        if(grid[r][c] == 0) return ans;
        return DFSCol(grid, r, c + k, ans + 1, N, k);

    }
}
__________________________________________________________________________________________________
