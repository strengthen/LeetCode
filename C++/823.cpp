__________________________________________________________________________________________________
sample 24 ms submission
static int x = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        static const int cnt = 1000000007;
        sort(A.begin(), A.end());
        unordered_set<int> st(A.begin(), A.end());
        unordered_map<int, unsigned long> dp;
        unsigned long ret = 0;
        for(int i = 0; i < A.size(); ++i) {
            int n = A[i];
            int n_sqt = sqrt(n);
            unsigned long sum = 1;
            for(int j = 0; j < i; ++j) {
                int f = A[j];
                if(f > n_sqt) break;
                if(n % f != 0) continue;
                int d = n / f;
                if(st.count(d) == 0) continue;
                if(d == f) {
                    sum += (dp[d] * dp[f]);
                    sum %= cnt;
                }
                else {
                    sum += (dp[d] * dp[f] * 2);
                    sum %= cnt;
                }
            }
            ret += (dp[n] = sum);
            ret %= cnt;
        }
        return (int)ret;
    }
};
__________________________________________________________________________________________________
sample 9200 kb submission
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        vector<long long> dp(n, 1);
        int sum = 1;
        for(int i = 1; i < n; i++){
            int j = 0;
            int k = i-1;
            while(j <= k){
                if((long long)A[j]*A[k] < A[i])
                    j++;
                else if((long long)A[j]*A[k] > A[i])
                    k--;
                else{
                    if(j==k)
                        dp[i] += (dp[j]*dp[k])% 1000000007;
                    else
                        dp[i] += (2*dp[j]*dp[k])% 1000000007;
                    dp[i] %= 1000000007;
                    j++;
                }
            }
            sum += dp[i];
            sum %= 1000000007;
        }
        return sum;
    }
};
__________________________________________________________________________________________________
