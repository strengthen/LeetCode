__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int maxSumTwoNoOverlap(int[] A, int L, int M) {
        for (int i = 1; i < A.length; ++i)
            A[i] += A[i - 1];
        int res = A[L + M - 1], Lmax = A[L - 1], Mmax = A[M - 1];
        for (int i = L + M; i < A.length; ++i) {
            Lmax = Math.max(Lmax, A[i - M] - A[i - L - M]);
            Mmax = Math.max(Mmax, A[i - L] - A[i - L - M]);
            res = Math.max(res, Math.max(Lmax + A[i] - A[i - M], Mmax + A[i] - A[i - L]));
        }
        return res;
    }
    
}
__________________________________________________________________________________________________
sample 35392 kb submission
class Solution {
    private int[] helper(int[] A, int len) {
        int[] array = new int[A.length];
        int pos = 0;
        while (pos < len) {
            array[0] += A[pos++];
        }
        for (int i = 1; pos < A.length; i++, pos++) {
            array[i] = array[i-1] - A[pos - len] + A[pos];
        }
        for (int i = A.length-len+1; i < A.length; i++) {
            array[i] = -1000000;
        }
        return array;
    }
    public int maxSumTwoNoOverlap(int[] A, int L, int M) {
        int[] LA = helper(A, L);
        int[] MA = helper(A, M);
        int max = 0;
        int end = A.length - L - M;
        int endL = A.length - L;
        int endM = A.length - M;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(
            (a, b)->MA[b] - MA[a]);
        for (int i = L; i < MA.length; i++) {
            pq.offer(i);
        }
        for (int i = 0; i <= endL; i++) {
            if (i >= M) {
                pq.offer(i - M);
            }
            if (i + L -1 <= endM) {
                pq.remove(i + L -1);
            }
            max = Math.max(max, MA[pq.peek()] + LA[i]);
        }
        return max;
    }
}
__________________________________________________________________________________________________
