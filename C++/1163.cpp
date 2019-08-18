__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    string lastSubstring(string S) {
        double mx = 0.0, pre = 0.0;
        int idx = 0, n = S.length();
        for(int i = n - 1; i > -1; --i) {
            double cur = pre / 26.0 + S[i] - 'a';
            if (cur > mx) {
                mx = cur;
                idx = i;
            }
            pre = cur;
        }
        return S.substr(idx);
    }
};
__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
    typedef long double ld;
public:
    string lastSubstring(string s) {
        int N = s.size();
        int idx = N;
        vector<double> val(N+1, 0.0);
        double maxv = 0.0;
        for (int i=s.size()-1; i>-1; i--) {
            val[i] = val[i+1] / 26.0 + s[i] - 'a' + 1;
            if (val[i] > maxv) {
                idx = i;
                maxv = val[i];
            }
        }
        return s.substr(idx);
    }
};
__________________________________________________________________________________________________
