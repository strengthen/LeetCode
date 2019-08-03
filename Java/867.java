__________________________________________________________________________________________________
Runtime: 0 ms
Memory Usage: 38.4 MB
class Solution {
    public int[][] transpose(int[][] A) {
        int b1=A[0].length;
        int b2=A.length;
        int[][] B=new int[b1][b2];
        for(int i=0;i<b1;i++){
            for(int j=0;j<b2;j++){
                B[i][j]=A[j][i];
            }
        }
        return B;
    }
}
__________________________________________________________________________________________________
sample 39064 kb submission
class Solution {
    public int[][] transpose(int[][] A) {
        int i=0;
        int j=0;
        int rowscount=A.length;
        int columncount=A[0].length;
        int[][] newmatrix= new int[columncount][rowscount];
          System.out.println(rowscount+""+columncount);
        
        for(i=0;i<A.length;i++){
          for(j=0;j<A[i].length;j++){
            newmatrix[j][i]=A[i][j];               
          }            
        }
        return newmatrix;
        
    }
}
__________________________________________________________________________________________________
