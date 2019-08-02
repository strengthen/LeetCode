__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    private static final long MODULO = 1000_000_007;
    
    public int numTilings(int n) {
        if (n <= 0) {
            return 0;
        }
        long[] tilings = new long[4];
        tilings[0] = 0;
        tilings[1] = 1;
        tilings[2] = 2;
        tilings[3] = 5;
        for (int i = 4; i <= n; i++) {
            tilings[i % 4] = (2 * tilings[(i-1) % 4] + tilings[(i-3) % 4]) % MODULO;
        }
        return (int) tilings[n % 4];
    }
}
__________________________________________________________________________________________________
sample 31588 kb submission
class Solution {
    public int numTilings(int N) {
        long M = 1000000007;
        long t = 0;
        long c1 = 1, c = 1;
        for (int i = 2; i <= N; i++) {
            long nt = c1 + t;
            long nc = (c + c1 + 2 * t) % M;
            t = nt;
            c1 = c;
            c = nc;
        }
        return (int) c;
    }
}
__________________________________________________________________________________________________
