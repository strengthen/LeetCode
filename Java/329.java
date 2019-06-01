__________________________________________________________________________________________________
sample 6 ms submission
class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length;
        if(m == 0) return 0;
        int n = matrix[0].length;
        int[][] dp = new int[m][n];
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] == 0)
                ans = Math.max(ans,foo(matrix,dp,i,j,m,n));
            }
        }
        return ans;
    }
    
    private int foo(int[][] matrix,int[][] dp,int i,int j,int m, int n){
        if(dp[i][j]>0) return dp[i][j];
        int ans = 0;
        if(j-1>=0 && matrix[i][j-1] > matrix[i][j])
            ans = Math.max(ans,foo(matrix,dp,i,j-1,m,n));
        if(i-1>=0 && matrix[i-1][j] > matrix[i][j])
            ans = Math.max(ans,foo(matrix,dp,i-1,j,m,n));
        if(j+1<n && matrix[i][j+1] > matrix[i][j])
            ans = Math.max(ans,foo(matrix,dp,i,j+1,m,n));
        if(i+1<m && matrix[i+1][j] > matrix[i][j])
            ans = Math.max(ans,foo(matrix,dp,i+1,j,m,n));       
        
        dp[i][j] = 1 + ans;
        return dp[i][j];
    } 
}
__________________________________________________________________________________________________
sample 33680 kb submission
class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return 0;
        int ret = 1;
        int[][] length = new int[matrix.length][matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                ret = Math.max(ret, helper(matrix, length, i, j));
            }
        }
        return ret;
    }
    private int helper(int[][] matrix, int[][] length, int x, int y) {
        if (length[x][y] > 0) return length[x][y];
        int ret = 1;
        int[] dx = new int[] {1, 0, -1, 0};
        int[] dy = new int[] {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < matrix.length && ny >= 0 && ny < matrix[0].length && matrix[nx][ny] > matrix[x][y]) {
                ret = Math.max(ret, 1 + helper(matrix, length, nx, ny));
            }
        }
        length[x][y] = ret;
        return ret;
    }
}
__________________________________________________________________________________________________
