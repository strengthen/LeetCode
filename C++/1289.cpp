__________________________________________________________________________________________________
sample 8 ms submission
static auto _______ = [](){
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        return 0;
}();

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int row = a.size(), col = a[0].size(), c1, c2, p1, p2;
        if (col == 1) return 0;
        for (int i = 0; i < row; i++, p1 = 0, p2 = 1) {
            if (a[i][0] > a[i][1]) p2 = 0, p1 = 1;
            for (int j = 0; j < col; j++) {
                if (i > 0)  {
                    if (c1 == j) a[i][j] += a[i - 1][c2];
                    else a[i][j] += a[i - 1][c1];                    
                }
                if (j > 1) {
                    if (a[i][j] < a[i][p1] && a[i][j] < a[i][p2]) p2 = p1, p1 = j;
                    else if (a[i][j] < a[i][p2]) p2 = j;                    
                }
            }
            c1 = p1, c2 = p2;
        }
        return *min_element(a[row - 1].begin(), a[row - 1].end());
    }
};
__________________________________________________________________________________________________
sample 16 ms submission
#define INF 20000
int func(vector<vector<int> > &A,int n,int rno,int pindx,vector<vector<int> > &dp){
    if(rno>=n){
        return 0;
    }
    
    if(pindx!=-1 && dp[rno][pindx] !=-1){
        return dp[rno][pindx];
    }
    
    int ans=20000;
    for(int i=0;i<n;i++){
        if(i==pindx){
            continue;
        }
        int cur=A[rno][i];
        ans = min(ans,cur+func(A,n,rno+1,i,dp));
    }
    if(pindx!=-1)
    return dp[rno][pindx]=ans;
    return ans;
}


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=A.size();
        vector<vector<int> > dp(n,vector<int> (n,-1));
        //return func(A,n,0,-1,dp);
        for(int j=n-1;j>=0;j--){
            dp[n-1][j]=A[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> lmin(n,INF);
            vector<int> rmin(n,INF);
            
            for(int k=1;k<n;k++){
                lmin[k]=min(lmin[k-1],dp[i+1][k-1]);
            }
            for(int k=n-2;k>=0;k--){
                rmin[k]=min(rmin[k+1],dp[i+1][k+1]);
            }
            
            for(int j=n-1;j>=0;j--){
                int mini = min(lmin[j],rmin[j]);
                dp[i][j] = mini+A[i][j];
            }
        }
        int ans=INF;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};

__________________________________________________________________________________________________
