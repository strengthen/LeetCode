__________________________________________________________________________________________________
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size(), left = n - 2, right = n - 1;
        while (left >= 0  && A[left] <= A[left + 1]) left--;
        if (left < 0) return A;
        while (A[left] <= A[right]) right--;
        while (A[right - 1] == A[right]) right--;
        swap(A[left], A[right]);
        return A;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
