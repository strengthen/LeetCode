__________________________________________________________________________________________________
class Solution {
  template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
  template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


  template<typename T>
  vector<T> compress(vector<T> v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    return v;
  }

  template<typename T>
  map<T, int> dict(const vector<T> &v){
    map<T, int> res;
    for(int i=0;i<(int)v.size();i++)
      res[v[i]]=i;
    return res;
  }

  //INSERT ABOVE HERE
public:
  bool canConvert(string str1, string str2) {
    if(str1==str2) return true;
    if(compress(vector<char>(str2.begin(),str2.end())).size()==26u)
      return false;

    int n=str1.size();
    vector< set<int> > G(26);
    for(int i=0;i<n;i++)
      G[str1[i]-'a'].emplace(str2[i]-'a');
    for(auto s:G) if(s.size()>=2u) return false;

    return true;
  }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
