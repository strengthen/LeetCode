__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        if (strs.size() <= 0)   return -1;
        int n = strs.size();
        int res = -1;
        int j;
        for (int i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j) continue;
                if (lus(strs[i], strs[j]))  break;
            }
            if (j == n)
                res = std::max(res, int(strs[i].size()));
        }
        return res;
    }
    bool lus(string& a, string& b) {
        int i = 0;
        for (auto ch: b) {
            if (i < a.size() && a[i] == ch) i++;
        }
        return i == a.size();
    }
};
__________________________________________________________________________________________________
sample 9112 kb submission
class Solution {
     bool issubstr(const string& a, const string& b) {
        if (b.size() < a.size()) return false;
        int i = 0;
        for(auto ch: b) {
            if(i < a.size() && a[i] == ch) i++;
        }
        return i == a.size();
    }
public:
    int findLUSlength(vector<string>& strs) {
       if (strs.empty()) return -1;
        int res = -1;
        for(auto i = 0; i < strs.size(); i++) {
            int j = 0;
            for(j=0; j < strs.size(); j++) {
                if(i==j) continue;
                if(issubstr(strs[i], strs[j])) break;  // strs[j] is a subsequence of strs[i]
            }
            // strs[i] is not subsequence of any the other strings.
            if(j==strs.size()) res = max(res, static_cast<int>(strs[i].size()));
        }
        return res;
    }
};
__________________________________________________________________________________________________
