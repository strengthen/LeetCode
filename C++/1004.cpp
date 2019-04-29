__________________________________________________________________________________________________
sample 28 ms submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j = 0;
        int ret = 0;
        int count = 0;
        while (j < A.size()) {
            while (i < A.size() && count > K) {
                if (i < A.size() && A[i] == 0)
                    count--;
                i++;
            }
            while (j < A.size() && count <= K) {
                if (j < A.size() && A[j] == 0)
                    count++;
                j++;
            }
            if (count > K)
                ret = max(ret, j - i - 1);
            else
                ret = max(ret, j - i);
        }
        return ret;
    }
};
__________________________________________________________________________________________________
sample 32 ms submission
static auto _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
  int longestOnes(const vector<int>& A, int K)
  {
    int res = 0;
    int zeroCount = 0;
    auto left = A.begin();
    auto right = A.begin();
    const auto& end = A.end();

    while (right != end) {
      if (*right++ == 0) {
        ++zeroCount;
        while (zeroCount > K) {
          if (*left++ == 0) {
            --zeroCount;
          }
        }
      }
      res = max(static_cast<int>(right - left), res);
    }

    return res;
  }
};
__________________________________________________________________________________________________
