__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean validTicTacToe(String[] b) {
        char[][] board = new char[3][];
        for (int i = 0; i < 3; i++) {
            board[i] = b[i].toCharArray();
        }
        int o = 0, x = 0;
        int[] rows = new int[3];
        int[] cols = new int[3];
        int plus = 0, minus = 0;
        boolean finishX = false, finishO = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') {
                    x++;
                    rows[i]++;
                    cols[j]++;
                    if (i + j == 2) plus++;
                    if (i - j == 0) minus++;
                    if (rows[i] == 3 || cols[j] == 3 || plus == 3 || minus == 3) finishX = true;
                }
                else if (board[i][j] == 'O') {
                    o++;
                    rows[i]--;
                    cols[j]--;
                    if (i + j == 2) plus--;
                    if (i - j == 0) minus--;
                    if (rows[i] == -3 || cols[j] == -3 || plus == -3 || minus == -3) finishO = true;
                }
            }
        }
        // boolean finishX = isFinishedX(rows, cols, minus, plus), finishY = isFinishedO(rows, cols, minus, plus);
        // System.out.println()
        if (x - o == 0) {
            return !finishX;
        } else if (x - o == 1) {
            return !finishO;
        }
        return false;
    }
    
    private boolean isFinishedX(int[] rows, int[] cols, int minus, int plus) {
        for (int i = 0; i < 3; i++) {
            if (rows[i] == 3 || cols[i] == 3) return true;
        }
        return minus == 3 || plus == 3;
    }
    
    private boolean isFinishedO(int[] rows, int[] cols, int minus, int plus) {
        for (int i = 0; i < 3; i++) {
            if (rows[i] == -3 || cols[i] == -3) return true;
        }
        return minus == -3 || plus == -3;
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean validTicTacToe(String[] board) {
        int xcount = 0;
        int ocount = 0;
        for(String raw : board){
            char[]  c = raw.toCharArray();
            for(char cur : c){
                if(cur == 'X') 
                    xcount++;
                if(cur == 'O')
                    ocount++;
            }
        }
       
        
        if(ocount != xcount && ocount != xcount-1) {
            System.out.println(ocount != xcount-1);
          System.out.println(xcount);
            return false;
        }
        if(win(board, 'X') && win(board, 'O')) {
            System.out.println("1");
            return false;
        }
        if(win(board, 'X') && xcount != ocount+1) {
            System.out.println("2");
            return false;
        }
        if(win(board, 'O') && xcount != ocount) {
            System.out.println("3");
            return false;
        }
        return true;
        
        
    }
    public boolean win(String[] board, char P){
        for(int i=0; i<3; i++){
            if(board[i].charAt(0) == P && board[i].charAt(1) == P && board[i].charAt(2) == P)
                return true;
            if(board[0].charAt(i) == P && board[1].charAt(i) == P && board[2].charAt(i) == P)
                return true;
        }
        if(P == board[0].charAt(0) && P == board[1].charAt(1) && P == board[2].charAt(2))
            return true;
        if(P == board[0].charAt(2) && P == board[1].charAt(1) && P == board[2].charAt(0))
            return true;
        return false;
    }
}
__________________________________________________________________________________________________
sample 35188 kb submission
class Solution {
  
    public boolean validTicTacToe(String[] board) {
        int turns = 0;
        boolean xwin = false; 
        boolean owin = false;
        int[] rows = new int[3];
        int[] cols = new int[3];
        int diag = 0;
        int antidiag = 0;
				
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i].charAt(j) == 'X') {
                    turns++; rows[i]++; cols[j]++;
                    if (i == j) diag++;
                    if (i + j == 2) antidiag++;
                } else if (board[i].charAt(j) == 'O') {
                    turns--; rows[i]--; cols[j]--;
                    if (i == j) diag--;
                    if (i + j == 2) antidiag--;
                }
            }
        }
		
        xwin = rows[0] == 3 || rows[1] == 3 || rows[2] == 3 || 
               cols[0] == 3 || cols[1] == 3 || cols[2] == 3 || 
               diag == 3 || antidiag == 3;
        owin = rows[0] == -3 || rows[1] == -3 || rows[2] == -3 || 
               cols[0] == -3 || cols[1] == -3 || cols[2] == -3 || 
               diag == -3 || antidiag == -3;
        
        if (xwin && turns == 0 || owin && turns == 1) {
            return false;
        }
        return (turns == 0 || turns == 1) && (!xwin || !owin);
    }
   
}