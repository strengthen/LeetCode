__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    bool repeatedSubstringPattern(string& s) {
        int i = 0, j = 1, n = s.size();
        vector<int> dp(n + 1);
        while (j < n) {
            if (s[i] == s[j]) {
                dp[++j] = ++i;
            } else if (i) {
                i = dp[i];
            } else {
                ++j;
            }
        }
        return dp[n] and dp[n] % (n - dp[n]) == 0;
    }
};
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
__________________________________________________________________________________________________
sample 13024 kb submission
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        if(s.size() <=1){return false;}
        string buf = "";
        
        for(int i =0; i < s.size();i++){
            
            buf+=s[i];
            if(buf.size()> s.size()/2){return false;}
            if(s.size()%buf.size() == 0){
                
                int j = i+1;
                int k = 0;
                
                while(j < s.size()){
                    if(s[j] != buf[k]){break;}
                    j++;
                    k = (k+1)%buf.size();
                }
                
                if(j == s.size()){return true;}
            }
        }
        
        return false;
    }
};
__________________________________________________________________________________________________
