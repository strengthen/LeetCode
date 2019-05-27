__________________________________________________________________________________________________
sample 92 ms submission
static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size(), i = n - 1, j;
        while (i > 0 && A[i] >= A[i - 1]) i--;
        if (i == 0) return A;
        for (j = i--; j < n && A[j] < A[i]; j++);
        for (j--; j > 0 && A[j] == A[j - 1]; j--);
        swap(A[i], A[j]);
        return A;
    }
};
__________________________________________________________________________________________________
sample 96 ms submission
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        for(int i = A.size() - 2; i >= 0; --i){
            for(int j = A.size() - 1; j >= i; --j){
                if(A[i] > A[j]){
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                    return A;
                }
            }
        }
        return A;
    }
};
__________________________________________________________________________________________________
