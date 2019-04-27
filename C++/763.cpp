__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
  vector<int> partitionLabels(string S) {
    vector<int> rez;
    vector<int> farest(26, -1);
    for (int i = 0; i < S.size(); ++i) farest[S[i] - 'a'] = i;
    for (int i = 0, cur = -1; i < S.size(); ++i) {
      cur = max(cur, farest[S[i] - 'a']);
      if (cur == i) rez.push_back(i + 1);  
    }
    for (int i = rez.size() - 1; i > 0; --i) rez[i] -= rez[i - 1];
    return rez;
  }
};
__________________________________________________________________________________________________
sample 8852 kb submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    std::vector<int> partitionLabels(const std::string& S) {
        std::array<int, 256> m = {0};
        for (int i = 0; i < S.size(); ++i) {
            m[S[i]] = i;
        }
        int lo = 0;
        int hi = 0;
        std::vector<int> res;
        res.reserve(S.size());
        for (int i = 0; i < S.size(); ++i) {
            hi = std::max(hi, m[S[i]]);
            if (i == hi) {
                res.push_back(hi - lo + 1);
                lo = i + 1;
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
