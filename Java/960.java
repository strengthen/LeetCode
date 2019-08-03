__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
  private static int calc(String[] A, int i, int[] arr) {
    if (arr[i] != 0) return arr[i];
    int res = 1;
    for (int j = 0; j < i; j++) {
      int max = calc(A, j, arr);
      boolean ok = true;
      for (int k = 0; k < A.length; k++) {
        if (A[k].charAt(j) > A[k].charAt(i)) {
          ok = false;
          break;
        }
      }
      if (ok) res = Math.max(res, max + 1);
    }
    arr[i] = res;
    return res;
  }
  
  public int minDeletionSize(String[] A) {
    int n = A[0].length();
    int[] arr = new int[n];
    arr[0] = 1;
    int res = 0;
    for (int i = 0; i < n; i++) {
      res = Math.max(res, calc(A, i, arr));
    }
    return n - res;
  }
}
__________________________________________________________________________________________________
sample 37548 kb submission
class Solution {
    public int minDeletionSize(String[] A) {
        if (A == null || A.length == 0) return 0;
        int len = A[0].length();
        int[] dp = new int[len];
        dp[0] = 1;
        for (int i = 1; i < len; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (isValid(A, i, j)) dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
        int max = 0;
        for (int i = 0; i < len; i++) max = Math.max(max, dp[i]);
        return A[0].length() - max;
    }
    
    boolean isValid(String[] A, int x, int y) {
        boolean flag = true;
        for (int i = 0; i < A.length; i++) {
            String s = A[i];
            if (s.charAt(x) < s.charAt(y)) return false;
        }
        return true;
    }
}
__________________________________________________________________________________________________
