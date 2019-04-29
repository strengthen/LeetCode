__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int r,c,i,j,mini=INT_MAX;
        r=v.size();
        if(r)
            c=v[0].size();
        int dp[r][c];
        for(i=0;i<c;i++){
            dp[0][i]=v[0][i];
        }
        for(i=1;i<r;i++){
            for(j=0;j<c;j++){
                if(j==0){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+v[i][j];
                }
                else if(j==c-1){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+v[i][j];
                }
                else{
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]))+v[i][j];
                }
            }
        }
        for(i=0;i<c;i++){
             mini=min(mini,dp[r-1][i]);
        }
        return mini;
    }
};
__________________________________________________________________________________________________
sample 9872 kb submission
class Solution {
public:
    int getMinBelow(const vector<vector<int>>& A, int x, int y) {
        auto &nextRow = A[y+1];
        int m = nextRow[x];
        if (x > 0) {
            m = min(m, nextRow[x-1]);
        }
        if (x < nextRow.size() - 1 ) {
            m = min(m, nextRow[x+1]);
        }
        return m;
    }
    
    int minFallingPathSum(vector<vector<int>>& A) {
        for (int y = A.size() - 2; y >=0 ; --y) {
            auto &row = A[y];
            for (int x = 0; x < row.size(); ++x) {
                row[x] += getMinBelow(A, x, y);
            }
        }
        int minPath = *min_element(A[0].begin(), A[0].end());
        return minPath;
    }
};

static const auto _____ = []()
{
    // fast IO code : this I understand
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
