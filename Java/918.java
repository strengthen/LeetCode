__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int maxSubarraySumCircular(int[] A) {
        int noWrap = findMax(A);
        int wrap = 0;
        for(int i = 0; i < A.length; i++){
            wrap += A[i];
            A[i] = -A[i];
        }
        wrap = wrap + findMax(A);
        if(wrap == 0)
            return noWrap;
        return wrap > noWrap? wrap : noWrap;
    }
    
    public int findMax(int[] A){
        int max = Integer.MIN_VALUE;
        int curr = 0;
        
        for(int i = 0; i < A.length; i++){
            curr += A[i];
        
            if(curr > max){
                max = curr;
            }
            if(curr < 0){
                curr = 0;
            }
        }
        return max;
    }
}
__________________________________________________________________________________________________
sample 41612 kb submission
class Solution {
    public int maxSubarraySumCircular(int[] A) {
        int N = A.length;

        // Compute P[j] = B[0] + B[1] + ... + B[j-1]
        // for fixed array B = A+A
        int[] P = new int[2*N+1];
        for (int i = 0; i < 2*N; ++i)
            P[i+1] = P[i] + A[i % N];

        // Want largest P[j] - P[i] with 1 <= j-i <= N
        // For each j, want smallest P[i] with i >= j-N
        int ans = A[0];
        // deque: i's, increasing by P[i]
        Deque<Integer> deque = new ArrayDeque();
        deque.offer(0);

        for (int j = 1; j <= 2*N; ++j) {
            // If the smallest i is too small, remove it.
            if (deque.peekFirst() < j-N)
                deque.pollFirst();

            // The optimal i is deque[0], for cand. answer P[j] - P[i].
            ans = Math.max(ans, P[j] - P[deque.peekFirst()]);

            // Remove any i1's with P[i2] <= P[i1].
            while (!deque.isEmpty() && P[j] <= P[deque.peekLast()])
                deque.pollLast();

            deque.offerLast(j);
        }

        return ans;
    }
}
__________________________________________________________________________________________________
