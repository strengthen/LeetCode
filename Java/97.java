__________________________________________________________________________________________________
× Close
sample 0 ms submission
class Solution {
        private String s1, s2, s3;
    private int n1, n2, n3;
    boolean seen[][];

    public boolean isInterleave(String s1, String s2, String s3) {
        n1 = s1.length();
        n2 = s2.length();
        n3 = s3.length();
        
        this.s1 = s1;
        this.s2 = s2;
        this.s3 = s3;
        
        seen = new boolean[n1+1][n2+1];

        return n1 + n2 == n3 && dewIt(0, 0);
    }

    private boolean dewIt(int n, int m) {
        if(seen[n][m]) return false;
        while (n != n1 && m != n2 && s1.charAt(n) != s2.charAt(m)) {
            if (s1.charAt(n) == s3.charAt(n + m)) ++n;
            else if (s2.charAt(m) == s3.charAt(n + m)) ++m;
            else {
                seen[n][m] = true;
                return false;
            }
        }
        if (n + m == n3)
            return true;
        if (n == n1) {
            boolean tryIt = s2.substring(m).equals(s3.substring(n + m));
            if(tryIt) return true;
            else seen[n][m] = true;
            return false;
        }
        if (m == n2) {
            boolean tryIt = s1.substring(n).equals(s3.substring(n + m));
            if(tryIt) return true;
            else seen[n][m] = true;
            return false;
        }
        if(s1.charAt(n) == s3.charAt(n+m)) {
            if (s1.charAt(n) == s2.charAt(m)) {
                boolean tryIt = dewIt(n + 1, m);
                if(tryIt) return true;
                tryIt = dewIt(n, m + 1);
                if(!tryIt) seen[n][m] = true;
                return tryIt;
            }
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 33108 kb submission
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()){
            return false;
        }
        boolean[] dp = new boolean[s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++){
            for (int j = 0; j <= s2.length(); j++){
                if (i == 0 && j == 0){
                    dp[j] = true;
                }else if(i == 0){
                    dp[j] = dp[j-1] && s2.charAt(j-1) == s3.charAt(i+j-1);
                }else if (j == 0){
                    dp[j] = dp[j] && s1.charAt(i-1) == s3.charAt(i+j-1);
                }else{
                    dp[j] = (dp[j-1] && s2.charAt(j-1) == s3.charAt(i+j-1)) || (dp[j] && s1.charAt(i-1) == s3.charAt(i+j-1));
                }
            }
        }
        return dp[s2.length()];
    }
}
__________________________________________________________________________________________________
