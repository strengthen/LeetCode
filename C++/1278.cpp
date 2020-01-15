__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int dp[110][110], pan[110][110];
    void update(int &x, int y) {
        if (x == -1 || x > y) x = y;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        memset(pan, -1, sizeof(pan));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) pan[i][j] = 0;
                else if (i + 1 == j) {
                    pan[i][j] = (s[i] == s[j] ? 0 : 1);
                } else {
                    pan[i][j] = (s[i] == s[j] ? 0 : 1) + pan[i + 1][j - 1];
                }
            }
        }
        
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i && j < k; j++) {
                if (dp[i][j] == -1) continue;
                for (int l = i; l < n; l++) {
                    update(dp[l + 1][j + 1], dp[i][j] + pan[i][l]);
                }
            }
        }
        return dp[n][k];
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
 
class Solution {
public:
    int solve(string &s,int l,int r,int k,vector<vector<int> >&cost,vector<vector<int> >&vec)
    {
        if(l>r)return 1011;
        if(k==0 &&l<=r)return cost[l][r];
        int mn=1011;   
        if(vec[l][k]!=-1)return vec[l][k];
        for(int i=l;i<=r;i++)
        {
            mn=min(mn,cost[l][i]+solve(s,i+1,r,k-1,cost,vec));
        }
        return vec[l][k]=mn;
    }
    int palindromePartition(string s, int k) {
       int n=s.length();
        vector<vector<int> >cost(n,vector<int>(n,1));
        for(int i=0;i<n;i++)
            cost[i][i]=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
                cost[i][i+1]=0;
            else
                cost[i][i+1]=1;
        }
        for(int len=3;len<=n;len++)
        {
            for(int i=0;i<n-len+1;i++)
            {
                int j=i+len-1;
                if(s[i]==s[j])cost[i][j]=cost[i+1][j-1];
                else
                    cost[i][j]=cost[i+1][j-1]+1;
            }
        }
        vector<vector<int> >vec(n+1,vector<int>(k+1,-1));
            return solve(s,0,n-1,k-1,cost,vec);
    }
};
__________________________________________________________________________________________________
