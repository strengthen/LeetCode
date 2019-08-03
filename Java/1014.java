__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        int max = Integer.MIN_VALUE;
        int runningMax = A[0];
        
        for(int i=1; i<A.length; i++){
            runningMax--;
            if(A[i] + runningMax > max){
                max = A[i] + runningMax;
            }
            if(A[i] > runningMax){
                runningMax = A[i];
            }
        }
        
        return max;
    }
}
__________________________________________________________________________________________________
sample 47804 kb submission
class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        Stack<Integer> stack = new Stack<>();
        stack.push(A.length-1);
        int max = A[A.length-1];
        for (int i = A.length - 2; i >= 0; i--) {
            // Remove all sights that are lower and later than this one, but still consider them here
            while (!stack.empty() && A[stack.peek()] <= A[i]) {
                int j = stack.pop();
                max = Math.max(max, A[i] + A[j] - (j - i));
            }
            // See if there are any better solutions starting here:
            for (int j : stack) {
                max = Math.max(max, A[i] + A[j] - (j - i));
            }
            stack.push(i);
        }
        return max;
    }
}
__________________________________________________________________________________________________
