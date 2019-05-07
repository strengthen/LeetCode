__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public List<List<String>> solveNQueens(int n) {
        // first generate a board filled with '.'
        char[][] board = new char[n][n];
        for (char[] line : board) {
            Arrays.fill(line, '.');
        }
        List<List<String>> solutions = new ArrayList<List<String>>();
        dfs(0, n, new boolean[2 * n], new boolean[2 * n - 1], new boolean[2 * n - 1], solutions, board);
        return solutions;
        
    }
    
    private void dfs(int row, int n, boolean[] cols, boolean[] diag1, boolean[] diag2,
                    List<List<String>> solutions, char[][] board) {
        if (row == n) {
            // convert the board to List<String> and add to answer set
            List<String> res = new ArrayList<String>();
            for (char[] line : board) {
                res.add(String.valueOf(line));
            }
            solutions.add(res);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (cols[i] || diag1[row - i + n - 1] || diag2[i + row]) continue;
            board[row][i] = 'Q';
            cols[i] = true;
            diag1[row - i + n - 1] = true;
            diag2[i + row] = true;
            dfs(row + 1, n, cols, diag1, diag2, solutions, board);
            cols[i] = false;
            diag1[row - i + n - 1] = false;
            diag2[i + row] = false;
            board[row][i] = '.';
        }
    }    
}
__________________________________________________________________________________________________
sample 37472 kb submission
class Solution {
    
    public List<List<String>> solveNQueens(int n) {
        int[] rows = new int[n];
        List<List<String>> solutions = new ArrayList<>();
        solve(rows, solutions, 0);
        return solutions;
    }
    
    private void solve(int[] rows, List<List<String>> solutions, int cur) {
        if (cur == rows.length) {
            solutions.add(encode(rows));
            return;
        }

        for (int i = 0; i < rows.length; i++) {
            boolean good = true;
            for (int j = 0; j < cur; j++) {
                if (rows[j] == i) {
                    good = false;
                    break;
                }
                int d = cur - j;
                if (rows[j] == i + d || rows[j] == i - d) {
                    good = false;
                    break;
                }
            }
            if (good) {
              rows[cur] = i;
              solve(rows, solutions, cur + 1);
            }
        }
    }
    
    private List<String> encode(int[] rows) {
        List<String> output = new ArrayList<>();
        for (int row : rows) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < rows.length; i++) {
                sb.append(i == row ? 'Q' : '.');
            }
            output.add(sb.toString());
        }
        return output;
    }
}
__________________________________________________________________________________________________
