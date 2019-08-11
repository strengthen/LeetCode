__________________________________________________________________________________________________
class Solution {
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

public:
  int minSwaps(vector<int>& data) {
    int n=data.size();
    vector<int> sum(n+1,0);
    for(int i=0;i<n;i++) sum[i+1]=sum[i]+data[i];
    int cnt=sum[n];
    int ans=n;
    for(int i=0;i+cnt<=n;i++)
      chmin(ans,cnt-(sum[i+cnt]-sum[i]));
    return ans;
  }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
