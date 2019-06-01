__________________________________________________________________________________________________
sample 54 ms submission
class NumMatrix {
  long[][] sums;
  public NumMatrix(int[][] matrix) {
    if (matrix.length == 0 || matrix[0].length == 0) {
      return;
    }
    sums = new long[matrix.length + 1][matrix[0].length + 1];
    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix[0].length; j++) {
        sums[i + 1][j + 1] = (long) matrix[i][j] + sums[i][j + 1] + sums[i + 1][j] - sums[i][j];
      }
    }
  }

  public int sumRegion(int row1, int col1, int row2, int col2) {
    // if (sums == null) {
    //   return 0;
    // }
    return (int) (sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1]);
  }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
__________________________________________________________________________________________________
sample 42368 kb submission
class NumMatrix {
    private int[][] dp;
    public NumMatrix(int[][] matrix) {
        int m = matrix.length;
        if(m == 0){
            return;
        }
        int n = matrix[0].length;
        dp = new int[m+1][n+1];
       
        for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] -dp[i - 1][j - 1] + matrix[i - 1][j - 1] ;
        }
    }
        
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        int iMin = Math.min(row1, row2);
    int iMax = Math.max(row1, row2);
    
    int jMin = Math.min(col1, col2);
    int jMax = Math.max(col1, col2);
    
    return dp[iMax + 1][jMax + 1] - dp[iMax + 1][jMin] - dp[iMin][jMax + 1] + dp[iMin][jMin];    
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
__________________________________________________________________________________________________
