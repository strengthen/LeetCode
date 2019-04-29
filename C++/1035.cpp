__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int dp[A.size() + 1][B.size() + 1];
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= A.size(); i++) {
            for(int j = 1; j <= B.size(); j++) {
                if(A[i - 1] == B[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[A.size()][B.size()];
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n1=A.size();
        int n2=B.size();
        
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=1;i<=n1;++i){
            for(int j=1;j<=n2;++j){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(A[i-1]==B[j-1]){
                    dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
                }
            }
        }
        return dp[n1][n2];
        
    }
};
__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int lenA=A.size();
        int lenB=B.size();
        if(lenA==0||lenB==0)return 0;
        vector<vector<int>> dp(lenA,vector<int>(lenB,0));
        for(int i=0;i<lenA;i++){
            if(A[i]==B[0]){
                for(int j=i;j<lenA;j++){
                    dp[j][0]=1;
                }
                break;
            }
        }
        for(int i=0;i<lenB;i++){
            if(A[0]==B[i]){
                for(int j=i;j<lenB;j++){
                    dp[0][j]=1;
                }
                break;
            }
        }
        for(int i=1;i<lenA;i++){
            for(int j=1;j<lenB;j++){
                if(A[i]==B[j]){
                    dp[i][j]=max(dp[i-1][j-1]+1,dp[i-1][j]);
                }else{
                    dp[i][j]=max(dp[i][j-1],max(dp[i-1][j],dp[i-1][j-1]));
                }
            }
        }
        return dp[lenA-1][lenB-1];
    }
};