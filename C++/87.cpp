__________________________________________________________________________________________________
4ms
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;
            
        int len = s1.length();
        int count[26] = {0};
        for(int i=0; i<len; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return false;
        }
        
        for(int i=1; i < len; i++)
        {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
};
__________________________________________________________________________________________________
7972 kb
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        int l = s1.size();
        bool dp[l+1][l][l];
        memset(dp, false, sizeof(dp));
        
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        
        for (int len = 2; len <= l; len++) {
            for (int i = 0; i <= l - len; i++) {
                for (int j = 0; j <= l - len; j++) {
                    for (int k = 1; k < len; k++) {
                        if (dp[len][i][j]) break;
                        // cout << k << " " << i << " " << j << "\n";
                        dp[len][i][j] = (dp[k][i][j] && dp[len-k][i+k][j+k]) || 
                                        (dp[k][i][j+len-k] && dp[len-k][i+k][j]);
                    }
                }
            }
        }
        return dp[l][0][0];
    }
};
__________________________________________________________________________________________________
