__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) 
    {
        int mod = (int)1e9 + 7;
        int dp[n+1][7]={0};
        for(int i=0;i<6;i++)
            dp[1][i]=1;
        dp[1][6]=6;
        
        for(int i=2;i<=n;i++)
        {
            int count=0;
            for(int j=0;j<6;j++)
            {
                dp[i][j]=dp[i-1][6];
                if(i-rollMax[j]==1)
                    dp[i][j]--;
                if(i-rollMax[j]>=2)
                {
                    int num=dp[i-rollMax[j]-1][6]-dp[i-rollMax[j]-1][j];
                    dp[i][j]=((dp[i][j]-num)%mod+mod)%mod;
                }
                count=(count+dp[i][j])%mod;
            }
            dp[i][6]=count;
        }
        return dp[n][6];
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int dieSimulator(int n, vector<int>& r) {
        int m=(int)(1e9+7);
        long long int dp[n][7];
        for(int i=0;i<6;i++)dp[0][i]=1;
        dp[0][6]=6;
        for(int i=1;i<n;i++){
            long long int sum=0;
            for(int j=0;j<6;j++){
                dp[i][j]=dp[i-1][6];
                if(i-r[j]<0){
                    sum=(sum+dp[i][j])%m;
                }
                else{
                    if(i-r[j]-1>=0){
                        dp[i][j]=(dp[i][j]-(dp[i-r[j]-1][6]-dp[i-r[j]-1][j]))%m+m;
                    }
                    else dp[i][j]=(dp[i][j]-1)%m;
                    sum=(sum+dp[i][j])%m;
                }
            }
            dp[i][6]=sum;
        }
        return dp[n-1][6];
        
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
    const int c = pow(10, 9) + 7;
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        
        vector<vector<int>> dp(n + 1, vector<int>(7, 1));
        dp[1][6] = 6;
        fill(dp[0].begin(), dp[0].end() - 1, 0);
        
        for(int i = 2; i <= n; i++) {
            dp[i][6] = 0;
            for(int j = 0; j < 6; j++) {
                dp[i][j] = dp[i - 1][6];
                if(i > rollMax[j]) {
                    dp[i][j] = (dp[i][j] - (dp[i - rollMax[j] - 1][6] - dp[i - rollMax[j] - 1][j])) % c;
                }
                dp[i][6] = (dp[i][6] + dp[i][j]) % c;
                if(dp[i][6] < 0) dp[i][6] += c;
            }
        }
        return dp.back().back();
    }
};