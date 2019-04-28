__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        if (words.empty()) return 0;
        
        int res = 0;
        if (s == "") {
            for (const auto& w : words) {
                if (w == "") ++res;
            }
            return res;
        }
        
        vector<pair<char, int>> counts;
        // count character runs
        for (char c : s) {
            if (counts.empty() or counts.back().first != c) {
                counts.emplace_back(c, 1);
            } else {
                ++counts.back().second;
            }
        }
        for (const string& w : words) {
            if (w == "") continue;
            
            int i = 0, count = 1, n = w.size();
            bool stretchy = true;
            for (int j = 1; j <= n; ++j) {
                if (j == n or w[j] != w[j - 1]) {
                    if (i == counts.size() or  // amount of runs don't match
                        w[j - 1] != counts[i].first or  // letters don't match
                        counts[i].second < count or  // have too many letters
                        (count < counts[i].second and counts[i].second < 3)) {
                        stretchy = false;
                        break;
                    }
                    ++i;
                    count = 0;
                }
                ++count;
            }
            if (stretchy and i == counts.size()) {
                ++res;
            }
        }
        return res;
    }
};
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
__________________________________________________________________________________________________
sample 8940 kb submission
class Solution {   
public:
    
    bool isMatch(const string& s, const string& o) {
        int i = 0, j = 0;
        while (i < s.size() && j < o.size()) {
            if (s[i++] != o[j++]) {
                return false;
            }
            // cntO means number of consecutive chars in O starting from i - 1
            // cntS means number of consecutive chars in S stargin from j - 1
            int cntO = 1, cntS = 1;
            while (i < s.size() && s[i] == s[i - 1]) {
                ++i;
                ++cntS;
            }
            while (j < o.size() && o[j] == o[j - 1]) {
                ++j;
                ++cntO;
            }
            if (cntS == cntO || (cntS >= 3 && cntS > cntO)) {
                continue;
            }
            return false;
        }
        return (i == s.size() && j == o.size());
    }
   
    
    int expressiveWords(string S, vector<string>& words) {
        
            int ret = 0;
        for (auto& word : words) {
            if (isMatch(S, word)) {
                ++ret;
            }
        }
        return ret;
    }
};
__________________________________________________________________________________________________
