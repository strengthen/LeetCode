__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    private int R = 0;
    private int C = 0;
    private int r0 = 0;
    private int c0 = 0;
    private int counter = 0;
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        this.R = R;
        this.C = C;
        this.r0 = r0;
        this.c0 = c0;
        int dis = 1;
        int[][] cells = new int[R * C][];
        cells[counter++] = new int[]{r0, c0};
        while (true) {
            if (!addCells(cells, r0, c0 - dis)) {
                break;
            }
            dis++;
        }
        return cells;
    }
    
    private boolean addCells(int[][] cells, int lr, int lc) {
        boolean added = false;
        int dis = c0 - lc;
        int rr = r0;
        int rc = c0 + dis;
        if (add(cells, lr, lc)) added = true;
        if (add(cells, rr, rc)) added = true;
        for (int i = 1; i <= dis; i++) {
            if (add(cells, lr - i, lc + i)) added = true;
            if (add(cells, lr + i, lc + i)) added = true;
        }
        for (int i = 1; i < dis; i++) {
            if (add(cells, rr - i, rc - i)) added = true;
            if (add(cells, rr + i, rc - i)) added = true;
        }
        return added;
    }
    
    private boolean add(int[][] cells, int r, int c) {
        if (r >= 0 && r < R && c >= 0 && c < C) {
            cells[counter++] = new int[]{r, c};
            return true;
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 37548 kb submission
class Solution {
    public int[][] allCellsDistOrder(int r, int c, int r0, int c0) {
        int i = 0;
        int[][] result = new int[r * c][];
        result[i++] = new int[] {r0, c0};
        for (int d = 1; d < r + c; ++d) {
            for (int dr = 0; dr <= d; ++dr) {
                final int dc = d - dr;
                if (r0 - dr >= 0 && c0 - dc >= 0) {
                    result[i++] = new int[] {r0 - dr, c0 - dc};
                }
                if (dr > 0 && r0 + dr < r && c0 - dc >= 0) {
                    result[i++] = new int[] {r0 + dr, c0 - dc};
                }
                if (r0 - dr >= 0 && dc > 0 && c0 + dc < c) {
                    result[i++] = new int[] {r0 - dr, c0 + dc};
                }
                if (dr > 0 && r0 + dr < r && dc > 0 && c0 + dc < c) {
                    result[i++] = new int[] {r0 + dr, c0 + dc};
                }
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
