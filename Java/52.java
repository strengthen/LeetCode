__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    
    public int totalNQueens(int n) {
        int row[] = new int[n];
        int hill[] = new int[4*n-1];
        int dale[] = new int[2*n-1];
        return backtrack(0,0,n,row,hill,dale);
    }
    private boolean isValid(int n,int row,int col,int[] queen,int[] hill,int[] dale ){
        return queen[col] + hill[row-col+2*n] + dale[row+col] == 0;
        
    }
    
    private int backtrack(int row,int count,int n, int[] queen,int[] hill,int[] dale){
        for(int i=0;i<n;i++){
            if(isValid(n,row,i,queen,hill,dale)){
                queen[i]=1;
                hill[row-i+2*n]=1;
                dale[row+i]=1;
                
                if(row+1 == n) count++;
                else count = backtrack(row+1,count,n,queen,hill,dale);
                queen[i] =0;
                hill[row-i+2*n]=0;
                dale[row+i]=0;
            }
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 34504 kb submission
class Solution {
    public int totalNQueens(int n) {
        int[] count = new int[1];
        
        solve(n, new int[n], 0, count);
        
        return (count[0]);
    }
    
    private void solve (int n, int[] board, int row, int[] count) {
        if (row == n) {
            count[0]++;
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (!valid(board, row, col)) {
                continue;
            }
            board[row] = col;
            solve(n, board, row + 1, count);
        }
    }
    
    private boolean valid (int[] board, int row, int col) {
        for (int i = row - 1, j = 1; i >= 0; i--, j++) {
            if (board[i] == col) {
                return (false);
            }
            
            if (Math.abs(board[i] - col) == j) {
                return (false);
            }
        }
                
        return (true);
    }
}
__________________________________________________________________________________________________
