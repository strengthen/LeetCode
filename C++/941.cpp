__________________________________________________________________________________________________
sample 12 ms submission
static const int _x_ = [] () { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; } ();

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        bool found_apex = false;
        if (A.size() > 2) {
            for (int i = 1; i < A.size() - 1; ++i) {
                if (found_apex) {
                    if (A[i - 1] <= A[i] || A[i] <= A[i + 1]) {
                        return false;
                    }
                }
                else {
                    if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
                        found_apex = true;
                    }
                    else if (A[i - 1] >= A[i] || A[i] >= A[i + 1]) {
                        return false;
                    }
                }
            }
        }
        return found_apex;        
    }
};
__________________________________________________________________________________________________
sample 10452 kb submission
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3) return false;
        if(A[0] >= A[1]) return false;
        int i = 0;
        while(i+1 < A.size() && A[i] < A[i+1]) i++;
        // now i+1 = n or A[i] >= A[i+1]
        if(i+1 == A.size()) return false;
        if(A[i] == A[i+1]) return false;
        
        // now A[i] > A[i+1]
        for(int k = i; k < A.size() -1; k++) {
            if(A[k] <= A[k+1]) return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
