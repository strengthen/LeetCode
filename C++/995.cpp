__________________________________________________________________________________________________
sample 44 ms submission
static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int ans = 0, acc = 0;
        for (int i = 0; i < n; ++i) {
            int a = A[i] ^ acc;
            if (a == 0) {
                if (i + K > n) {
                    return -1;
                }
                A[i] = 1;
                acc ^= 1;
                ++ans;
            } else {
                A[i] = 0;
            }
            int ik = i - K + 1;
            if (ik >= 0 && A[ik]) {
                acc ^= 1;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 15632 kb submission
class Solution {
public:

    void flipbits(vector<int> & A, int i, int j) {
        if (i < 0 || i >= A.size()) return;
        if (j < 0 || j >= A.size()) return;

        for (int k = i; k <= j; ++k)
            A[k] = !A[k];
    }
    int minKBitFlips(vector<int>& A, int K) {
        int c = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == 0)
            {
                flipbits(A, i, i + K - 1);
                ++c;
            }
        }

        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == 0) return -1;
        }

        return c;
    }
};
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________
