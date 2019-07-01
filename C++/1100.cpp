__________________________________________________________________________________________________
int F[10010][26];

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; ++ i)
        {
            for (int j = 0; j < 26; ++ j)
                F[i+1][j] = F[i][j] + (s[i] == j+'a');
        }
        int ret = 0;
        for (int i = k; i <= n; ++ i)
        {
            int flag = 0;
            for (int j = 0; j < 26; ++ j)
                if (F[i][j]-F[i-k][j] >= 2) flag = 1;
            if (!flag) ret ++;
        }
        return ret;
    }
};

__________________________________________________________________________________________________
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int n=S.length();
        int cnt[30], fail=0;
        memset(cnt, 0, sizeof(cnt));
        
        if (n<K) return 0;
        
        int ans=0;
        for (int i=0; i<K; i++){
            int c=S[i]-'a';
            ++cnt[c];
            if (cnt[c]==2) ++fail;
        }
        if (fail==0) ++ans;
        
        for (int i=K; i<n; i++){
            int c=S[i]-'a';
            ++cnt[c];
            if (cnt[c]==2) ++fail;
            c=S[i-K]-'a';
            --cnt[c];
            if (cnt[c]==1) --fail;
            if (fail==0) ++ans;
        }
        
        return ans;
    }
};

__________________________________________________________________________________________________
