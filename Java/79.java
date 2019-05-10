__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    //space is O(L) where L is the length of the word; 
    //and time is O(M * N * 4^L) where M*N is the size of the board and we have 4^L for each cell because of the recursion. 
    //Of course this would be an upper bound. Not sure if it is good enough in an interview.
    public boolean exist(char[][] board, String word) {
        char[] words = word.toCharArray();
        for(int i=0; i<board.length; i++) {
            for(int j=0; j<board[0].length; j++) {
                if(checker(board, i, j, 0, words)) return true;
            }
        }
        return false;
    }
    
    public boolean checker(char[][] board, int i, int j, int index, char[] words) {
        if(index == words.length) return true;
        if(i < 0 || j < 0 || i >= board.length || j >= board[0].length) return false;
        if(board[i][j] != words[index]) return false;
        //board[i][j] ^= 256;
        board[i][j]='*';
        boolean res = checker(board, i+1, j, index+1, words)
            || checker(board, i-1, j, index+1, words)
            || checker(board, i, j+1, index+1, words)
            || checker(board, i, j-1, index+1, words);
        //board[i][j] ^= 256;
        board[i][j] = words[index];
        return res;
    }
}
__________________________________________________________________________________________________
sample 35632 kb submission
class Solution {
    public boolean exist(char[][] board, String word) {
        int row = board.length;
        if(row==0)
            return false;
        int column = board[0].length;
        boolean[][] visited = new boolean[row][column];
        boolean ans = false;
        for(int i=0;i<=row-1;i++){
            for(int j =0;j<=column-1;j++){
                ans = ans||helper(i, j, visited, board, word, 0);
            }
        }
        return ans;
    }
    
    private boolean helper(int i, int j, boolean[][] visited, char[][] board, String word, int pos){
        
        if(pos>word.length()-1)
            return true;
        if(i>board.length-1||j>board[0].length-1||i<0||j<0)
            return false;
        if(visited[i][j] == true)
            return false;
        if(board[i][j]!=word.charAt(pos))
            return false;
        
        
        visited[i][j] =true;
        boolean temp = helper(i+1,j,visited,board,word,pos+1)||helper(i-1,j,visited,board,word,pos+1)||helper(i,j+1,visited,board,word,pos+1)||helper(i,j-1,visited,board,word,pos+1);
        visited[i][j] = false;
        return temp;
    }
}
__________________________________________________________________________________________________
