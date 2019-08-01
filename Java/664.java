__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int strangePrinter(String s) {
        char[] a = s.toCharArray();
        if (a.length < 2) return a.length;
        int j = 1;
        for (int i = 1; i < a.length; i++) {
            if (a[i] == a[j - 1]) continue;
            a[j++] = a[i];
        }
        return dfs(a, 0, j - 1, new int[j][j]);
    }

    private int dfs(char[] s, int i, int j, int[][] cache) {
        if (i > j) return 0;
        if (cache[i][j] > 0) return cache[i][j];
        int ans = 1 + dfs(s, i, j - 1, cache);
        for (int k = i; k < j; k++) {
            if (s[k] == s[j]) {
                ans = Math.min(ans, dfs(s, i, k, cache) + dfs(s, k + 1, j - 1, cache));
            }
        }
        cache[i][j] = ans;
        return ans;
    }
}
__________________________________________________________________________________________________
sample 36700 kb submission
class Solution {
    public int strangePrinter(String s) {
        if(s == null || s.equals("")) return 0;
        int n = s.length();
        int[][] dp = new int[n][n];
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(i == j) {
                    dp[i][j] = 1;
                    continue;
                }else{
                    dp[i][j] = dp[i + 1][j] + 1;
                    for(int k = i + 1; k <= j; k++) {
                        if(s.charAt(k) == s.charAt(i)) {
                            dp[i][j] = Math.min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                        }
                    }
                }
            }
        }
        //for(int[] row : dp) System.out.println(Arrays.toString(row));
        return dp[0][n - 1];
    }
}
__________________________________________________________________________________________________
