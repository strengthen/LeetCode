__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
   int getMoneyAmount(int n) {
        vector<vector<int>> cache(n+1, vector<int>(n+1, 0));
        return cost(cache, 1, n);
    }
    
    int cost(vector<vector<int>>& v, int l, int r) {
        if (l >= r) return 0;
        if (v[l][r] != 0) return v[l][r];
        int res = INT_MAX;
        int start = l + (r - l) / 2;
        for (int i = start; i <= r; ++i) {
            int lc = cost(v, l, i-1);
            int rc = cost(v, i+1, r);
            int tmp = i + std::max(lc, rc);
            res = std::min(res, tmp);
            if (lc >= rc) break;
        }
        v[l][r] = res;
        return res;
    }
};
__________________________________________________________________________________________________
sample 8256 kb submission
class Solution {
public:
    int getMoneyAmount(int n) {
        
        int dp[n+5][n+5];
        for(int len=0;len<n;len++)
            for(int i =1;i+len<=n;i++){
                int j=i+len;
                if(len==0)
                    dp[i][j]=0;
                else if(len==1)
                    dp[i][j] = i;
                else{
                    int minx = min(i + dp[i+1][j], dp[i][j-1] + j);
                    for(int k=i+1;k<j;k++)
                        minx = min(minx, k + max(dp[i][k-1], dp[k+1][j]));
                    dp[i][j] = minx;
                }
            }
        
        return dp[1][n];
    }
};
__________________________________________________________________________________________________
