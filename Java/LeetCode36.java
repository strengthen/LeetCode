__________________________________________________________________________________________________
1ms
class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            if (!isValidRow(board, i) || !isValidCol(board, i)) {
                return false;
            }
        }
        
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!isValidSubBox(board, i, j)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    public boolean isValidRow(char[][] board, int row) {
        boolean[] seenNums = new boolean[10];
        
        for (int i = 0; i < 9; i++) {
            char cellVal = board[row][i];
            if (cellVal != '.') {
                if (seenNums[cellVal - '0']) {
                    return false;
                }
                seenNums[cellVal - '0'] = true;
            }
        }
        
        return true;
    }
    
    public boolean isValidCol(char[][] board, int col) {
        boolean[] seenNums = new boolean[10];
        
        for (int i = 0; i < 9; i++) {
            char cellVal = board[i][col];
            if (cellVal != '.') {
                if (seenNums[cellVal - '0']) {
                    return false;
                }
                seenNums[cellVal - '0'] = true;
            }
        }
        
        return true;
    }
    
    public boolean isValidSubBox(char[][] board, int row, int col) {
        boolean[] seenNums = new boolean[10];
        
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                char cellVal = board[i][j];
                if (cellVal != '.') {
                    if (seenNums[cellVal - '0']) {
                        return false;
                    }
                    seenNums[cellVal - '0'] = true;
                }
            }
        }
        
        return true;
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[] digits = new int[10];
        for (char[] b: board) {
            digits = new int[10];
            for (char ch: b) {
                if (ch != '.')  {
                    if (ch < '0' || ch > '9' || digits[ch-'0'] > 0) return false;
                    digits[ch-'0']++;
                }
            }
        }
        
        for (int c = 0; c < 9; c++) {
            digits = new int[10];
            for (int r = 0; r < 9; r++) {
                if (board[r][c] != '.') {
                    if (board[r][c] < '0' || board[r][c] > '9' || digits[board[r][c]-'0'] > 0) return false;
                    digits[board[r][c]-'0']++;
                }
            }
        }
        
        for (int r = 0; r < 9; r+=3) {
            for (int c = 0; c < 9; c+=3) {
                digits = new int[10];
                for (int s1 = r; s1 < r+3; s1++) {
                    for (int s2 = c; s2 < c+3; s2++) {
                        if (board[s1][s2] != '.') {
                            if (board[s1][s2] < '0' || board[s1][s2] > '9' || digits[board[s1][s2]-'0'] > 0) return false;
                            digits[board[s1][s2]-'0']++;
                        }
                    }
                }
            } 
        }
        
        return true;
    }
}
__________________________________________________________________________________________________
3ms
class Solution {
    public boolean isValidSudoku(char[][] board) {
        
        Set<Character> set = null;
        Set<Character> set2 = null;
        Set<Character> set3 = null;
        
        for(int i = 0; i < 9; i++){
            set = new HashSet<>();
            set2 = new HashSet<>();
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && !set.add(board[i][j])){
                    return false;
                }
                if(board[j][i] != '.' && !set2.add(board[j][i])){
                   return false;
                }
            } 
        }
        
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                set3 = new HashSet<>();
                if(board[i][j] != '.' && !set3.add(board[i][j])){
                    return false;
                }
                if(board[i+1][j] != '.' && !set3.add(board[i+1][j])){
                    return false;
                }
                if(board[i+2][j] != '.' && !set3.add(board[i+2][j])){
                    return false;
                }
                if(board[i][j+1] != '.' && !set3.add(board[i][j+1])){
                    return false;
                }
                if(board[i+1][j+1] != '.' && !set3.add(board[i+1][j+1])){
                    return false;
                }
                if(board[i+2][j+1] != '.' && !set3.add(board[i+2][j+1])){
                    return false;
                }
                if(board[i][j+2] != '.' && !set3.add(board[i][j+2])){
                    return false;
                }
                if(board[i+1][j+2] != '.' && !set3.add(board[i+1][j+2])){
                    return false;
                }
                if(board[i+2][j+2] != '.' && !set3.add(board[i+2][j+2])){
                    return false;
                }
            } 
        } 
        
        return true;
        
    }
}
__________________________________________________________________________________________________
36820 kb
class Solution {
    public boolean isValidSudoku(char[][] board) {
        if(board == null || board.length != 9 || board[0].length != 9)
            return false;
        Set<String> setSeen = new HashSet<>();
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] != '.'){
                    if(!setSeen.add(new String(board[i][j] +"in row" + i))||
                      !setSeen.add(new String(board[i][j] +"in col" + j))||
                      !setSeen.add(new String(board[i][j] +"in cube" + i/3 + "and" +j/3))){
                          return false;
                      }
                }
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
37336 kb
class Solution {
    public boolean isValidSudoku(char[][] board) {
      Set seen = new HashSet();
      for (int i=0; i<9; ++i) {
          for (int j=0; j<9; ++j) {
              char number = board[i][j];
              if (number != '.')
                  if (!seen.add(number + " in row " + i) ||
                      !seen.add(number + " in column " + j) ||
                      !seen.add(number + " in block " + i/3 + "-" + j/3))
                      return false;
          }
      }
      return true;
    }

}
__________________________________________________________________________________________________