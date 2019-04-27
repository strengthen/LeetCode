__________________________________________________________________________________________________
sample 20 ms submission
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for(int i=0; i<A.size(); i++){
            if(abs(A[i]-i)>1) return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
sample 12444 kb submission
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        if (A.size() <= 2) {
            return true;
        }
        for (int i = 0; i < A.size()-2; i++) {
            for (int j = i+2; j < A.size(); j++) {
                if (A[i] > A[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
