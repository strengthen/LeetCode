__________________________________________________________________________________________________
sample 28 ms submission
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s == "") return 0;
        
        int slen = s.length();
        int cache[slen];
        
        for(int i = 0; i < slen; ++i)
            cache[i] = 1;
        
        for(int i = 1; i < slen; ++i) {
            int tmp = cache[i-1], cb = 1;
            if(s[i] == s[i-1]) {
                cache[i-1] = 2;
                cb = 2;
            }
            for(int j = i - 2; j >= 0; --j) {
                if(s[i] == s[j]) {
                   int old = cache[j];
                   cache[j] = 2 + tmp; 
                   cb = cache[j];
                   tmp = old;
                }
                else {
                    tmp = cache[j];
                    cache[j] = max(cb, cache[j]);
                }
            }
        }
        return cache[0];
    }
};
__________________________________________________________________________________________________
sample 9028 kb submission
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(), res = 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            int len = 0;
            for (int j = i - 1; j >= 0; j--) {
                int tmp = dp[j];
                if (s[j] == s[i]) {
                    dp[j] = len + 2;
                }
                len = max(len, tmp);
            }
        }
        for (auto i : dp)
            res = max(res, i);
        return res;
    }
};
__________________________________________________________________________________________________
