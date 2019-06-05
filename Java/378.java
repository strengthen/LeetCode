__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        // use binaru search
        // the array is not fully sorted
        // but when we know lo and hi, we could always know how many entries
        // are smaller than mid (in an efficient way), and redefine the search range
        int row = matrix.length, col = matrix[0].length;
        int lo = matrix[0][0], hi = matrix[row-1][col-1];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            // now count how many entries are smaller than mid
            // you may count row by row, or another way
            int count = getLessOrEqual(matrix, mid);
            if (count < k) lo = mid + 1;
            else hi = mid;
        }
        
        // how can you make sure that lo is one of the elements in the matrix?
        return lo;
    }
    
    private int getLessOrEqual(int[][] matrix, int target) {
        // this function is very interesting!
        // think about how it works!
        int i = matrix.length - 1, j = 0;
        int res = 0;
        while (i >= 0 && j < matrix[0].length) {
            if (matrix[i][j] > target) {
                i --;
            } else {
                res += i + 1;
                j++;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 38732 kb submission
class Solution {
    public int kthSmallest(int[][] M, int k) {
        int n = M.length;
        PriorityQueue<Tuple> Q = new PriorityQueue<>(10000, (a, b) -> M[a.r][a.c] - M[b.r][b.c]);
        Tuple t = new Tuple(0, 0);
        Q.add(t);
        while (k-- > 0) {
            t = Q.remove();
            if (t.r + 1 < n) 
                Q.add(new Tuple(t.r + 1, t.c));
            if (t.r == 0 && t.c + 1 < n) 
                Q.add(new Tuple(t.r, t.c + 1));
        }
        return M[t.r][t.c];
    }
    class Tuple {
        int r;
        int c;
        Tuple(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}
__________________________________________________________________________________________________
