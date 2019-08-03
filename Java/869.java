__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean reorderedPowerOf2(int N) {
        if(N<10)
            return Integer.bitCount(N)==1;
        
        int min = 10;
        while(10*min<=N)
            min*=10;
        //candidates are powers of 2 between min and 10 x min
        for(int cand = 2*Integer.highestOneBit(min);cand<10*min;cand*=2){
            if(match(N,cand))
                return true;
        }
        return false;
    }
    static boolean match(int a, int b){
        int[] cts = new int[10];
        
        while(a>0){
            cts[a%10]++;
            a/=10;
        }
        while(b>0){
            cts[b%10]--;
            b/=10;
        }        
        for(int i:cts)
            if(i!=0)
                return false;
        return true;
    }
}
__________________________________________________________________________________________________
sample 31924 kb submission
class Solution {
    public boolean reorderedPowerOf2(int N) {
        long target = counter(N);
        for (int i = 0; i < 32; i++) {
            if (counter(1 << i) == target) {
                return true;
            }
        }
        return false;
        
    }
    
    private long counter(int N) {
        // long长度为10， 分别代表9876543210的个数
        long res = 0;
        while (N > 0) {
            int n = N % 10;
            res += (int) Math.pow(10, n);
            N /= 10;
        }
        return res;
    }    
}
__________________________________________________________________________________________________
