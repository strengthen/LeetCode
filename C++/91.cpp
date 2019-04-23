__________________________________________________________________________________________________
4ms
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || (s.size() > 1 && s[0] == '0')) return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
__________________________________________________________________________________________________
8124 kb
class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0 || s.front()=='0')
            return 0;
        
        int r1=1;
        int r2=1;
        for(int i=1;i<s.size();++i)
        {
            if(s[i]=='0')
                r1=0;
            if(s[i-1]=='1' || s[i-1]=='2' && s[i]<='6')//dp[n-2]项存在
            {
                r1=r1+r2;
                r2=r1-r2;
            }
            else //dp[n-2]不存在
            {
                r2=r1;
            }
        }
        
        return r1;
    }
};
__________________________________________________________________________________________________
