__________________________________________________________________________________________________
sample 1 ms submission
class Solution {

    static final int Mod = 1000_000_007;

    static final int[] xs = new int[]{1, 3, 8, 19, 43, 94};

    static final int[][] m = new int[][] {
            {0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 1},
            {-1, -2, -3, 0, 1, 2},
    };

    public int checkRecord(int n) {
        if(n <= 5) {
            return xs[n];
        }
        int[][] mp = power(m, n - 5);
        int[] row = mp[5];
        long sum = 0;
        for(int i = 0; i < 6; i++) {
            sum += (long)row[i] * xs[i];
        }
        return (int)((sum % Mod + Mod) % Mod);
    }

    private int[][] power(int[][] m, int n) {
        if(n == 1) {
            return m;
        }
        int[][] mp = power(m, n >> 1);
        int[][] mp2 = multiply(mp, mp);
        if((n & 1) == 1) {
            mp2 = multiply(mp2, m);
        }
        return mp2;
    }

    private int[][] multiply(int[][] a, int[][] b) {
        int[][] c = new int[6][6];
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                long sum = 0;
                for(int k = 0; k < 6; k++) {
                    sum += (long)a[i][k] * b[k][j];
                }
                c[i][j] = (int)(sum % Mod);
            }
        }
        return c;
    }
}
__________________________________________________________________________________________________
sample 31592 kb submission
public class Solution {
    public int checkRecord(int n) {
        long M = 1000000007;
        long a0l0=1;
        long a0l1 =0, a0l2 =0, a1l0=0, a1l1 =0, a1l2 =0;
      
      for(int i=0; i< n;i++){
        long a0l0Temp = (a0l0+a0l1+a0l2)%M;
       // long a0l1Temp = a0l0;
        //long a0l2Temp = a0l1;
        long a1l0Temp = (a0l0 + a0l1 + a0l2 + a1l0 + a1l1 + a1l2) %M;
        //long a1l1Temp = a1l0;
        //long a1l2Temp = a1l1;
        
        a0l2 = a0l1;
        a0l1 = a0l0;
        a1l2 = a1l1;
        a1l1 = a1l0;
        a0l0 = a0l0Temp;
        a1l0 = a1l0Temp;
        
        
      }
      return (int)((a1l1 + a1l0+ a1l2 + a0l0+ a0l1 + a0l2)%M);
    
    }
}
__________________________________________________________________________________________________
