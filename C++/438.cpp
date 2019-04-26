__________________________________________________________________________________________________
sample 24 ms submission
auto _=[](){ios::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if(p.size()>s.size()) return ret;
        vector<int> map(128,0);
        for(char c:p) map[c]++;
        
        int begin=0,end=0,cnt=p.size();
        while(end<s.size()){
            if(map[s[end++]]-->0) cnt--;
            while(cnt==0){
                if(end-begin==p.size()) ret.push_back(begin);
                if(map[s[begin++]]++==0) cnt++;
            }
        }
        return ret;
    }
};
__________________________________________________________________________________________________
sample 10244 kb submission
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int >res;
        int n=s.length();
        int k=p.length();
        int a[26]={0};
        for(char c:p)
            a[c-'a']++;
        for(int i=0;i<n-k+1;i++){
            int b[26]={0};
            int flag=0;
         for(int j=i;j<i+k;j++){
             b[s[j]-'a']++;
         }
            for(int j=0;j<26;j++)
                if(a[j]!=b[j])
                    flag=1;
            if(flag!=1)
                res.push_back(i);
        }
        
        return res;
        
    }
};
__________________________________________________________________________________________________
