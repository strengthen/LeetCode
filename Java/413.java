__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int n = A.length, res = 0, count = 0;
        for (int i = 1; i < n - 1; i++) {
            if (A[i] - A[i - 1] == A[i + 1] - A[i]) res += ++count;
            else count = 0;
        }
        
        return res;
    }
}
__________________________________________________________________________________________________
sample 35560 kb submission
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        if(A == null || A.length < 3) {
            return 0;
        }
        int n = A.length;
        int[] dp = new int[n];
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i < n; i++){
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2]){
                dp[i] = dp[i - 1] + 1;
            }
        }
        return IntStream.of(dp).sum();
    }
}
__________________________________________________________________________________________________
