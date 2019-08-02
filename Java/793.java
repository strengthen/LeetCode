__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    long getZeros(long n) {
        long ans = 0;
        long temp = n;
        while(temp>0) {
            ans+=temp/5;
            temp/=5;
        }
        return ans;
    }
    int findRange(long k) {
        long low = 0;
        long high = Long.MAX_VALUE;
        while(low<=high) {
            long mid = (low+high)>>1;
            if(getZeros(mid)>k)
                high = mid-1;
            else low = mid+1;
        }
        return (int)low - 1;
    }
    public int preimageSizeFZF(int K) {
        return findRange(K) - findRange(K-1);
    }
}
__________________________________________________________________________________________________
sample 31624 kb submission
class Solution {

    static final int[] ms = new int[14];
    static {
        for(int i = 0, m = 1; i < ms.length; i++, m = m * 5 + 1) {
            ms[i] = m;
        }
    }

    public int preimageSizeFZF(int K) {
        int i = 0;
        for(; K > ms[i]; i++);
        for(i--; i >= 0; i--) {
            int m = ms[i];
            if(K / m == 5) {
                return 0;
            }
            K %= m;
        }
        return 5;
    }
}
__________________________________________________________________________________________________
