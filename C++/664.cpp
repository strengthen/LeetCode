__________________________________________________________________________________________________
sample 16 ms submission
#pragma GCC optimize("O3")
static const auto __ = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
    vector<vector<int>> memo;
    vector<char> strvec;
    
    int dp(int i, int j) {
        if (i == j) return 1;
        int &memoval = memo[i][j-i-1];
        if (memoval != 0) return memoval;
        
        memoval = (strvec[j]==strvec[i])?dp(i,j-1):(1+dp(i+1,j));
        
        for (int k = i + 2; k < j; ++k) {
            if (strvec[k] == strvec[i]) {
                memoval = min(memoval, dp(i, k - 1) + dp(k + 1, j));
            }
        }
        
        return memoval;
    }
public:
    int strangePrinter(string s) {
        int slen = s.size();
        if (slen < 2) return slen;
        
        strvec.reserve(slen);
        
        strvec.push_back(s[0]);
        
        int idx = 0;
        for (auto it = next(s.begin()); it != s.end(); ++it) {
            auto ch = *it;
            if (strvec[idx] != ch) {
                strvec.push_back(ch);
                ++idx;
            }
        }
        
        int strveclen = strvec.size();
        if (strveclen < 2) return strveclen;
        
        memo.reserve(strveclen);
        for (int i = 0; i < strveclen; ++i)
            memo.emplace_back(strveclen-i-1, 0);
        
        
        //memo.assign(strveclen, vector<int>(strveclen, 0));
        
        return dp(0, strveclen-1);
    }
};
__________________________________________________________________________________________________
sample 9896 kb submission
class Solution {
public:
    int dp[110][110];
    
    int solve(int l, int r, string &s) {
        if(l > r) return 0;
        int &ret = dp[l][r];
        if(ret != -1) return ret;
        ret = solve(l+1, r, s) + 1;
        for(int i = l+1; i <= r; i++) {
            if(s[i] != s[l]) continue;
            ret = min(ret, solve(l, i-1, s) + solve(i+1, r, s));
        }
        // cout<<l<<" "<<r<<" "<<ret<<endl;
        return ret;
    }
    
    int strangePrinter(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s.size()-1, s);
    }
};
__________________________________________________________________________________________________
