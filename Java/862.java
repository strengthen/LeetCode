__________________________________________________________________________________________________
sample 7 ms submission
// sample 10 ms submission of leetcode-cn.com
class Solution {
    public int shortestSubarray(int[] A, int K) {
        int start = 0;
        int minl = -1;
        int maxw = A.length -1;
        int sum = 0;
        for (int i=0, l; i<A.length;i++) {
            if (A[i] >= K) return 1;
            sum += A[i];
            if (sum <= 0) {
                sum = 0;
                start = i+1;
                continue;
            }
            l = i;
            while (A[l] < 0 && l >start) {
                A[l-1] += A[l];
                A[l] = 0;
                --l;
            }
            if (i-start > maxw) {
                sum -= A[start];
                ++start;
            }
            if (sum>=K) {
                l = i-start+1;
                for (int j=start;j<i;++j) {
                    sum -= A[j];
                    if (sum < K) {
                        l = i-j+1;
                        start = j+1;
                        maxw = i-j;
                        break;
                    }
                }
                if (l<minl || minl<0) minl = l;
            }
        }
        return minl;
    }
}
__________________________________________________________________________________________________
sample 51628 kb submission
class Solution {
    public int shortestSubarray(int[] A, int K) {
        // subarraySum[i + 1, j] = sum[j] - sum[i]
        int res = Integer.MAX_VALUE;
        long[] sums = new long[A.length];
        Deque<Integer> indexDeque = new ArrayDeque<>();
        //indexDeque.offerFirst(-1);
        for (int i = 0; i < A.length; i++) {
            sums[i] = i == 0 ? A[i] : A[i] + sums[i - 1];
            while (indexDeque.size() > 0 && sums[indexDeque.peekFirst()] >= sums[i]) {
                indexDeque.pollFirst();
            }
            indexDeque.offerFirst(i);
            long diff = sums[i] - K;
            if (diff >= 0) {
                res = Math.min(res, i + 1);
            }
            while (indexDeque.size() > 0 && indexDeque.peekLast() != i && sums[indexDeque.peekLast()] <= diff) {
                int lo = indexDeque.pollLast();
                res = Math.min(res, i - lo);
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}
__________________________________________________________________________________________________
