__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    int fixedPoint(vector<int>& A) {
        for(int i = 0;i < A.size();++i) {
            if(A[i] == i) {
                return i;
            }
        }
        return -1;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
   int fixedPoint(vector<int>& A) {
        int l = 0, r = A.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (A[m] - m > 0)
                r = m - 1;
            else if (A[m] - m < 0)
                l = m + 1;
            else
                return m;
        }
        return -1;
    }
};
__________________________________________________________________________________________________
