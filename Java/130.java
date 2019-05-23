__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public void solve(char[][] board) {
        if (board == null || board.length == 0 || board[0].length==0) return;
        int m = board.length;
        int n = board[0].length;
        for (int j=0; j<n; ++j) {
            if (board[0][j] == 'O')
                dfs(board, 0, j, m, n);
            if (board[m-1][j] == 'O')
                dfs(board, m-1, j, m, n);
        }
        
        for (int i=0; i<m; ++i) {
            if (board[i][0] == 'O') 
                dfs(board, i, 0, m, n);
            if (board[i][n-1] == 'O')
                dfs(board, i, n-1, m, n);
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(char[][] board, int i, int j, int m, int n) {
        if (i <0 || j<0 || i>=m || j>=n || board[i][j] != 'O') return;
        board[i][j] = '#';
        dfs(board, i-1, j, m, n);
        dfs(board, i+1, j, m, n);
        dfs(board, i, j-1, m, n);
        dfs(board, i, j+1, m, n);
    }
}
__________________________________________________________________________________________________
sample 36288 kb submission
class Solution {
    public class Coord{
        int x;
        int y;
        public Coord(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public void solve(char[][] board) {
        if (board.length == 0 ) {return;}
        Deque<Coord> edges = new ArrayDeque<>();
        for(int i = 1; i < board[0].length-1;i++) {
            if(board[0][i] == 'O'){
                edges.add(new Coord(0, i));
            }
            if(board[board.length-1][i]=='O') {
                edges.add(new Coord(board.length-1, i));
            }
        }
        for(int i = 1; i < board.length-1;i++) {
            if(board[i][0] == 'O'){
                edges.add(new Coord(i, 0));
            }
            if(board[i][board[0].length-1]=='O') {
                edges.add(new Coord(i, board[0].length-1));
            }
        }
        while(!edges.isEmpty()) {
            Coord entry = edges.remove();
            List<Coord> surrounding = new ArrayList<>();
            surrounding.add(new Coord(entry.x -1, entry.y));
            surrounding.add(new Coord(entry.x +1, entry.y));
            surrounding.add(new Coord(entry.x, entry.y-1));
            surrounding.add(new Coord(entry.x, entry.y+1));
            for(Coord c: surrounding) {
                if(c.x >0 && c.x < board.length-1 && c.y>0 && c.y<board[0].length-1) {
                    if(board[c.x][c.y]=='O') {
                        board[c.x][c.y] = 'M';
                        edges.add(c);
                    }
                }
            }
        }
        for(int i = 1; i < board.length-1; i++){
            for(int j = 1; j < board[0].length-1;j++) {
                if(board[i][j] == 'M') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
}
__________________________________________________________________________________________________
