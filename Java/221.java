__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    class Pair {
        public int x;
        public int y;
        
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        @Override
        public boolean equals(Object obj) {
            if (obj == null || !(obj instanceof Pair)) {
                return false;
            }
            Pair o = (Pair) obj;
            
            return o.x == this.x && o.y == this.y;
        }
    }
    
    public int maximalSquare(char[][] matrix) {
        int maxx = 0;
        if (matrix.length < 1)
            return maxx;
        
        int[][] coord2dim = new int[matrix.length][matrix[0].length];
        
        for (int x = 0; x < matrix.length; x++) {
            for (int y = 0; y < matrix[x].length; y++) {
                coord2dim[x][y] = -1;
            }
        }
        
        for (int x = 0; x < matrix.length; x++) {
            for (int y = 0; y < matrix[x].length; y++) {
                int area = maximalSquare(matrix, x, y, coord2dim);
                maxx = Math.max(maxx, area * area);
            }
        }
        
        return maxx;
    }
    
    private int maximalSquare(char[][] matrix, int x, int y, int[][] coord2dim) {
        if (x >= matrix.length || y >= matrix[x].length || matrix[x][y] == '0')
            return 0;
        
        if (coord2dim[x][y] != -1) {
            return coord2dim[x][y];
        }
        
        int down = maximalSquare(matrix, x + 1, y, coord2dim);
        int right = 0;
        int diag = 0;
        
        if (down != 0)
            right = maximalSquare(matrix, x, y + 1, coord2dim);
        if (right != 0)
            diag = maximalSquare(matrix, x + 1, y + 1, coord2dim);
        
        coord2dim[x][y] =  1 + Math.min(Math.min(down, right), diag);
        
        return coord2dim[x][y];
    }
}
__________________________________________________________________________________________________
sample 37524 kb submission
class Solution {
    public int maximalSquare(char[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0)
            return 0;
        int[][] dp = new int[matrix.length+1][matrix[0].length+1];
        int maxLen = 0;
        for (int i=0; i<matrix.length;++i){
            for (int j=0;j<matrix[0].length;++j) {
                if (matrix[i][j] == '1') {
                    dp[i+1][j+1] = Math.min(Math.min(dp[i][j+1], dp[i+1][j]), dp[i][j])+1;
                    maxLen = Math.max(maxLen, dp[i+1][j+1]);
                }
            }
        }
        return maxLen * maxLen;
    }
}
__________________________________________________________________________________________________
