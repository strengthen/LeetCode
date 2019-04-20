__________________________________________________________________________________________________
0ms
class Solution {
    int rowmasks[] = new int[9];
    int colmasks[] = new int[9];
    int boxmasks[][] = new int[3][3];
    int moves[] = new int[9 * 9];
    int undolevel = 0;

    void analyze(char[][] board) {
        for (int i = 0; i < 9; i++) {
            rowmasks[i] = colmasks[i] = boxmasks[i/3][i%3] = 0x1ff;
        }
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if (ch != '.') {
                    mask(r, c, ch);
                }
            }
        }
    }

    void mask(int row, int col, int bit) {
        int notbit = ~bit;
        rowmasks[row] &= notbit;
        colmasks[col] &= notbit;
        boxmasks[row/3][col/3] &= notbit;
    }

    void mask(int row, int col, char ch) {
        mask(row, col, 1 << (ch - '1'));
    }

    void claim(char board[][], int row, int col, int bit) {
        mask(row, col, bit);
        char ch = '1';
        while ((bit >>= 1) != 0) {
            ch++;
        }
        board[row][col] = ch;
        moves[undolevel++] = row * 9 + col;
    }

    void undo(char board[][], int prevlevel) {
        while (undolevel > prevlevel) {
            int index = moves[--undolevel];
            int row = index / 9;
            int col = index - row * 9;
            int bit = 1 << (board[row][col] - '1');
            board[row][col] = '.';
            rowmasks[row] |= bit;
            colmasks[col] |= bit;
            boxmasks[row/3][col/3] |= bit;
        }
    }

    public void solveSudoku(char[][] board) {
        analyze(board);
        trySolve(board, 0, 0);
    }

    boolean trySolve(char[][] board, int row, int nextcol) {
        while (true) {
            boolean foundone = false;
            int col = nextcol;
            for (int r = row; r < 9; r++) {
                for (int c = col; c < 9; c++) {
                    if (board[r][c] == '.') {
                        int possbits = rowmasks[r] & colmasks[c] & boxmasks[r/3][c/3];
                        if (possbits == 0) {
                            return false;
                        }
                        int rembits = possbits & (possbits - 1);
                        if (rembits == 0) {
                            claim(board, r, c, possbits);
                            foundone = true;
                        }
                    }
                }
                col = 0;
            }
            if (foundone) continue;
            col = nextcol;
            for (int r = row; r < 9; r++) {
                for (int c = col; c < 9; c++) {
                    if (board[r][c] == '.') {
                        int possbits = rowmasks[r] & colmasks[c] & boxmasks[r/3][c/3];
                        while (possbits != 0) {
                            int rembits = possbits & (possbits - 1);
                            int bit = possbits - rembits;
                            possbits = rembits;
                            int prevundo = undolevel;
                            claim(board, r, c, bit);
                            if (trySolve(board, row, col+1)) {
                                return true;
                            }
                            undo(board, prevundo);
                        }
                        return false;
                    }
                }
                col = 0;
            }
            return true;
        }
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    boolean[][][] possibilities;
    int[][] possibleCounts;
    char[][] thisBoard;

    public void solveSudoku(char[][] board) {
        possibilities = new boolean[9][9][9];
        possibleCounts = new int[9][9];
        thisBoard = board;
        populateAll();
        fillLogically();
        dewIt();
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                board[i][j] = thisBoard[i][j];
            }
        }
    }

    boolean dewIt() {
        int minCount = 10, x = 0, y = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (possibleCounts[i][j] == 0 && thisBoard[i][j] == '.')
                    return false;
                if (possibleCounts[i][j] != 0 && possibleCounts[i][j] < minCount) {
                    minCount = possibleCounts[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        if (minCount == 10)
            return true;

        boolean[][][] possibilitiesSnapshot = boolClone(possibilities);
        int[][] countsSnapshot = intClone(possibleCounts);
        char[][] thisBoardSnapshot = charClone(thisBoard);

        for (int k = 0; k < 9; ++k) {
            if (possibilities[x][y][k]) {
                updateCell(x, y, k);
                fillLogically();
                boolean isPossible = dewIt();
                if (isPossible)
                    return true;
                else {
                    possibilities = possibilitiesSnapshot;
                    possibleCounts = countsSnapshot;
                    thisBoard = thisBoardSnapshot;
                }
            }
        }
        return false;
    }

    void fillLogically() {
        int x = 10, y = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (possibleCounts[i][j] == 1) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        if (x != 10) {
            int val = 0;
            for (int k = 0; k < 9; ++k) {
                if (possibilities[x][y][k]) {
                    val = k;
                    break;
                }
            }
            updateCell(x, y, val);
            fillLogically();
            return;
        }
        for (int i = 0; i < 9; ++i) {
            for (int k = 0; k < 9; ++k) {
                int count = 0;
                for (int j = 0; j < 9; ++j) {
                    if (possibilities[i][j][k]) ++count;
                }
                if (count == 1) {
                    for (int j = 0; j < 9; ++j) {
                        if (possibilities[i][j][k]) {
                            updateCell(i, j, k);
                            fillLogically();
                            return;
                        }
                    }
                }
            }
        }
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 9; ++k) {
                int count = 0;
                for (int i = 0; i < 9; ++i) {
                    if (possibilities[i][j][k]) ++count;
                }
                if (count == 1) {
                    for (int i = 0; i < 9; ++i) {
                        if (possibilities[i][j][k]) {
                            updateCell(i, j, k);
                            fillLogically();
                            return;
                        }
                    }
                }
            }
        }
        for (int a = 0; a < 9; ++a) {
            for (int k = 0; k < 9; ++k) {
                int count = 0;
                for (int b = 0; b < 9; ++b) {
                    int i = 3 * (a % 3) + b % 3, j = 3 * (a / 3) + b / 3;
                    if (possibilities[i][j][k]) ++count;
                }
                if (count == 1) {
                    for (int b = 0; b < 9; ++b) {
                        int i = 3 * (a % 3) + b % 3, j = 3 * (a / 3) + b / 3;
                        if (possibilities[i][j][k]) {
                            updateCell(i, j, k);
                            fillLogically();
                            return;
                        }
                    }
                }
            }
        }
    }

    void populateAll() {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                possibleCounts[i][j] = 9;
                for (int k = 0; k < 9; ++k) possibilities[i][j][k] = true;
            }
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (thisBoard[i][j] != '.') {
                    updateCell(i, j, thisBoard[i][j] - '1');
                }
            }
        }
    }

    void updateCell(int x, int y, int val) {
        thisBoard[x][y] = (char) (val + '1');
        possibleCounts[x][y] = 0;
        for (int k = 0; k < 9; ++k) possibilities[x][y][k] = false;
        for (int k = 0; k < 9; ++k) {
            if (possibilities[k][y][val]) {
                possibilities[k][y][val] = false;
                --possibleCounts[k][y];
            }
        }
        for (int k = 0; k < 9; ++k) {
            if (possibilities[x][k][val]) {
                possibilities[x][k][val] = false;
                --possibleCounts[x][k];
            }
        }
        for (int k = 0; k < 9; ++k) {
            if (possibilities[3 * (x / 3) + k / 3][3 * (y / 3) + k % 3][val]) {
                possibilities[3 * (x / 3) + k / 3][3 * (y / 3) + k % 3][val] = false;
                --possibleCounts[3 * (x / 3) + k / 3][3 * (y / 3) + k % 3];
            }
        }
    }

    boolean[][][] boolClone(boolean[][][] b) {
        boolean[][][] a = new boolean[9][9][9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                for (int k = 0; k < 9; ++k) {
                    a[i][j][k] = b[i][j][k];
                }
            }
        }
        return a;
    }

    char[][] charClone(char[][] b) {
        char[][] a = new char[9][9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                a[i][j] = b[i][j];
            }
        }
        return a;
    }

    int[][] intClone(int[][] b) {
        int[][] a = new int[9][9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                a[i][j] = b[i][j];
            }
        }
        return a;

    }
}
__________________________________________________________________________________________________
3ms
class Solution {
    public void solveSudoku(char[][] board) {
        int[][] rows = new int[9][10];
        int[][] columns = new int[9][10];
        int[][] quadrants = new int[9][10];
        populate(board, rows, columns, quadrants);
        solve(board, 0, 0, rows, columns, quadrants);
    }
    
