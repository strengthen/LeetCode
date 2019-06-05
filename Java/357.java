__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int product = 9;
            for (int j = 0; j < i - 1; j++) {
                product *= (9 - j);
            }
            dp[i] = dp[i - 1] + product;
        }
        return dp[n];
    }
}
__________________________________________________________________________________________________
sample 31424 kb submission
class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1){
            return 10;
        }
        if(n > 10){
            return countNumbersWithUniqueDigits(10);
        }
        int num = 9;
        for(int i = 0; i < n-1; i++){
            num *= (9-i);
        }
        return num + countNumbersWithUniqueDigits(n-1);
    }
}
__________________________________________________________________________________________________
