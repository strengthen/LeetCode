__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public void gameOfLife(int[][] board) {
        int M = board.length;
        int N = board[0].length;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(isLive(board,i,j)){
                    board[i][j] = board[i][j] | 2;
                } 
            }
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                board[i][j] = board[i][j] / 2;
            }
        }
        
    }
    public boolean isLive(int[][] board, int row, int col){
        int sum=0;
        int M = board.length;
        int N = board[0].length;
        
        for(int i=row-1;i<=row+1;i++){
            for(int j = col-1; j<=col+1; j++){
                if(i==row && j==col){
                    continue;
                }
                if(i>=0 && i<M && j>=0 && j<N){
                    if((board[i][j] & 1)==1){
                        sum++;
                    }
                }
            }
        }
        
        if((board[row][col] & 1) == 1){
            if(sum==2 || sum==3){
                return true;
            }
        } else{
            if(sum==3){
                return true;
            }
        }
        
        return false;
    }        
}
__________________________________________________________________________________________________
sample 34596 kb submission
class Solution {
    int ZERO_TO_ONE = 2;
    int ONE_TO_ZERO = 3;
    
    public void gameOfLife(int[][] board) {
        if (board == null || board.length == 0 ) return;
        
        int n = board.length;
        int m = board[0].length;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int c = getNeighbours(board, i, j);
                
                if ((board[i][j] == 1 && (c == 2 || c == 3)) || (board[i][j] == 0 && c != 3)) continue;
                
                if (board[i][j] == 1) {
                    board[i][j] = ONE_TO_ZERO;
                } else {
                    board[i][j] = ZERO_TO_ONE;
                }
            }    
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == ONE_TO_ZERO) {
                    board[i][j] = 0;
                } else if (board[i][j] == ZERO_TO_ONE) {
                    board[i][j] = 1;
                }
            }    
        }        
    }
    
    public int getNeighbours(int[][] board, int x, int y) {
        int n = board.length;
        int m = board[0].length;
        int res = 0;
        
        for (int i = -1; i < 2; i++) {
            if (x + i < 0 || x + i >= n) continue;
            for (int j = -1; j < 2; j++) {
                if (y + j < 0 || y + j >= m || (i == 0 && j == 0)) continue;
                
                if (board[x + i][y + j] == 1 || board[x + i][y + j] == ONE_TO_ZERO) res++;
            }    
        }
        
        return res;
    }        
}
__________________________________________________________________________________________________
