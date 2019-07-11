__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
   private int rows;
private int cols;
public int countBattleships(char[][] board) {
    rows = board.length;
    if (rows == 0) return 0;
    cols = board[0].length;

    int res = 0;
    for(int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (board[i][j] == 'X') {
          res++;
          if (i < rows - 1 && board[i + 1][j] == 'X') markBattleShip(board, i, j, true);
          else markBattleShip(board, i, j, false);
        }
      }
    }

    return res;
}

private void markBattleShip(char[][] board, int row, int col, boolean checkRow) {
  if (row >= rows || col >= cols || board[row][col] != 'X') return;
  
  board[row][col] = '.';

  if (checkRow) markBattleShip(board, row+1, col, checkRow);
  else markBattleShip(board, row, col + 1, checkRow);
}

}
__________________________________________________________________________________________________
sample 38252 kb submission
class Solution {
    public int countBattleships(char[][] board) {
        Map<String, Boolean> map = new HashMap<>();
        int count = 0;
        for(int i=0; i< board.length; i++){
            for(int j=0; j< board[0].length; j++){
                char c = board[i][j];
                if(c == 'X'){
                    String left = ""+i+"$"+(j-1);
                    String right = ""+i+"$"+(j+1);
                    String top = ""+(i-1)+"$"+j;
                    String bottom = ""+(i+1)+"$"+j;
                    
                    String curr = ""+i+"$"+j;
                    map.put(curr, true);
                    if(!map.containsKey(left) && !map.containsKey(right) && !map.containsKey(top) && !map.containsKey(bottom)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
}
__________________________________________________________________________________________________
