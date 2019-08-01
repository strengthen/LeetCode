__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public double[][][] dp;
    public final int[][] spread = new int[][]{{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    int N;
    public double knightProbability(int N, int K, int r, int c) {
        this.N = N;
        int half = (N+1)/2;
        dp = new double[half][half][K+1];
        return dpSolution(r,c,K);
    }
    public double dpSolution(int r, int c, int K){
        if(r<0||c<0||r>N-1||c>N-1) return 0d;
        if(K==0) return 1d; //still on board, even after all steps!
        if(r>N-1-r) r=N-1-r; //dont cross n+1/2
        if(c>N-1-c) c=N-1-c; //"
        if(dp[r][c][K]!=0) return dp[r][c][K]; //visited
        
        double prob=0d; //calculate prob
        for(int[] d:spread){
            prob+=0.125*dpSolution(r+d[0],c+d[1],K-1);
        }
        dp[r][c][K]=prob;
        return prob;
    }
}
__________________________________________________________________________________________________
sample 32032 kb submission
class Solution {
  
  int[][] moves = new int[][] {
    {-2, -1}, {-2, 1},
    {-1, -2}, {-1, 2},
    { 1, -2}, { 1, 2},
    { 2, -1}, { 2, 1},
  };

  public double knightProbability(int N, int K, int r, int c) {
    double[][] prev = new double[N][N];
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        prev[i][j] = 1.0;
      }
    }
    
    double[][] curr = new double[N][N];

    while(K-- > 0) {
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) {
        double p = 0.0;
        for(int[] move: moves) {
          p += 0.125 * prob(prev, i + move[0], j + move[1]);
        }
        curr[i][j] = p;
      }
      double[][] swap = curr;
      curr = prev;
      prev = swap;
    }
    return prev[r][c];
  }
  
  double prob(double[][] board, int i, int j) {
    if (i < 0 || board.length <= i || j < 0 || board.length <= j) {
      return 0.0;
    }
    return board[i][j];
  }
}
__________________________________________________________________________________________________
