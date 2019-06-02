__________________________________________________________________________________________________
class Solution {
public:
    vector<int> addBinary(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int carry = 0, i = A.size() - 1, j = B.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += A[i--];
            if (j >= 0) carry += B[j--];
            res.push_back(carry & 1);
            carry = (carry >> 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> addNegabinary(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int carry = 0, i = A.size() - 1, j = B.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += A[i--];
            if (j >= 0) carry += B[j--];
            res.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
