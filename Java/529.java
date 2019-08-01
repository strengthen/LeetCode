__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    char[][] board;
    int[] d1 = {1, 0, -1, 0, 1, 1, -1, -1};
    int[] d2 = {0, 1, 0, -1, 1, -1, 1, -1};
    public void traverse(int r, int c, int R, int C) {
        int count = 0;
        for(int k = 0; k < 8; ++k){
            int nr = r + d1[k];
            int nc = c + d2[k];
            if(nr >= 0 && nr < R && nc >= 0 && nc < C && board[nr][nc] == 'M')
                count++;
        }
        if(count != 0)
            board[r][c] = (char) ('0' + count);
        else{
            board[r][c] = 'B';
            for(int k = 0; k < 8; ++k){
                int nr = r + d1[k];
                int nc = c + d2[k];
                if(nr >= 0 && nr < R && nc >= 0 && nc < C && board[nr][nc] == 'E')
                    traverse(nr, nc, R, C);
            }
        }
    }
    public char[][] updateBoard(char[][] board, int[] click) {
        this.board = board;
        int R = board.length;
        int C = board[0].length;
        int r = click[0];
        int c = click[1];
        if(board[r][c] == 'M')
            board[r][c] = 'X';
        else
            traverse(r, c, R, C);
        return board;
    }
}
__________________________________________________________________________________________________
sample 38488 kb submission
class Solution {
    public char[][] updateBoard(char[][] board, int[] click) {
        int m = board.length, n = board[0].length;
        int row = click[0], col = click[1];
        
        if (board[row][col] == 'M') { // Mine
            board[row][col] = 'X';
        }
        else { // Empty
            // Get number of mines first.
            int count = 0;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (i == 0 && j == 0) continue;
                    int r = row + i, c = col + j;
                    if (r < 0 || r >= m || c < 0 || c < 0 || c >= n) continue;
                    if (board[r][c] == 'M' || board[r][c] == 'X') count++;
                }
            }
            
            if (count > 0) { // If it is not a 'B', stop further DFS.
                board[row][col] = (char)(count + '0');
            }
            else { // Continue DFS to adjacent cells.
                board[row][col] = 'B';
                for (int i = -1; i < 2; i++) {
                    for (int j = -1; j < 2; j++) {
                        if (i == 0 && j == 0) continue;
                        int r = row + i, c = col + j;
                        if (r < 0 || r >= m || c < 0 || c < 0 || c >= n) continue;
                        if (board[r][c] == 'E') updateBoard(board, new int[] {r, c});
                    }
                }
            }
        }
        
        return board;
    }   
}
__________________________________________________________________________________________________