    private boolean solve(char[][] board, int row, int column, int[][] rows, int[][] columns, int[][] quadrants) {
        if (row > 8) return true;
        
        int[] next = next(row, column);
        if (board[row][column] != '.') {
            
            return solve(board, next[0], next[1], rows, columns, quadrants);
        } else {
            for (int i = 1; i < 10; i++) {
                if (!(rows[row][i] == 1 || columns[column][i] == 1 || quadrants[quadrant(row, column)][i] == 1)) {
                    rows[row][i] = 1;
                    columns[column][i] = 1;
                    quadrants[quadrant(row, column)][i] = 1;
                    board[row][column] = (char) (i + '0');
                    if (solve(board, next[0], next[1], rows, columns, quadrants)) return true;
                    board[row][column] = '.';
                    rows[row][i] = 0;
                    columns[column][i] = 0;
                    quadrants[quadrant(row, column)][i] = 0;
                }
            }
            return false;
        }
        
    }
    
    private int[] next(int row, int column) {
        if (column == 8) return new int[] {row + 1, 0};
        return new int[] {row, column + 1};
    }
    
    private void populate(char[][] board, int[][] rows, int[][] columns, int[][] quadrants) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] != '.') {
                    int number = board[i][j] - '0';
                    rows[i][number] = 1;
                    columns[j][number] = 1;
                    quadrants[quadrant(i, j)][number] = 1;
                }
            }
        }
    }
    
    private int quadrant(int row, int column) {
        return row / 3 * 3 + column / 3;
    }
}
__________________________________________________________________________________________________
34536 kb
class Solution {
    
