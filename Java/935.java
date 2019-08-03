__________________________________________________________________________________________________
sample 0 ms submission
class Solution {

    static int[] res;
    public int knightDialer(int N) {
        if (res == null) {
            res = new int[5001];
            res[1] = 10;
            int mod = 1000_000_007;
            long f0 = 1, f1379 = 4, f28 = 2, f46 = 2;
            for (int i = 2; i < res.length; ++i) {
                long b0 = f46;
                long b1379 = (f28 << 1) + (f46 << 1);
                long b28 = f1379;
                long b46 = (f0 << 1) + f1379;
                f0 = b0 % mod;
                f1379 = b1379 % mod;
                f28 = b28 % mod;
                f46 = b46 % mod;
                res[i] = (int)((f0 + f1379 + f28 + f46) % mod);
            }
        }
        return res[N];
    }
}
__________________________________________________________________________________________________
sample 31764 kb submission
class Solution {
    public int knightDialer(int N) {
        if(N==1)
            return 10;
        
        //initialization
        long c46=2,c1379=4,c28=2,c0=1;
        int mod=(int)1e9+7;
        int i=2;
        
        while(i<=N){
            //hop
            //key 0 <-- key 4,6
            //key 2,8 <-- key 1,3,7,9
            //...
            long n0=c46,n28=c1379,n1379=(c46*2+c28*2)%mod,n46=(c1379+c0*2)%mod;
            
            c0=n0;
            c28=n28;
            c46=n46;
            c1379=n1379;
            
            i++;
        }
        
        return (int)((c0+c28+c46+c1379)%mod);
    }
}
__________________________________________________________________________________________________
