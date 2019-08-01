__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        if(matrix == null || matrix.length == 0)
            return matrix;
        int rows = matrix.length;
        int cols = matrix[0].length;
        int [][] output = new int [rows][cols];
        for(int row = 0; row < rows; row++){
            for(int col =0; col < cols; col++){
                if(matrix[row][col] == 1){
                    output[row][col] =  dfs(matrix,row,col,output);
                }
            }
        }
        return output;
    }
    private int dfs(int [][] matrix , int row, int col,int [][] output){
        if(row < 0 || col < 0 || row >= matrix.length || col >= matrix[0].length)
            return Integer.MAX_VALUE;
        if(matrix[row][col] == 0)
            return 1;

        
        // Case 1 Find 0 on top
         if(row > 0 && matrix[row-1][col] == 0) return 1;
         // Case 2 Find 0 on right
         if(col < matrix[0].length-1 && matrix[row][col+1] == 0) return 1;
         // Case 3 Find 0 on bottom
         if(row < matrix.length-1 && matrix[row+1][col] == 0) return 1;
        // Case 4 Find 0 on left
          if(col>0 && matrix[row][col-1] == 0) return 1;
              
        int left,bottom,right,top;
        left=top=9999;
        // if recursive call
        if(row > 0 && output[row-1][col] != 0){
            top = output[row-1][col];
        }
        if(col> 0 && output[row][col-1] != 0){
            left = output[row][col-1];
        }
        bottom = dfs(matrix,row+1, col,output);
        right = dfs(matrix,row,col+1,output);
        int finalMin = Math.min(Math.min(left, right), Math.min(top,bottom))+1;
        return finalMin;
    }
}
__________________________________________________________________________________________________
sample 43016 kb submission
class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        if (matrix== null ||matrix.length == 0)
            return matrix;
        int m = matrix.length;
        int n = matrix[0].length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> Integer.compare(a[2],b[2]));
        int[][] res = new int[m][n];
        for(int i =0; i <m;i++){
            for(int j =0; j <n;j++){
                if (matrix[i][j] == 1){
                    res[i][j] = Integer.MAX_VALUE;
                }else{
                    pq.offer(new int[]{i,j,0});
                }
            }
        }
        
        int[][] dir = {{-1,0},{1,0},{0,1},{0,-1}};
        while(!pq.isEmpty()){
            int[] top = pq.poll();
            int r = top[0];
            int c = top[1];
            int v = top[2];
            for(int[] arr:dir){
                int nr = r+arr[0];
                int nc = c+arr[1];
                if (nr < 0 || nr >= matrix.length || nc < 0 || nc >= matrix[0].length)
                    continue;
                if (v +1 < res[nr][nc]){
                    res[nr][nc] = 1+v;
                    pq.offer(new int[]{nr,nc,1+v});
                }
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
