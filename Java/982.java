__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public int countTriplets(int[] A) {
        int N = (1 << 16) - 1;
        int[] ct = new int[N + 1];
        int l = A.length;

        for (int x : A) {
            for (int k = x; k <= N; k = x | (k + 1)) {
                ++ct[k];
            }
        }

        int res = 0;
        for (int a : A) {
            for (int b : A) {
                res += ct[N ^ (a & b)];
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 37148 kb submission
class Solution {
    public int countTriplets(int[] A) {
        int ans=0;
        int []store= new int[1<<16];
        for(int i=0;i<A.length;i++){
            for(int j=0;j<A.length;j++)
            {
                store[A[i]&A[j]]++;
            }
        }
        for(int i=0;i<A.length;i++)
        {
            for(int j=0;j<(1<<16);j++){
                if((A[i]&j)==0)
                {
                    ans+=store[j];
                }
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
