__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if(matrix == null || matrix.length == 0) return new int[0];
        int m = matrix.length, n = matrix[0].length;
        int[] res = new int[m*n];
        int i = 0, lvl = 0, x = 0, y = 0;
        while(i < m*n) {
            if(lvl % 2 == 0) {
                while(x >= 0 && y < n) res[i++] = matrix[x--][y++];
                if(y < n) {
                    x = 0;
                }
                else{
                    y = n - 1;
                    x += 2;
                }
                lvl ++;
            }
            else{
                while(y >= 0 && x < m) res[i++] = matrix[x++][y--];
                if(x < m) {
                    y = 0;
                }
                else{
                    x = m - 1;
                    y += 2;
                }
                lvl++;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 37960 kb submission
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {        
        List<int[]> d = new ArrayList<>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                d.add(new int[] {i, j});
            }
        }
        Collections.sort(d, (x,y)->x[0]+x[1]!=y[0]+y[1]? x[0]+x[1]-y[0]-y[1] : ((x[0]+x[1]) % 2 == 0 ? y[0]-x[0] : x[0]-y[0]));
        if (matrix.length == 0) return new int[0];
        int[] ret = new int[matrix.length *matrix[0].length];
        for (int i = 0; i < d.size(); i++) {
            ret[i] = matrix[d.get(i)[0]][d.get(i)[1]];
        }
        return ret;
    }
}
__________________________________________________________________________________________________
