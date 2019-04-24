__________________________________________________________________________________________________
sample 4 ms submission
static int lambda_0 = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] ={0}, m2[256] = {0};
        for(int i = 0; i < s.size(); i ++)
        {
            if (m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        
        return true;
    }
};
__________________________________________________________________________________________________
sample 8612 kb submission
class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int m1[256]={0};
        int m2[256]={0};
        for(int i=0;i<s.size();++i){
            if(m1[s[i]]!=m2[t[i]])return false;
            m1[s[i]]=i+1;
            m2[t[i]]=i+1;
        }
        return true;
    }
};
__________________________________________________________________________________________________
