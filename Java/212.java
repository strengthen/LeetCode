__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    public static List<String> findWords(char[][] board, String[] words) {
        List<String> ans = new LinkedList<>();
        TrieNode root = new TrieNode();
        for (String word: words) insert(word, root);
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                findWords(board, root, i, j, ans);
            }
        }
        return ans;
    }
    
    private static void findWords(char[][] board, TrieNode root, int i, int j, List<String> list) {
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length) return;
        
        char ch = board[i][j];
        int index = ch - 'a';
        if (ch == '.' || root.children[index] == null) return;
        
        root = root.children[index];
        if (root.word != null) {
            list.add(root.word);
            root.word = null;
        }
        
        board[i][j] = '.';
        findWords(board, root, i + 1, j, list);
        findWords(board, root, i - 1, j, list);
        findWords(board, root, i, j + 1, list);
        findWords(board, root, i, j - 1, list);
        board[i][j] = ch;
    }
    
    private static void insert(String word, TrieNode root) {
        for (char ch: word.toCharArray()) {
            int index = ch - 'a';
            if (root.children[index] == null) root.children[index] = new TrieNode();
            root = root.children[index];
        }
        root.word = word;
    }
    
    private static class TrieNode {
        String word;
        TrieNode[] children = new TrieNode[26];
    }
}
__________________________________________________________________________________________________
sample 38908 kb submission
class Solution {
    private int w;
    private int h;
    
    public List<String> findWords(char[][]board, String[] words) {
        List<String> ans = new ArrayList<>();
        for (String s: words) if (exist(board, s) && !ans.contains(s)) ans.add(s);
        return ans;
    }
    
    private boolean exist(char[][] board, String word) {
        if (board.length == 0) return false;
        this.h = board.length;
        this.w = board[0].length;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (bst(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
    private boolean bst(char[][] board, int i, int j, String word, int length) {
        // case 1 out of bound
        if (i < 0 || i >= h || j < 0 || j >= w) return false;
        // case 2 don't match
        if (board[i][j] != word.charAt(length)) return false;
        // case 3 end of string (char matches and is the last index)
        if (length == word.length() - 1) return true;
        char curr = board[i][j];
        board[i][j] = 0; //marked as visted
        // try four directions
        boolean temp = bst(board, i - 1, j, word, length + 1)
            || bst(board, i + 1, j, word, length + 1)
            || bst(board, i, j - 1, word, length + 1)
            || bst(board, i, j + 1, word, length + 1);
        board[i][j] = curr;
        return temp;
    }
}
__________________________________________________________________________________________________
