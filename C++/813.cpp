__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<double> current(n), next(n);

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            current[i] = static_cast<double>(sum) / (i + 1);
        }

        for (int group = 2; group <= K; ++group) {
            for (int last = group - 1; last < n - (K - group); ++last) {
                sum = A[last];
                int count = 0;
                double best = 0;
                for (int i = last - 1; i >= group - 2; --i) {
                    ++count;
                    best = max(best, static_cast<double>(sum) / count + current[i]);
                    sum += A[i];
                }
                next[last] = best;
            }
            current.swap(next);
        }
        return current.back();
    }
};
__________________________________________________________________________________________________
sample 8888 kb submission
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n  = A.size();
        vector<double> dp(n,0);
        
        double acc = 0;
        for(int i=n-1;i>=0;i--){
            acc+=A[i];
            dp[i]=acc/(n-i);
        }
        
        for(int k=0;k<K-1;k++){
            for(int i=0;i<n;i++){
                double acc = 0;
                for(int j=i;j<n-1;j++){
                    acc+=A[j];
                    dp[i]=max(dp[i],acc/(j-i+1)+dp[j+1]);
                }
            }
        }
        
        return dp[0];
    }
};
__________________________________________________________________________________________________
