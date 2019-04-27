__________________________________________________________________________________________________
sample 20 ms submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
    int processidxs(vector<int> &idxs, int beg, int end) {
        if (idxs.empty()) return 0;
        
        int retval = 0;
        
        for (int idx : idxs) {
            retval += (end - idx) * (idx - beg + 1);
            beg = idx +1;
        }
        
        return retval;
    }
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int len = A.size();
        if (len < 1) return 0;
        
        int retval = 0;
        
        vector<int> idxs;
        int beg = 0;
        for (int i = 0; i < len; ++i) {
            if (A[i] > R) {
                retval += processidxs(idxs, beg, i);
                idxs.clear();
                beg = i + 1;
            }
            else if (A[i] >= L) {
                idxs.push_back(i);
            }
        }
        
        retval += processidxs(idxs, beg, len);
        
        return retval;
    }
};
__________________________________________________________________________________________________
sample 12332 kb submission
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size(), count = 0;
        int largerthanRleft = n, withinLRleft = n;
        for (int i = n-1; i >= 0; i--) {
            if (A[i] > R)
                largerthanRleft = i;
            else if (A[i] <= R && A[i] >= L) {
                count += largerthanRleft - i;
                withinLRleft = i;
            }
            else { // A[i] < L
                if (withinLRleft < largerthanRleft)
                    count += largerthanRleft - withinLRleft;
            }
        }
        return count;
    }
};
__________________________________________________________________________________________________
