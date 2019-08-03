__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int numEnclaves(int[][] A) {
        int result = 0;
        for(int i = 0; i < A.length; i++){
            dfs(A,i,0);
            dfs(A,i,A[0].length-1);
        } 
        for(int j = 0; j < A[0].length; j++) {
            dfs(A,0,j);
            dfs(A,A.length-1,j);
        }
        
        for(int i = 0; i < A.length; i++) 
            for(int j = 0; j < A[i].length; j++) 
                    result+=A[i][j];
        
        return result;
    }
    
    public void dfs(int a[][], int i, int j) {
        if(i >= 0 && i <= a.length - 1 && j >= 0 && j <= a[i].length - 1 && a[i][j] == 1) {
            a[i][j] = 0;
            dfs(a, i + 1, j);
            dfs(a, i - 1, j);
            dfs(a, i, j + 1);
            dfs(a, i, j - 1);
        }
    }
}
__________________________________________________________________________________________________
sample 46468 kb submission
class Solution {
    private int[][] dirs = new int[][]{{0,1},{0,-1},{1,0},{-1,0}};
    private void dfs(int[][] A,int i,int j){
        if(i < 0 || i >= A.length || j < 0 || j >=A[0].length) return;
        if(A[i][j] == 0) return;

        A[i][j] = 0;
        for(int[] d : dirs){
            dfs(A,i + d[0],j + d[1]);
        }
    }

    public int numEnclaves(int[][] A) {
        for (int i = 0; i < A.length; i++) {
            dfs(A,i,0);
            dfs(A,i,A[0].length - 1);
        }

        for (int i = 0; i < A[0].length; i++) {
            dfs(A,0,i);
            dfs(A,A.length - 1,i);
        }

        int ones = 0;
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[0].length; j++) {
                if(A[i][j] == 1) ones++;
            }

        }
        return ones;
    }
}
__________________________________________________________________________________________________
