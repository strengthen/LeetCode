__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean isMonotonic(int[] A) {
        if (A.length == 1) {
            return true;
        }
        int p = 1;
        while (p < A.length && A[p - 1] <= A[p]) {
            ++p;
        }
        if (A.length != p) {
            p = 1;
            while (p < A.length && A[p] <= A[p - 1]) {
                ++p;
            }
        }
        return A.length == p;
    }
}
__________________________________________________________________________________________________
sample 47008 kb submission
class Solution {
    public boolean isMonotonic(int[] arr) {
        int[] sorted = IntStream.of(arr)
                .boxed()
                .sorted()
                .mapToInt(i -> i)
                .toArray();
        int[] reversed = IntStream.of(arr)
                .boxed()
                .sorted(Collections.reverseOrder())
                .mapToInt(i -> i)
                .toArray();
        return Arrays.equals(sorted, arr) || Arrays.equals(reversed, arr);
    }
}
__________________________________________________________________________________________________
