__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int lo = 0, hi = A.size() - 1, N = A.size();
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid == 0) {
                if (A[1] > A[0] && A[1] > A[2])
                    return 1;
            }
            else if (mid == N - 1) {
                if (A[N - 2] > A[N - 1] && A[N - 2] > A[N - 3])
                    return N - 2;
            }
            else if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) return mid;
            else if (A[mid] > A[mid + 1]) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
sample 9304 kb submission
static int x = [](){std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0;}();
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, r = A.size() - 1;
        
        while(l <= r)
        {
            int m = l + ((r - l) >> 1);
            if((A[m] > A[m - 1]) && (A[m] > A[m + 1]))
                return m;
            if(A[m] > A[m - 1])
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};
__________________________________________________________________________________________________
