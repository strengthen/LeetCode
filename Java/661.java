__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int[][] imageSmoother(int[][] M) {
        int[][] smooth = new int[M.length][M[0].length];
        
        for(int i =0; i < M.length; i++){
            for(int j=0; j < M[i].length; j++){
                smooth[i][j] = getAvg( M, i, j);
            }
        }
        return smooth;
    }
    
    private int getAvg(int[][] M, int i, int j){
        int total = 0;
        int smooth =0;
        for(int x = -1; x < 2; x++){
            for(int y=-1; y < 2; y++){
                if(x + i >= 0 && x+i < M.length 
                    && y+j >=0 && y+j < M[i].length){
                    smooth += M[i+x][j+y];
                    total++;
                }
            }
        }
        return smooth /= total;
    }
}
__________________________________________________________________________________________________
sample 39808 kb submission
class Solution {
    public int[][] imageSmoother(int[][] M) {
        if (M == null || M.length == 0 || M[0].length == 0) {
            return null;
        }
        int m = M.length;
        int n = M[0].length;
        int[][] ans = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = helper(i, j, M, m, n);
            }
        }
        return ans;
    }
    
    private int helper(int i, int j, int[][] M, int m, int n) {
        int sum = 0;
        int count = 0;
        for (int k = -1; k < 2; k++) {
            for (int l = -1; l < 2; l++) {
                if (i + k > -1 && i + k < m && j + l > -1 && j + l < n) {
                    //System.out.println(
                    sum += M[i + k][j + l];
                    count++;
                }
            }
        }
       // System.out.println(sum + " " + count);
        return sum/count;
    }
}
__________________________________________________________________________________________________
