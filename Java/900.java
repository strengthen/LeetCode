__________________________________________________________________________________________________
sample 44 ms submission
class RLEIterator {

    int[] a;
    int idx;
    public RLEIterator(int[] A) {
        a = A;
        idx = 0;
    }
    
    public int next(int n) {
        while(n > 0 && idx < a.length) {
            if (n > a[idx]) {
                n -= a[idx];
                if (n == 0) return a[idx + 1];
                idx += 2;
            } else {
                a[idx] -= n;
                return a[idx + 1];
            }
        }
        return -1;
    }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
__________________________________________________________________________________________________
sample 38468 kb submission
class RLEIterator {
    private int currIndex;
    private int[] A;
    public RLEIterator(int[] A) {
        currIndex = 0;
        this.A = A;
    }
    
    public int next(int n) {
       while(currIndex < A.length) {
           if(A[currIndex] < n) {
               n -= A[currIndex];
               currIndex += 2;
           }
           else {
               A[currIndex] -= n;
               return A[currIndex+1];
           }
       }
       
       return -1;
    }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
__________________________________________________________________________________________________
