__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[] sortedSquares(int[] A) {
        int[] squares = new int[A.length];
        int end = A.length-1, start=0, idx = end;
        while(start <= end) {
          int endSq = A[end] * A[end];
          int startSq = A[start] * A[start];
          if (endSq >= startSq) {
            squares[idx--] = endSq;
            end--;
          } else {
            squares[idx--] = startSq;
            start++;
          } 
        }
        return squares;
    }
}
__________________________________________________________________________________________________
sample 39456 kb submission
class Solution {
    public int[] sortedSquares(int[] A) {
        Integer[] B = new Integer[A.length];
        for (int t = 0; t < A.length; ++t)
            B[t] = A[t];
        Arrays.sort(B, (a, b) -> Integer.compare(Math.abs(a), Math.abs(b)));
        for (int t = 0; t < A.length; ++t)
            A[t] = B[t] * B[t];
        return A;
    }
}
__________________________________________________________________________________________________
