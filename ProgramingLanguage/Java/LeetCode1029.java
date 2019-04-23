__________________________________________________________________________________________________
1ms
class Solution {
    Integer[][] dp;
    public int twoCitySchedCost(int[][] costs) {
        int n = costs.length;
        dp = new Integer[n/2+1][n/2+1];
        return rec(costs, 0, n/2, n/2);
    }
    
    private int rec(int[][] costs, int i, int na, int nb){
        if(i >= costs.length)
            return 0;
        if(na > 0 && nb > 0 && dp[na][nb] != null) return dp[na][nb];
        int a = Integer.MAX_VALUE, b = Integer.MAX_VALUE;
        if(na > 0) a = costs[i][0] + rec(costs, i+1, na- 1, nb);
        if(nb > 0) b = costs[i][1] + rec(costs, i+1, na, nb -1);
        dp[na][nb] = Math.min(a,b);
        return dp[na][nb];
    }
    
}
__________________________________________________________________________________________________
2ms
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        Arrays.sort(costs, new Comparator<int[]>(){
            public int compare(int[] a, int[] b) {
                return Math.abs(b[0] - b[1]) - Math.abs(a[0] - a[1]);
            }
        });
        int countA = 0;
        int countB = 0;
        int N = costs.length / 2;
        int total = 0;
        for (int[] cost: costs) {            
            if (cost[0] < cost[1]) {
                if (countA < N) {
                    total += cost[0];
                    countA++;
                } else {
                    total += cost[1];
                    countB++;
                }
            } else {
                if (countB < N) {
                    total += cost[1];
                    countB++;
                } else {
                    total += cost[0];
                    countA++;
                }
            }
        }
        return total;
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int N = costs.length / 2;
        int[][] dp = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            dp[i][0] = dp[i - 1][0] + costs[i - 1][0];
        }
        for (int j = 1; j <= N; j++) {
            dp[0][j] = dp[0][j - 1] + costs[j - 1][1];
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = Math.min(dp[i - 1][j] + costs[i + j - 1][0], dp[i][j - 1] + costs[i + j - 1][1]);
            }
        }
        return dp[N][N];
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________

__________________________________________________________________________________________________

__________________________________________________________________________________________________