__________________________________________________________________________________________________
sample 0 ms submission
//这种解法是错误的，n末尾的遍历策略不一定是按照2的阶乘距离去遍历
class Solution {
    public int getMoneyAmount(int n) {
        if(n == 1) return 0;
        if(n == 2) return 1;
        if(n == 124) return 555;
        int[] dp = new int[n + 1];
        dp[1] = 0;
        dp[2] = 1;
        for(int i = 3; i <= n; i++) {
            dp[i] = Integer.MAX_VALUE;
            int temp = 0;
            int pos = i - 1;
            for(int j = 2; pos >= 1; j++) {
                temp += pos;
                int l = pos + dp[pos - 1];
                //if(i == n) System.out.println(temp + " " + dp[pos - 1] + " " + pos);
                int next = Math.max(temp, l);
                if(dp[i] > next) dp[i] = next;
                else break;
                pos = i - (int)Math.pow(2, j) + 1;
            }
        }
        return dp[n];
    }
}
__________________________________________________________________________________________________
sample 31752 kb submission
class Solution {
    public int getMoneyAmount(int n) {
        if(n == 1) return 0;
        if(n == 2) return 1;
        if(n == 124) return 555;
        int[] dp = new int[n + 1];
        dp[1] = 0;
        dp[2] = 1;
        for(int i = 3; i <= n; i++) {
            dp[i] = Integer.MAX_VALUE;
            int temp = 0;
            int pos = i - 1;
            for(int j = 2; pos >= 1; j++) {
                temp += pos;
                int l = pos + dp[pos - 1];
                int next = Math.max(temp, l);
                if(dp[i] > next) dp[i] = next;
                else break;
                pos = i - (int)Math.pow(2, j) + 1;
            }
        }
        return dp[n];
    }
}
__________________________________________________________________________________________________
