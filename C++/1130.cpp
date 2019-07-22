__________________________________________________________________________________________________
const int N_MAX = 105;
const long long LL_INF = (long long) 2e18 + 5;

class Solution {
public:
    int n;
    vector<int> leaves;
    long long dp[N_MAX][N_MAX];

    long long solve(int start, int end) {
        if (end - start <= 1)
            return 0;

        long long &answer = dp[start][end];

        if (answer >= 0)
            return answer;

        answer = LL_INF;

        for (int i = start + 1; i < end; i++) {
            int left = 0, right = 0;

            for (int j = start; j < i; j++)
                left = max(left, leaves[j]);

            for (int j = i; j < end; j++)
                right = max(right, leaves[j]);

            answer = min(answer, left * right + solve(start, i) + solve(i, end));
        }

        return answer;
    }

    int mctFromLeafValues(vector<int>& arr) {
        leaves = arr;
        n = leaves.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n);
    }
};
__________________________________________________________________________________________________
class Solution {
  template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
  template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
public:
  int mctFromLeafValues(vector<int>& arr) {
    int n=arr.size();
    using ll = long long;
    const ll INF = 1e15;
    vector< vector<ll> > dp(n+1,vector<ll>(n+1,INF));
    vector< vector<ll> > val(n+1,vector<ll>(n+1,-INF));

    for(int i=0;i<=n;i++)
      for(int j=0;j<=n;j++)
        for(int k=i;k<j;k++)
          chmax(val[i][j],arr[k]);

    for(int i=0;i<n;i++) dp[i][i+1]=0;
    for(int w=2;w<=n;w++){
      for(int i=0;i+w<=n;i++){
        int j=i+w;
        //for(int k=i+1;k<j;k++) cout<<dp[i][k]<<" "<<dp[k][j]<<endl;
        for(int k=i+1;k<j;k++)
          chmin(dp[i][j],dp[i][k]+dp[k][j]+(val[i][k]*val[k][j]));
        //cout<<i<<" "<<j<<":"<<dp[i][j]<<endl;
      }
    }

    return (int)dp[0][n];
  }
};
__________________________________________________________________________________________________
