__________________________________________________________________________________________________
4ms
class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size(), n = p.size();
        int i = 0, j = 0;
        bool dp[n+1][m+1];                                       // i - n - p, j - m - s
        memset(dp, false, sizeof(bool)*(m+1)*(n+1));             // i at string corresponds with i+1 at dp matrix
        dp[0][0] = true;
        while (j++ < n){                                         // scan * while i = 0
            if (j > 1 && p[j-1] == '*') dp[j][0] = dp[j-2][0];
        }
        while (i++ < m){
            j = 0;
            while (j++ < n){
                if (p[j-1] == s[i-1] || p[j-1] == '.') dp[j][i] = dp[j-1][i-1];       // if not * but match
                else if (p[j-1] == '*'){                                              // if * |
                    if (p[j-2] != s[i-1] && p[j-2] != '.') dp[j][i] = dp[j-2][i];     //      | not match
                    else dp[j][i] = (dp[j-2][i] || dp[j-1][i] || dp[j][i-1]);         //      | match
                }
            }
        }
        return dp[n][m];
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i=0; i<=m; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(p[j-1] == '*')
                {
                    if(j>=2 && dp[i][j-2])
                        dp[i][j] = true; // repeat 0 
                    if(j>=2 && i>=1)
                        if(p[j-2] == s[i-1] || p[j-2] == '.')
                            if(dp[i-1][j] == true)
                                dp[i][j] = true;
                }
                else 
                {
                    if(i>=1 && (s[i-1]==p[j-1] || p[j-1] == '.')) 
                        dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    bool isMatch(string s, string p) 
    {
                
        dp.resize(s.size() + 1);
        for(auto& it : dp)
        {
            it.resize(p.size(), -1);
        }
                
        return helper(s, 0, p, 0);
        
    }
private:    
    vector<vector<int>> dp;
    int real_end;
    
    bool helper(const string& S, int si, const string& P, int pi)
    {        
        if(si > S.size())
        {
            return pi >= P.size();
        }
        
        if(pi >= P.size())
        {
            return si >= S.size();
        }
        
        if(dp[si][pi] != -1)
        {
            return dp[si][pi] == 1;
        }
        
        char s = si < S.size() ? S[si] : 0;
        char p = P[pi];
        
        bool ret = false;
        if(s != 0 && (s == p || p == '.'))
        {
            ret = helper(S, si + 1, P, pi + 1);
        }                
        else if(p == '*')
        {
            char prev = pi > 0 ? P[pi-1] : 0;
            if(prev == 0)
            {
                ret = false;
            }
            else
            {
                ret =  helper(S, si, P, pi + 1);
                if(prev == '.' || prev == s)
                {
                    ret |= helper(S, si + 1, P, pi);         
                }
            }            
        }
        
        if(pi < P.size() - 1 && P[pi + 1] == '*')
        {
            ret |= helper(S, si, P, pi + 2);
        }
        
        dp[si][pi] =  ret ? 1 : 0;
        return ret;
        
    }
};
__________________________________________________________________________________________________
8228 kb
static int pre = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	bool isMatchRecursive(const string& s, const string& p, int strIndex, int patternIndex) {
		while (strIndex < s.size() && patternIndex < static_cast<int>(p.size() - 1)) {
			if (p[patternIndex + 1] != '*') {
				if (p[patternIndex] != '.') {
					if (s[strIndex] == p[patternIndex]) {
						strIndex++;
						patternIndex++;
					}
					else {
						return false;
					}
				}
				else {
					strIndex++;
					patternIndex++;
				}
			}
			else {
				if (p[patternIndex] != '.') {
					while (true) {
						bool success = isMatchRecursive(s, p, strIndex, patternIndex + 2);
						if (success)
							return true;
						else if (strIndex < s.size() && s[strIndex] == p[patternIndex])
							strIndex++;
						else
							break;
					}
					patternIndex += 2;
				}
				else {
					do {
						bool success = isMatchRecursive(s, p, strIndex, patternIndex + 2);
						if (success)
							return true;
						else
							strIndex++;
					} while (strIndex < s.size());
					patternIndex += 2;
				}
			}
		}
		if (strIndex < s.size() && patternIndex == p.size() - 1) {
			if (p[patternIndex] != '.') {
				if (s[strIndex] == p[patternIndex]) {
					strIndex++;
					patternIndex++;
				}
				else {
					return false;
				}
			}
			else {
				strIndex++;
				patternIndex++;
			}
		}
		if (patternIndex >= p.size()) {
			if (strIndex >= s.size())
				return true;
			else
				return false;
		}
		else {
			while (patternIndex < (int)p.size() - 1) {
				if (p[patternIndex + 1] != '*') {
					return false;
				}
				else {
					patternIndex += 2;
				}
			}
			if (patternIndex == p.size() - 1) {
				return false;
			}
			return true;
		}

	}
	bool isMatch(string s, string p) {
		return isMatchRecursive(s, p, 0, 0);
	}
};
__________________________________________________________________________________________________
9084 kb 
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_l = s.length(), p_l = p.length();
        int maxn = 1000+10;
        int d[maxn][maxn];
        for(int i = 0; i<=s_l; i++){
            memset(d[i], 0, sizeof(int)*maxn);
        }
        //d[i][j]: s[i-1] and p[j-1] match
        d[0][0] = 1;
        for(int i = 0; i<=s_l; i++){
            for(int j = 0; j<=p_l; j++){
                if(j>=1 && d[i][j-1] && p[j-1]=='*') d[i][j] = 1;
                if(i>=1 && j>=2 && d[i-1][j] && p[j-1] == '*' && (s[i-1] == p[j-2] || p[j-2] == '.')) d[i][j] = 1;
                if(i>=1 && j>=1 && d[i-1][j-1] &&  (s[i-1]==p[j-1] || p[j-1] == '.')) d[i][j] = 1;
                if(j>=2 && d[i][j-2] && p[j-1] == '*') d[i][j] =1;
            }
        }
        return (bool)d[s_l][p_l];
    }
};
__________________________________________________________________________________________________
