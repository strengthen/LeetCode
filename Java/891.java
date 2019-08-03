__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    
    private static final long MOD = 1000000007;

    public int sumSubseqWidths(int[] A) {
        final int M = 20001;
        int[] c = new int[M];
        for (int a: A) c[a]++;
        long res = 0, S = 0, T = 0;
        int k, prev = -1;
        for (k=1; k<M; k++) {
            int cnt = c[k];
            if (cnt == 0) continue;
            if (prev < 0) {
                prev = k;
                cnt--;
            }
            while (cnt-- > 0) {
                T = (T + T + 1) % MOD;
                S = (S + S + (k - prev) * T) % MOD;
                res = (res + S) % MOD;  
                prev = k;
            }
        }
        return (int)res;
    }

    public int sumSubseqWidths_sort(int[] A) {
        Arrays.sort(A);
        int n = A.length;
        long res = 0, S = 0, T = 0;
        for (int k=0; k<n-1; k++) {
            T = (T + T + 1) % MOD;
            S = (S + S + (A[k+1] - A[k]) * T) % MOD;
            res = (res + S) % MOD;
        }
        return (int)res;
    }    
}

// S1 = (A[k] - A[i]) * 2^(k - i - 1), 0 <= i <= k
// S2 = A([k+1] - A[i]) * 2^(k - i)
// S2 = 2S1 + (A[k+1] - A[k]) * 2^(k - i)
__________________________________________________________________________________________________
sample 39632 kb submission
class Solution {
    public int sumSubseqWidths(int[] A) {
        long res = 0;
        long mod = (long)1e9+7;
        Arrays.sort(A);
        long c = 1;
        for(int i = 0; i < A.length; ++i, c = (c << 1)%mod) {
            res =  (res + (A[i] - A[A.length - 1 - i]) * c + mod)%mod;
        }
        
        return (int)(res);
    }
}
__________________________________________________________________________________________________
