__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
 public:
  int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    size_t n = A.size();
    vector<int> aa(n);
    aa[0] = A[0];
    for (size_t i = 1; i < n; ++i) {
      aa[i] = aa[i - 1] + A[i];
    }

    int res = aa[L + M - 1];
    int ll = aa[L - 1];
    int mm = aa[M - 1];
    for (size_t i = L + M; i < n; ++i) {
      ll = max(ll, aa[i - M] - aa[i - L - M]);
      mm = max(mm, aa[i - L] - aa[i - L - M]);
      res = max(max(res, ll + aa[i] - aa[i - M]), mm + aa[i] - aa[i - L]);
    }
    return res;
  }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution
{
public:
  int maxSumTwoNoOverlap(vector<int> &A, int L, int M)
  {
    if (A.size() == 0)
      return -1;

    int ans = max(maxSumHelper(A, L, M), maxSumHelper(A, M, L));

    return ans;
  }

  int maxSumHelper(vector<int> &A, int L, int M)
  {
    int currLeftSum = 0;
    int currRightSum = 0;

    vector<int> leftSum(A.size() + 1, 0);
    vector<int> rightSum(A.size() + 1, 0);

    for (int i = 0, j = A.size() - 1; i < A.size(); i++, j--)
    {
      currLeftSum += A[i];
      currRightSum += A[j];

      leftSum[i + 1] = max(leftSum[i], currLeftSum);
      rightSum[j] = max(rightSum[j + 1], currRightSum);

      if (i + 1 >= L)
        currLeftSum -= A[i - L + 1];
      if (i + 1 >= M)
        currRightSum -= A[j + M - 1];
    }

    int maxSum = INT_MIN;
    for (int i = 0; i < A.size() + 1; i++)
    {
      int currSum = leftSum[i] + rightSum[i];
      maxSum = max(currSum, maxSum);
    }

    return maxSum;
  }
};
__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        //use two pointers
        int n = A.size();
        //1. build sums first
        vector<int> sums(n, 0);
        sums[0] = A[0];
        for(int i = 1; i < n; ++i){
            sums[i] = sums[i-1] + A[i];
        }
        //case 1: L & M
        int maxSum = 0;
        int lSum = 0;
        int rSum = 0;
        for(int r = 0; r + M - 1 < n; ++r){
            rSum = sums[r + M - 1] - (r == 0 ? 0 : sums[r-1]);
            for(int l = 0; l + L - 1 < r; ++l){
                lSum = sums[l + L - 1] - (l == 0 ? 0 : sums[l-1]);
                maxSum = max(maxSum, lSum + rSum);
            }
        }
        //cout <<"maxSum="<<maxSum<<endl;
        //case 1: M & L
        for(int r = 0; r + L - 1 < n; ++r){
            rSum = sums[r + L - 1] - (r == 0 ? 0 : sums[r-1]);
            for(int l = 0; l + M - 1 < r; ++l){
                lSum = sums[l + M - 1] - (l == 0 ? 0 : sums[l-1]);
                maxSum = max(maxSum, lSum + rSum);
            }
        }
        //cout <<"maxSum="<<maxSum<<endl;
        return maxSum;
    }
};