__________________________________________________________________________________________________
1ms
class Solution {
    public boolean isMatch(String s, String p) {
        Boolean[][] memo = new Boolean[s.length() + 1][p.length() + 1];
        return dp(s, p, 0, 0, memo);
    }
    
    private boolean dp(String s, String p, int i, int j, Boolean[][] memo) {
        if (memo[i][j] != null) return memo[i][j];
        boolean ans;
        if (j == p.length()) {
            ans = i == s.length();
        } else {
            boolean firstMatch = i < s.length() && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.');
            if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
                ans = dp(s, p, i, j + 2, memo) || (firstMatch && dp(s, p, i + 1, j, memo));
            } else {
                ans = firstMatch && dp(s, p, i + 1, j + 1, memo);
            }
        }
        memo[i][j] = ans;
        return ans;
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] match = new boolean[s.length()+1][p.length()+1];
        match[0][0] = true;
        for ( int j = 2; j <= p.length(); j++)
            match[0][j] = match[0][j-2] && p.charAt(j-1) == '*';
        
        for ( int i = 1; i <= s.length(); i++)
            for( int j = 1; j <= p.length(); j++){
                if (p.charAt(j-1) == '*')
                match[i][j] = match[i-1][j] && (s.charAt(i-1) == p.charAt(j-2) || p.charAt(j-2) == '.') || 
                              match[i][j-2] && p.charAt(j-1) == '*';
                else 
                    match[i][j] = match[i-1][j-1] && (s.charAt(i-1) == p.charAt(j-1) || p.charAt(j-1) == '.');
            }
        
        return match[s.length()][p.length()];
    }
}
__________________________________________________________________________________________________
3ms
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        dp[s.length()][p.length()] = true;
        
        for (int i = s.length(); i >= 0; i--) {
            for (int j = p.length() - 1; j >= 0; j--) {
                boolean firstMatch = (i < s.length()) && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.');
                if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
                    dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
                } else {
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
}
__________________________________________________________________________________________________
35452 kb
class Solution {    
    char[] ct, cp;
    int lt, lp;

    private boolean solve(int it, int ip) {
        if (ip == lp) return it == lt;
        boolean fm = it < lt && (ct[it] == cp[ip] || cp[ip] == '.');
        if (ip + 1 < lp && cp[ip + 1] == '*')
            return fm && solve(it + 1, ip) || solve(it, ip + 2);
        else return fm && solve(it + 1, ip + 1);
    }
    
    public boolean isMatch(String t, String p) {
        lt = t.length(); lp = p.length();
        cp = p.toCharArray(); ct = t.toCharArray();
        return solve(0, 0);
    }
}
__________________________________________________________________________________________________
35524 kb
class Solution {
    public boolean isMatch(String s, String p) {
        int M = s.length(), N = p.length();
        boolean[][] dp = new boolean[M+1][N+1];
        dp[0][0] = true;
        
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= N; j++) {
                if (j == 0 && i > 0) {
                    dp[i][0] = false;
                } else {
                    if (i > 0 && j > 0 && (s.charAt(i-1)==p.charAt(j-1)
                        || p.charAt(j-1) == '.')) {
                        dp[i][j] = dp[i-1][j-1];
                    } else if (j >0 && p.charAt(j-1) == '*') {
                        if (j > 1) {
                            dp[i][j] = dp[i][j-2];
                            if (i > 0 && (s.charAt(i-1) == p.charAt(j-2) 
                                          || p.charAt(j-2) == '.')){
                                dp[i][j] = dp[i][j] || dp[i-1][j];
                            }
                        }
                    }
                }
            }
        }
        return dp[M][N];
    }
}
__________________________________________________________________________________________________
