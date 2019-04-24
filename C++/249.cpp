__________________________________________________________________________________________________
// Correct but complicated
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;
        unordered_map<string, multiset<string>> m;
        for (auto a : strings) {
            bool b = false;
            for (auto it = m.begin(); it != m.end(); ++it) {
                if (isShifted(it->first, a)) {
                    it->second.insert(a);
                    b = true;
                }
            }
            if (!b) m[a] = {a};
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(vector<string>(it->second.begin(), it->second.end()));
        }
        return res;
    }
    bool isShifted(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int diff = (s1[0] + 26 - s2[0]) % 26;
        for (int i = 1; i < s1.size(); ++i) {
            if ((s1[i] + 26 - s2[i]) % 26 != diff) return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;
        unordered_map<string, multiset<string>> m;
        for (auto a : strings) {
            string t = "";
            for (char c : a) {
                t += to_string((c + 26 - a[0]) % 26) + ",";
            }
            m[t].insert(a);
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(vector<string>(it->second.begin(), it->second.end()));
        }
        return res;
    }
};
__________________________________________________________________________________________________
