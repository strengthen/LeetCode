__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    int[][] dp;
    int[] boxes;
    public int removeBoxes(int[] boxes) {
        int len = boxes.length;
        dp = new int[len][len];

        Map<Integer, Integer> last = new HashMap<>();
        for (int i = boxes.length - 1; i >= 0; --i) {
            int color = boxes[i];
            boxes[i] = last.getOrDefault(color, len);
            last.put(color, i);
        }

        this.boxes = boxes;
        return dpc(0, len - 1);
    }

    int dpc(int i, int j) {
        if (i == j) return 1;
        if (i > j) return 0;
        int r = dp[i][j];
        if (r > 0) return r;

        return dp[i][j] = dfs(j, i, boxes[i], 1, 0);
    }

    int dfs(int j, int x, int y, int count, int part) {
        if (y > j) {
            return count*count + part + (x < j ? dpc(x+1, j) : 0);
        }

        if (x+1 == y) {
            return dfs(j, y, boxes[y], count+1, part);
        }

        return Math.max(dfs(j, x, boxes[y], count, part),
            dfs(j, y, boxes[y], count + 1, part + dpc(x+1, y-1)));
    }
}
__________________________________________________________________________________________________
sample 49796 kb submission
class Solution {
    public int removeBoxes(int[] boxes) {

        int n = boxes.length;
        int[][][] dp = new int[n][n][n];

        for (int j = 0; j < n; j++) 
            for (int k = 0; k <= j; k++) 
                dp[j][j][k] = (k + 1) * (k + 1);



        for (int l = 1; l < n; l++) 
            for (int j = l; j < n; j++) {
                int i = j - l;

                for (int k = 0; k <= i; k++) {
                    int res = (k + 1) * (k + 1) + dp[i + 1][j][0];

                    for (int m = i + 1; m <= j; m++) 
                        if (boxes[m] == boxes[i]) 
                            res = Math.max(res, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);

                    dp[i][j][k] = res;
                }
            }


        return (n == 0 ? 0 : dp[0][n - 1][0]);
    }
}
__________________________________________________________________________________________________
