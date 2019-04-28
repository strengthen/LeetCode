__________________________________________________________________________________________________
sample 36 ms submission
class Solution {
    constexpr static int M = 1e9 + 7;
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(P + 1, vector<int>(G + 1));
        dp[0][0] = 1;
        for (int i = 0; i < group.size(); ++i) {
            const auto g1 = group[i];
            const auto p1 = profit[i];
            for (int p0 = P; p0 >= 0; --p0) {
                const auto p2 = min(p0 + p1, P);
                for (int g0 = G - g1; g0 >= 0; --g0) {
                    const auto g2 = g0 + g1;
                    dp[p2][g2] = (dp[p2][g2] + dp[p0][g0]) % M;
                }
            }
        }
        
        int res = 0;
        for (const auto t: dp[P])
            res = (res + t) % M;
        return res;
    }
};
__________________________________________________________________________________________________
sample 8628 kb submission
class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        
        int dp[101][101];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int k = 0; k < group.size(); ++k) {
        for(int i = G; i >= 0; --i) {
            for(int j = P; j >= 0; --j) {
                
                    if(i + group[k] > G)
                        continue;
                    //cout<<i<<" "<<j<<" "<<group[k]<<" "<<profit[k]<<" "<<dp[i][j]<<endl;
                    dp[i+group[k]][min(P, j + profit[k])] = (dp[i+group[k]][min(P, j + profit[k])] + dp[i][j]) % 1000000007;
                }
            }
        }
        int sum = 0;
        for(int i = 0; i <= G; ++i)
            sum = (sum + dp[i][P]) % 1000000007;
        return sum;
    }
};
__________________________________________________________________________________________________
