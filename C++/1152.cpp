__________________________________________________________________________________________________
class Solution {
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
public:
  vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
    int n=username.size();
    map<vector<string>, set<string> > st;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        for(int k=j+1;k<n;k++){
          if(username[i]!=username[j]) continue;
          if(username[i]!=username[k]) continue;
          if(username[j]!=username[k]) continue;
          using P = pair<int, string>;
          vector<P> vp;
          vp.emplace_back(timestamp[i],website[i]);
          vp.emplace_back(timestamp[j],website[j]);
          vp.emplace_back(timestamp[k],website[k]);
          sort(vp.begin(),vp.end());
          st[vector<string>({vp[0].second,vp[1].second,vp[2].second})]
            .emplace(username[i]);
        }
      }
    }
    int ans=0;
    for(auto p:st) chmax(ans,(int)p.second.size());
    for(auto p:st) if((int)p.second.size()==ans) return p.first;
    return {};
  }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
