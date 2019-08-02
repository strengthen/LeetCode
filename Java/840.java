__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public static int numMagicSquaresInside(int[][] grid) {
          if (grid == null || grid.length < 3 || grid[0].length < 3) 
              return 0;
          int R = grid.length, C = grid[0].length;
          int count = 0;
          for (int r = 0; r <= R - 3; ++r) {
              for (int c = 0; c <= C - 3; ++c) {
                  if (grid[r + 1][c + 1] == 5 && isMagic(grid, r, c)) {//middle element of magic grid will always be 5
                      count++;
                  }
              }
          }
          return count;
      }
  
      private static  boolean isMagic(int[][] grid, int r, int c) {
          int[] counts = new int[9];
          for (int i = 0; i < 3; ++i) {
              int rSum = 0, cSum = 0;
              for (int j = 0; j < 3; ++j) {
                  rSum += grid[r + i][c + j];
                  cSum += grid[r + j][c + i];
                  int t = grid[r + i][c + j];
                  if (t > 9 || t < 1 || counts[t - 1]++ > 0) 
                      return false;
              }
              if (rSum != 15 || cSum != 15) 
                  return false;
          }
          return true;
  	  }
}
__________________________________________________________________________________________________
sample 34508 kb submission
class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int height = grid.length;
        int length = grid[0].length;
        if (height < 3 || length < 3) {
            return 0;
        }

        int[][] rows = new int[height][length - 2];
        int[][] column = new int[height - 2][length];

        int[][] diagonals1 = new int[height - 2][length - 2];
        int[][] diagonals2 = new int[height - 2][length - 2];

        int result = 0;

        //build map
        for (int i = 0; i < height; i ++) {
            for (int j = 0; j < length; j++) {
                //for rows
                if (j < length - 2) {
                    rows[i][j] = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                }

                //for column
                if (i < height - 2) {
                    column[i][j] = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
                }

                //for diagonals
                if (j < length - 2 && i < height - 2) {
                    diagonals1[i][j] = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                    diagonals2[i][j] = grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];
                }

                if (j > 1 && i > 1) {
                    //check distinct
                    Set distinct = new HashSet();
                    distinct.add(grid[i][j]);
                    distinct.add(grid[i][j-1]);
                    distinct.add(grid[i][j-2]);
                    distinct.add(grid[i-1][j]);
                    distinct.add(grid[i-1][j-1]);
                    distinct.add(grid[i-1][j-2]);
                    distinct.add(grid[i-2][j]);
                    distinct.add(grid[i-2][j-1]);
                    distinct.add(grid[i-2][j-2]);
                    if (distinct.size() != 9) {
                        continue;
                    }
                    Object[] sort = distinct.stream().sorted(Comparator.naturalOrder()).toArray();
                    if ((int)sort[sort.length - 1] > 9 || (int)sort[0] < 1) {
                        continue;
                    }
                    //check row
                    if (rows[i][j-2] == rows[i - 1][j-2]
                        && rows[i - 1][j-2] == rows[i - 2][j-2]
                    ) {
                        //check column
                        if (
                            column[i-2][j] == column[i-2][j - 1]
                                && column[i-2][j - 1] == column[i-2][j - 2]
                                && rows[i][j-2] == column[i-2][j]
                        ) {
                            //check other
                            if (
                                diagonals1[i-2][j-2] == diagonals2[i-2][j-2]
                                    && diagonals1[i-2][j-2] == rows[i][j-2]
                            ) {
                                result ++;
                            }
                        }
                    }
                }
            }
        }

        return result;
    }
}
__________________________________________________________________________________________________
