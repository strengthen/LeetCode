__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    
    public int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) return 0;
        int i1 = i - N, j1 = j - N;
        if (i1 > 0) {
            i = i - i1;
            m = m - i1;
        }
        if (j1 > 0) {
            j = j - j1;
            n = n - j1;
        }
        int i2 = i + N, j2 = j + N;
        if (i2 < m - 1) m = i2 + 1;
        if (j2 < n - 1) n = j2 + 1;
        int[][][] data = new int[m][n][N + 1];
        return helper(m, n, N, i, j, data);
    }
    
    private int helper(int m, int n, int N, int i, int j, int[][][] data) {
        if (i < 0 || i == m || j < 0 || j == n) return 1;
        if (Math.min(Math.min(i + 1, j + 1), Math.min(m - i, n - j)) > N)
            return 0;
        if (N == 0) return 0;
        if (data[i][j][N] > 0) return data[i][j][N];
        int total = 0;
        total = (total + helper(m, n, N - 1, i - 1, j, data)) % 1000000007;
        total = (total + helper(m, n, N - 1, i + 1, j, data)) % 1000000007;
        total = (total + helper(m, n, N - 1, i, j - 1, data)) % 1000000007;
        total = (total + helper(m, n, N - 1, i, j + 1, data)) % 1000000007;
        data[i][j][N] = total;
        return total;
    }
}
__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    static final int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    public int findPaths(int m, int n, int N, int i, int j) {
        int[][][] memo = new int[m][n][N + 1];
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                Arrays.fill(memo[r][c], -1);
            }
        }
        
        return helper(m, n, N, i, j, memo);
    }
    
    public int helper(int m, int n, int N, int i, int j, int[][][] memo) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 1;
        }
        
        if (memo[i][j][N] >= 0) {
            return memo[i][j][N];
        }
        
        int ans = 0;
        if (N > 0) {
            for (int[] dir : dirs) {
                ans += helper(m, n, N - 1, i + dir[0], j + dir[1], memo);
                ans %= 1_000_000_007;
            } 
        }
    
        memo[i][j][N] = ans;
        return ans;
    }
}
__________________________________________________________________________________________________
sample 32892 kb submission
class Solution {
    
    int mod = 1000000000 + 7;
    public int findPaths(int m, int n, int N, int _i, int _j) {
        if(N == 0) {
            return 0;
        }
        
        int[][] dp0 = new int[m][n];
        int[][] dp1 = new int[m][n];
        
        for(int i = 0; i < m; i++) {
            dp0[i][0] += 1;
            dp0[i][n-1] += 1;
        }
        for(int j = 0; j < n; j++) {
            dp0[0][j] += 1;
            dp0[m-1][j] += 1;
        }
        
        for(int k = 2; k <= N; k++) {
            
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    dp1[i][j] = (i == 0) ? 1 : dp0[i-1][j];
                    dp1[i][j] %= mod;
                    dp1[i][j] += (i == m - 1) ? 1 : dp0[i+1][j];
                    dp1[i][j] %= mod;
                    dp1[i][j] += (j == 0) ? 1 : dp0[i][j - 1];
                    dp1[i][j] %= mod;
                    dp1[i][j] += (j == n - 1) ? 1 : dp0[i][j + 1];
                    dp1[i][j] %= mod;
                }
            }
            int[][] tmp = dp0;
            dp0 = dp1;
            dp1 = tmp;
        }
        
        return dp0[_i][_j];
    }
}