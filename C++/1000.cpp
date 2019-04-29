__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int mergeStones(const vector<int>& stones, const int K) {
        const int N = stones.size();
        if ((N - 1) % (K - 1) != 0) return -1;
        vector<vector<int> > dp(N, vector<int>(N, 0));
        
        // sum.at(i) = stones.at(0) + ... stones.at(i - 1)
        vector<int> sum(N + 1, 0);
        for (int i = 0; i < N; ++i) sum.at(i + 1) = sum.at(i) + stones.at(i);
        
        for (int len = K; len <= N; ++len) {
            for (int a = 0; a + len <= N; ++a) {
                // a, ..., a + len - 1
                int tmp = INT_MAX;
                for (int mid = a; mid < a + len - 1; mid += K - 1)
                    tmp = min(tmp, dp.at(a).at(mid) + dp.at(mid + 1).at(a + len - 1));
                dp.at(a).at(a + len - 1) = tmp;
                if ((len - 1) % (K - 1) == 0)
                    dp.at(a).at(a + len - 1) += sum.at(a + len) - sum.at(a);
            }
        }
        
        return dp.at(0).at(N - 1);
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if((n-1)%(K-1))return -1;
        vector<int> sum(n+1,0);
        for(int i = 1;i<n+1;i++){
            sum[i]=sum[i-1]+stones[i-1];
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int len = K;len<=n;len++){
            for(int i = 0;i+len<=n;i++){
                int j = i+len-1;
                dp[i][j]=INT_MAX;
                for(int t = i;t<j;t+=K-1)
                    dp[i][j]=min(dp[i][j],dp[i][t]+dp[t+1][j]);
                if((j-i)%(K-1)==0)
                    dp[i][j]+=sum[j+1]-sum[i];
            }
        }
        return dp[0][n-1];
        
        
    }
};
__________________________________________________________________________________________________