    public void solveSudoku(char[][] board) {
       
        sudokuSolverHelper(board);
    }
    
  private static boolean sudokuSolverHelper(char[][] board)
  {
          
    // step1. findEmptySpot
    int r;
    int c;
    int[] spot = findEmptySpot(board);
    r = spot[0];
    c = spot[1];
    
    if(r == -1){
      return true;
    }
    
     // step2. for 1 to 9 
     for(int i = 1; i <= 9; i++)
     {
       char value = (char)(i+'0');
         
       // step2.1 check isValidPlacement 
       boolean isInRow = usedInRow(board,r, value);      
       boolean isInCol = usedInCol(board,c, value);
       boolean isInBox = usedInBox(board,r, c, value);
       if(!isInRow && !isInCol && !isInBox)
       {
         
          board[r][c] = value; 
          
         // step2.2  sudokuSolve(board)        
          if(sudokuSolverHelper(board))
          {
            return true;
          }
          board[r][c] = '.';
       }         
     }
    
    // step3:
    return false;
  }
  
  private static boolean usedInRow(char[][] board, int r, char value)
  {        
       for(int i = 0; i < 9; i++)
       {
           // column valid
               if(board[r][i] == value)
               {
                  return true;
               }             
      }
    
    return false;
  }
  
  private static boolean usedInCol(char[][] board,int c, char value)
  {    
    
       for(int i = 0; i < 9; i++)
       {
           // column valid
               if(board[i][c] == value)
               {
                  return true;
               }             
      }
    
    return false;
  }
  
  private static boolean usedInBox(char[][] board, int r, int c, char value)
  {
       
     for(int i=0; i < 3; i++)
     {
        for(int j=0; j < 3; j++)
        {
           char curr = board[i+ (r - r%3)][j + (c - c%3)];
           
           if(curr == value)
           {
              return true;
           }
        }
     }
    return false;
  }
  
  private static int[] findEmptySpot(char[][] board)
  {
      int[] cell = new int[2];
    
       for(int i = 0; i < 9; i++)
       {
           for(int j = 0; j < 9; j++)
           {
               if(board[i][j] == '.')
               {
                 
                  cell[0] = i;
                  cell[1] = j;
                  return cell;
               }
           }
       }
      cell[0] = -1;
      cell[1] = -1;
     
     return cell;
  }
}
__________________________________________________________________________________________________
34612 kb
public class Solution {
    public void solveSudoku(char[][] board) {
        if (board == null || board.length == 0)
            return;
        solve(board);
    }

    public static boolean solve(char[][] board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char c = '1'; c <= '9'; c++) { // trial. Try 1 through 9
                        if (isValid(board, row, col, c)) {
                            board[row][col] = c; // Put c for this cell

                            if (solve(board)) return true; // If it's the solution return true
                            else board[row][col] = '.'; // Otherwise go back
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }

    private static boolean isValid(char[][] board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) return false; // check row
            if (board[row][i] == c) return false; // check column
            int _3x3_row = 3 * (row / 3) + i / 3;
            int _3x3_col = 3 * (col / 3) + i % 3;
            if (board[_3x3_row][_3x3_col] == c) return false; //check 3*3 block
        }
        return true;
    }
}
__________________________________________________________________________________________________