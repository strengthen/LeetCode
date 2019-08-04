__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int N = nums.size();
        vector<int> A(nums), B(nums);
        int odd = 0, even = 0;
        for (int i=0; i<N-1; i++) {
            if (i%2==0) {
                if (A[i] <= A[i+1]) {
                    odd += A[i+1] - A[i] + 1;
                    A[i+1] = A[i] - 1;
                }
                if (B[i] >= B[i+1]) {
                    even += B[i] - B[i+1] + 1;
                    B[i] = B[i+1] - 1;
                }
            } else {
                if (A[i] >= A[i+1]) {
                    odd += A[i] - A[i+1] + 1;
                    A[i] = A[i+1] - 1;
                }
                if (B[i] <= B[i+1]) {
                    even += B[i+1] - B[i] + 1;
                    B[i+1] = B[i] - 1;
                }
            }
        }
        return min(odd, even);
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int movesToMakeZigzag(vector<int>& A) {
        int res[2] = {0, 0},  n = A.size(), left, right;
        for (int i = 0; i < n; ++i) {
            left = i > 0 ? A[i - 1] : 1001;
            right = i + 1 < n ? A[i + 1] : 1001;
            res[i % 2] += max(0, A[i] - min(left, right) + 1);
        }
        return min(res[0], res[1]);
    }
};
__________________________________________________________________________________________________
