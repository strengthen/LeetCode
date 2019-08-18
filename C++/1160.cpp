__________________________________________________________________________________________________
sample 68 ms submission
class Solution {
public:
    int countCharacters(vector<string>& W, string C) {
        int r = 0;
        array<int, 26> cnt{};
        for (char c : C)
            cnt[c - 'a']++;
        for (auto &s : W) {
            if (s.size() > C.size())
                continue;
            auto t = cnt;
            bool f = true;
            for (char c : s)
                if (--t[c - 'a'] < 0) {
                    f = false;
                    break;
                }
            if (f)
                r += s.size();
        }
        return r;
    }
};
__________________________________________________________________________________________________
sample 76 ms submission
class Solution {
public:
    vector < int > cnt;
    int countCharacters(vector<string>& W, string C) {
        cnt.resize(27);
        for(int i = 0;i < C.size();++i) {
            ++cnt[C[i] - 'a'];
        }
        
        int ans = 0;
        for(int i = 0;i < W.size();++i) {
            vector < int > ccnt = cnt;
            bool ok = true;
            for(int j = 0;j < W[i].size();++j) {
                ccnt[W[i][j] - 'a']--;
                if(ccnt[W[i][j] - 'a'] < 0) {
                    ok = false;
                    break;
                }
            }
            
            if(ok) {
                ans += W[i].size();
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
