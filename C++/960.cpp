__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        // variant of longest increasing subsequence (LIS, No.300)
        int m = A.size(), n = A[0].size(), maxLen = 0;
        vector<int> dp(n, 1);
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                for (int k = 0; k < m; k++) {
                    if (A[k][i] > A[k][j]) break;
                    if (k == m-1) dp[j] = max(dp[j], dp[i]+1);
                }
            }
            maxLen = max(maxLen, dp[j]);
        }
        return n - maxLen;
    }
};
__________________________________________________________________________________________________
sample 10600 kb submission
class Solution {
    
public:
    int minDeletionSize(vector<string>& A) {
        vector<int> sequence(A[0].size(), 1);
        
        for(int i = 0; i < A[0].size(); i++){
            for(int j = 0; j < i; j++){
                for(int k = 0; k <= A.size(); k++){
                    if(k == A.size()) sequence[i] = max(sequence[i], sequence[j] + 1);
                    else if(A[k][i] < A[k][j]) break;
                }
            }
        }
        
        return A[0].size() - *max_element(begin(sequence),end(sequence));
    }
};
__________________________________________________________________________________________________
