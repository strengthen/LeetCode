__________________________________________________________________________________________________
class Solution {
    public int[] prevPermOpt1(int[] A) {
        int n = A.length, left = n - 2, right = n - 1, tmp;
        while (left >= 0  && A[left] <= A[left + 1]) left--;
        if (left < 0) return A;
        while (A[left] <= A[right]) right--;
        while (A[right - 1] == A[right]) right--;
        tmp = A[left]; A[left] = A[right]; A[right] = tmp;
        return A;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
