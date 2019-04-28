__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return helper(S)==helper(T);
    }
    string helper(string s)
    {
        string res="";
        for(char c:s)
        {
            if(c=='#')
            {
                if(!res.empty())
                    res.pop_back();
            }
            else
                res.push_back(c);
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 8408 kb submission
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s1;
        string s2;

        for(int i = 0; i < S.size(); ++i){
            if(S[i] == '#')
            {
                if(!s1.empty())
                    s1.resize(s1.size()-1);
            }
            else
                s1+=S[i];
        }
        
        for(int i = 0; i < T.size(); ++i){
            if(T[i] == '#')
            {
                if(!s2.empty())
                    s2.resize(s2.size()-1);
            }
            else
                s2+=T[i];
        }
        
        if(s1.size() == s2.size() && s1 == s2) return true;
        
        return false;
    }
};
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________
