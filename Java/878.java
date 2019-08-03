__________________________________________________________________________________________________
sample 0 ms submission

//import java.util.HashMap;
class Solution {
    public int nthMagicalNumber(int n, int a, int b) {
        if (a == b) {
            return (int)(((long) a) * n % 1_000_000_007);
        }
        if (a > b) {
            a = b + a;
            b = a - b;
            a = a - b;
        }
        long nok = findNok(b, a);
        long min = a;
        long max = (a + b) * 1_000_000_007L;
        while (min != max) {
            long middle = (min + max) >> 1;
            long iterations = middle / a + middle / b - middle / nok;
            if (iterations < n)
                min = middle;
            else if (iterations > n)
                max = middle;
            else {
                long result = Math.max( (middle / a) * a, (middle / b) * b);
                return (int)(result % 1_000_000_007);
            }

        }
        return 0;
    }
    
    long findNod(int a, int b) {
        if (b == 0) 
            return a;
        else
            return findNod(b, a % b);
    }
    
    long findNok(int a, int b) {
        return (a / findNod(a, b)) * b;
    }
};
__________________________________________________________________________________________________
sample 31664 kb submission
class Solution {
    public int nthMagicalNumber(int N, int A, int B) {
        int MOD = 1_000_000_007;
        int L = A / gcd(A, B) * B;
        int M = L / A + L / B - 1;
        int q = N / M, r = N % M;

        long ans = (long) q * L % MOD;
        if (r == 0)
            return (int) ans;

        int[] heads = new int[]{A, B};
        for (int i = 0; i < r - 1; ++i) {
            if (heads[0] <= heads[1])
                heads[0] += A;
            else
                heads[1] += B;
        }

        ans += Math.min(heads[0], heads[1]);
        return (int) (ans % MOD);
    }

    public int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
}
__________________________________________________________________________________________________
