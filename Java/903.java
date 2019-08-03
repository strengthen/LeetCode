__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    private int mod = (int)(1e9+7);
    public int numPermsDISequence(String S) {
        int n = S.length();
        int[][] dp = new int[n+1][n+1];
        for (int j=0; j<=n; j++) {
            dp[0][j] = 1;
        }
        
        for (int i=1; i<=n; i++) {
            char c = S.charAt(i-1);
            int count = 0;
            
            if (c == 'I') {
                for (int j=0; j<=n-i; j++) {
                    count += dp[i-1][j];
                    count %= mod;
                    dp[i][j] = count;
                }
            } else {
                for (int j=n-i; j>=0; j--) {
                    count += dp[i-1][j+1];
                    count %= mod;
                    dp[i][j] = count;
                }
            }
        }
        
        return dp[n][0];
        
        // TLE
        /*
        int count = 0, n = S.length() + 1;
        boolean[] visited = new boolean[n];
        for (int i=0; i<n; i++) {
            count += helper(i, 0, visited, S);
            count %= mod;
        }
        
        return count;
        */
    }
    
    private int helper(int num, int i, boolean[] visited, String S) {
        if (i == S.length()) {
            return 1;
        }
        
        visited[num] = true;
        int count = 0, n = visited.length;
        char c = S.charAt(i);
        
        if (c == 'D') {
            for (int j=num-1; j>=0; j--) {
                if (visited[j]) {
                    continue;
                }
                
                count += helper(j, i+1, visited, S);
                count %= mod;
            }
        } else {
            for (int j=num+1; j<n; j++) {
                if (visited[j]) {
                    continue;
                }
                
                count += helper(j, i+1, visited, S);
                count %= mod;
            }
        }
        
        visited[num] = false;
        return count;
    }
}
__________________________________________________________________________________________________
sample 37064 kb submission
class Solution {
    public int numPermsDISequence(String S) {
         int n = S.length(), mod = (int)1e9 + 7;
        int[][] dp = new int[n + 1][n + 1];
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int i = 0; i < n; i++)
            if (S.charAt(i) == 'I')
                for (int j = 0, cur = 0; j < n - i; j++)
                    dp[i + 1][j] = cur = (cur + dp[i][j]) % mod;
            else
                for (int j = n - i - 1, cur = 0; j >= 0; j--)
                    dp[i + 1][j] = cur = (cur + dp[i][j + 1]) % mod;
        return dp[n][0];
    }
}
__________________________________________________________________________________________________
