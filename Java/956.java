__________________________________________________________________________________________________
sample 6 ms submission
class Solution {
    public int tallestBillboard(int[] A) {
        int n = A.length;
        if (n == 0) {
            return 0;
        }
        int sum = 0;
        for (int num : A) {
            sum += num;
        }
        int[][] diff = new int[n][sum + 1];
        // diff[i][j]: after adding in A[i], for height difference of j, the max height of the shorter support.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= sum; j++) {
                diff[i][j] = -1;
            }
        }
        
        diff[0][0] = 0;
        diff[0][A[0]] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (diff[i - 1][j] == -1) {
                    continue;
                }
                //System.out.println(i + " " +j +" " + diff[i - 1][j]);
                int d1 = j, d2 = j + A[i], d3 = Math.abs(j - A[i]);
                diff[i][d1] = Math.max(diff[i][d1], diff[i - 1][j]);
                diff[i][d2] = Math.max(diff[i][d2], diff[i - 1][j]);
                diff[i][d3] = Math.max(diff[i][d3], diff[i - 1][j] + Math.min(j, A[i]));
            }
        }
        return diff[n - 1][0];
    }
}
__________________________________________________________________________________________________
sample 35588 kb submission
class Solution {
    public int tallestBillboard(int[] rods) {
        int sum = 0;
        sum = Arrays.stream(rods).sum();
        int n = rods.length;
        
        //dp[i][j] - whether sum of first i nums can be (j-sum) - using offset of sum to avoid going in -ve
        //dp[i + 1][j] = dp[i][j - rods[i]] | dp[i][j + rods[i]] | dp[i][j]
        //max[i][j] represents the largest sum of all positive numbers when the sum of first i numbers is j - sum
        boolean[][] dp = new boolean[n + 1][2*sum+1];
        int[][] max = new int[n + 1][2*sum+1];
        dp[0][sum] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 2*sum; j++) {
                if (j - rods[i] >= 0 && dp[i][j - rods[i]]) {
                    dp[i + 1][j] = true;
                    max[i + 1][j] = Math.max(max[i + 1][j], max[i][j - rods[i]] + rods[i]);
                }
                if (j + rods[i] <= 2*sum && dp[i][j + rods[i]]) {
                    dp[i + 1][j] = true;
                    max[i + 1][j] = Math.max(max[i + 1][j], max[i][j + rods[i]]);
                }
                if (dp[i][j]) {
                    dp[i + 1][j] = true;
                    max[i + 1][j] = Math.max(max[i + 1][j], max[i][j]);
                }
            }
        }
        return max[n][sum];
    }
}
__________________________________________________________________________________________________
