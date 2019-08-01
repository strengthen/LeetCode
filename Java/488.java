__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    // "YWWRRRWWYY" -> "YWWWWYY" -> "YYY" -> ""
    public String update(String board){
        int i=0;
        while(i < board.length()){
            int j=i;
            while(j < board.length() && board.charAt(i) == board.charAt(j)){
                j++;
            }
            if(j-i >= 3){
                board = board.substring(0,i)+board.substring(j);
                i=0;
            } else {
                i=j;
            }
        }
        return board;
    }
    public int findMinStep(String board, String hand) {
        int[] h = new int[128];
        for(char c : hand.toCharArray()){
            h[c]++;
        }
        return dfs(board,h);
    }
    public int dfs(String board, int[] h){
        if(board.length()==0){
            return 0;
        }
        int i=0;
        int res = Integer.MAX_VALUE;
        while(i < board.length()){
            int j=i;
            while(j < board.length() && board.charAt(i) == board.charAt(j)){
                j++;
            }
            int b = 3-(j-i);
            if(h[board.charAt(i)] >= b){
                h[board.charAt(i)] -= b;
                String newBoard = update(board.substring(0,i)+board.substring(j));
                int innerRes = dfs(newBoard,h);
                if(innerRes >=0){
                    res = Math.min(res, b+innerRes);
                }
                h[board.charAt(i)] += b;
            }
            i=j;
        }
        return res == Integer.MAX_VALUE?-1:res;
    }
}
__________________________________________________________________________________________________
sample 36804 kb submission
class Solution {
     public int findMinStep(String board, String hand) {
        if (board == null || board.length() == 0) {
            return 0;
        }

        // 为了方面查询，我们需要统计手中珠子的信息（本题中我们可以发射手中的任意一颗珠子）
        Map<Character, Integer> balls = new HashMap<>();
        for (char c : hand.toCharArray()) {
            balls.put(c, balls.getOrDefault(c, 0) + 1);
        }
        return dfs(board, balls);
    }

    // 返回全部清楚当前board所需要的最少珠子，如果无法全部清除返回-1
    private int dfs(String board, Map<Character, Integer> balls) {
        if (board == null || board.length() == 0) {
            return 0;
        }

        int rst = Integer.MAX_VALUE;
        int i = 0, j;
        while (i < board.length()) {
            j = i + 1;
            Character color = board.charAt(i);
            // j一直向后移动，直到 j 越界 或者 指向的珠子颜色与 i 的不同
            while (j < board.length() && color == board.charAt(j)) {
                j++;
            }
            // 需要插入多少颗珠子才能消掉 i~j-1 的珠子
            int costBalls = 3 - (j - i);
            // 手中剩余足够的珠子可供插入
            if (balls.containsKey(color) && balls.get(color) >= costBalls) {
                // 消去 i~j-1 段的珠子，同时因为消去该段会导致两边的两段的珠子碰到一起
                // 可能会引发连续的消除反应，因此实现了 shrink() 来实现这点
                String newBoard = shrink(board.substring(0, i) + board.substring(j));
                // 减去花费掉的珠子数
                balls.put(color, balls.get(color) - costBalls);
                // 进行 DFS 调用子过程，求解全部消去剩下珠子需要的最少珠子数
                int subRst = dfs(newBoard, balls);
                if (subRst >= 0) {
                    // 如果可以被顺利全部消除的话，取最小值即可
                    rst = Math.min(rst, costBalls + subRst);
                }
                // Backtracking 加上之前消耗掉的珠子，进行回溯操作
                balls.put(color, balls.get(color) + costBalls);
            }
            i = j;
        }

        return rst == Integer.MAX_VALUE ? -1 : rst;
    }

    // 消除当前 board 中所有可以消除的珠子串
    private String shrink(String board) {
        int i = 0, j;
        while (i < board.length()) {
            j = i + 1;
            Character color = board.charAt(i);
            while (j < board.length() && color == board.charAt(j)) {
                j++;
            }
            if (j - i >= 3) {
                board = board.substring(0, i) + board.substring(j);
                // 当进行成功消除后，记得将 i 重置回 0 位置，重新进行检查（因为可能发生连锁反应）
                i = 0;
            } else {
                i++;
            }
        }
        return board;
    }
}
__________________________________________________________________________________________________
