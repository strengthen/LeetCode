__________________________________________________________________________________________________
4ms
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> DP(s.size(),0);
        int min_len=numeric_limits<int>::max();
        int max_len=0;
        unordered_set<string> dict;
        for(auto&s:wordDict){
            dict.insert(s);
            min_len = std::min(min_len,int(s.size()));
            max_len = std::max(max_len,int(s.size()));
        }
        for(int i=0;i<s.size();++i){
            if(i+1<min_len) DP[i] = 0;
            else{
                if(dict.count(s.substr(0,i+1))) DP[i] = 1;
                else{
                    for(int k=min_len;k<=max_len&&i-k+1>=min_len;++k){
                        DP[i] = (dict.count(s.substr(i-k+1,k)))?(DP[i-k]):0;
                        if(DP[i]) break;
                    }
                }
            }
        }
        return DP[s.size()-1];
    }
};
__________________________________________________________________________________________________
8668 kb
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool* p = new bool[s.size()+1];
        memset(p, 0, sizeof(bool)*(s.size()+1));
        p[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                if (wordDict[j].size() > i) continue;
                int len = wordDict[j].size();
                if (wordDict[j].compare(s.substr(i-len,len)) == 0) {
                    p[i] |= p[i-len];
                }
            }
        }
        bool result = p[s.size()];
        delete[] p;
        return result;
    }
};
__________________________________________________________________________________________________
