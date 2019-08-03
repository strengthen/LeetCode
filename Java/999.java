__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int numRookCaptures(char[][] board) {
        int[] RIdx = new int[2];
        for(int i = 0; i < board.length; i++){
            for (int j = 0; j <board[0].length; j++){
                if(board[i][j] == 'R'){
                    RIdx[0] = i;
                    RIdx[1] = j;
                }
            }
        }
        int count = 0;
        int up = RIdx[1]-1, down = RIdx[1]+1, left = RIdx[0]-1, right = RIdx[0]+1;
        while(up >= 0){
            if(board[RIdx[0]][up] == 'B'){
                break;
            }else if(board[RIdx[0]][up] == 'p'){
                count += 1;
                break;
            }
            up -= 1;
        }
        while(down < board.length){
            if(board[RIdx[0]][down] == 'B'){
                break;
            }else  if(board[RIdx[0]][down] == 'p'){
                count += 1;
                break;
            }
            down += 1;
        }
        while(left >= 0){
            if(board[left][RIdx[1]] == 'B'){
                break;
            }else if(board[left][RIdx[1]] == 'p'){
                count += 1;
                break;
            }
            left -= 1;
        }
        while(right < board[0].length){
            if(board[right][RIdx[1]] == 'B'){
                break;
            }else  if(board[right][RIdx[1]] == 'p'){
                count += 1;
                break;
            }
            right += 1;
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 35248 kb submission
class Solution {
    public int numRookCaptures(char[][] board) {
        int row = 0;
        int col = 0;
        int n = board.length;
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'R'){
                    row = i;
                    col = j;
                }
            }
        }
        for(int j = col - 1; j >= 0; j--){
            if(board[row][j] == 'B') break;
            if(board[row][j] == 'p'){
                count++;
                break;
            }
        }
        for(int j = col + 1; j < n; j++){
            if(board[row][j] == 'B') break;
            if(board[row][j] == 'p'){
                count++;
                break;
            }
        }
        for(int i = row - 1; i >= 0; i--){
            if(board[i][col] == 'B') break;
            if(board[i][col] == 'p'){
                count++;
                break;
            }
        }
        for(int i = row + 1; i < n; i++){
            if(board[i][col] == 'B') break;
            if(board[i][col] == 'p'){
                count++;
                break;
            }
        }
        return count;
    }
}
__________________________________________________________________________________________________
