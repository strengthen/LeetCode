__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
      public int integerBreak(int n) {
        if(n<4) return n-1;
        if(n==4) return 4;
        int res=1;
        while (n>4){
            n-=3;
            res*=3;
            // System.out.println(res);
        }
        return res*n;
    }
}
__________________________________________________________________________________________________
sample 31468 kb submission
class Solution {
    public int integerBreak(int n) {
        int[] result = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            int curMax = 0;
            for (int j = 1; j < i; j++) {
                curMax = Math.max(curMax, Math.max(j, result[j]) * (i - j));
            }
            result[i] = curMax;
        }
        return result[n];
    }
}
__________________________________________________________________________________________________
