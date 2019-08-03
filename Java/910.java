__________________________________________________________________________________________________
sample 6 ms submission
class Solution {
    int x;
    public int smallestRangeII(int[] A, int K) {
        int min=10000;
        int max=0;
        for (int a:A) {
            max=Math.max(max,a);
            min=Math.min(min,a);
        }
        // min and max with the same operation
        x=max-min;
        int l=Math.min(max,min+2*K);
        int r=Math.max(max,min+2*K);
        helper(l,r,0,A,K);
        return x;
    }
    
    void helper(int l,int r,int idx,int[] A,int K) {
        if (r-l>=x) {
            return;
        }
        if (idx==A.length) {
            x=r-l;
            return;
        }
        int n=A[idx];
        if (n+2*K<=r||n>=l) {
            helper(l,r,idx+1,A,K);
        } else {
            helper(n,r,idx+1,A,K);
            helper(l,n+2*K,idx+1,A,K);
        }
    }
}
__________________________________________________________________________________________________
sample 39112 kb submission
class Solution {
    public int smallestRangeII(int[] A, int K) {
        Arrays.sort(A);
        
        int n = A.length, mx = A[n - 1], mn = A[0], res = mx - mn;
        for (int i = 0; i < n - 1; i++) {
             mn = Math.min(A[0] + K, A[i + 1] - K);
             mx = Math.max(A[i] + K, A[n - 1] - K);
            res = Math.min(res, mx-mn);
        }
        return res;
    }
}
__________________________________________________________________________________________________
