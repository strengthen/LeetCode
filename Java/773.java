__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int slidingPuzzle(int[][] board) {
         if (noSolution(board)) return -1;
        int target = 42792;                   // 123450 = 001 010 011 100 101 000 -> 42792
        boolean[] hash = new boolean[181897]; // 543210 = 101 100 011 010 001 000 -> 181896
        int start = 0;
        for (int[] line : board) {
            for (int c : line) {
                start = (start << 3) | c;
            }
        }
        if (start == target) return 0;

        int[][] move = new int[][] { { 1, 3 }, { 0, 2, 4 }, { 1, 5 }, { 0, 4 }, { 3, 1, 5 }, { 4, 2 } };

        List<Integer> now = new ArrayList<>();
        now.add(start);
        hash[start] = true;
        int step = 1;
        while (!now.isEmpty()) {
            List<Integer> next = new ArrayList<>();
            for (int b : now) {
                int i = find0(b);
                for (int j : move[i]) {
                    int nb = move(b, j, i);
                    if (nb == target) return step;
                    if (hash[nb]) continue;
                    hash[nb] = true;
                    next.add(nb);
                }
            }
            now = next;
            ++step;
        }

        return -1;
    }

    int find0(int b) {
        int i;
        for (i = 0; (b & 0x7) != 0; ++i) {
            b >>= 3;
        }
        return 5 - i;
    }

    int move(int b, int i, int j) {
        i = (5 - i) * 3;
        j = (5 - j) * 3;
        int ibit = (b >> i) & 0x7;
        return (b & ~(0x7 << i)) | (ibit << j);
    }

    boolean noSolution(int[][] board) {
        int count = 0;
        for (int x = 1; x < 6; ++x) {
            int val = board[x/3][x%3];
            if (val == 0) continue;
            for (int y = 0; y < x; ++y) {
                if (board[y/3][y%3] > val) ++count;
            }
        }
        return (count & 1) == 1;
    }
}
__________________________________________________________________________________________________
sample 36548 kb submission
class Solution {
    public int slidingPuzzle(int[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0)
            return 0;
        
        String target = "123450";
        String start = "";
        
        int row = board.length;
        int col = board[0].length;
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                start += board[i][j] + "";
            }
        }
        
        Queue<String> que = new LinkedList<String>();
        Set<String> set = new HashSet<String>();
        
        que.offer(start);
        set.add(start);
        int steps = 0;
        
        int[] d = new int[] {1, -1, 3, -3};
        
        while (que.size() > 0)
        {
            steps++;
            
            int size = que.size();
            for (int s = 0; s < size; s++)
            {
                String cur = que.poll();
                if (cur.equals(target))
                    return steps-1;
                
                int curPos = cur.indexOf("0");
                
                for (int k = 0; k < 4; k++)
                {
                    int nextPos = curPos + d[k];
                    if (isValid(board, curPos, nextPos))
                    {
                        char[] ca = cur.toCharArray();
                        ca[curPos] = ca[nextPos];
                        ca[nextPos] = '0';
                        String next = new String(ca);
                        
                        if (!set.contains(next))
                        {
                            que.offer(next);
                            set.add(next);
                        }
                    }
                }
            }         
        }
        
        return -1;        
    }
    
    private boolean isValid(int[][] board, int cur, int next)
    {
        int row = board.length;
        int col = board[0].length;
        
        if (next >= 0 && next < row * col && !(cur == 2 && next == 3) && !(cur == 3 && next == 2))
            return true;
        else
            return false;
    }
}
__________________________________________________________________________________________________
