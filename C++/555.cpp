__________________________________________________________________________________________________
class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        if (strs.empty()) return "";
        string s = "", res = "a";
        int n = strs.size(), cur = 0;
        for (string str : strs) {
            string t = string(str.rbegin(), str.rend());
            s += str > t ? str : t;
        }
        for (int i = 0; i < n; ++i) {          
            string t1 = strs[i], t2 = string(t1.rbegin(), t1.rend());
            string mid = s.substr(cur + t1.size()) + s.substr(0, cur);
            for (int j = 0; j < strs[i].size(); ++j) {
                if (t1[j] >= res[0]) res = max(res, t1.substr(j) + mid + t1.substr(0, j));
                if (t2[j] >= res[0]) res = max(res, t2.substr(j) + mid + t2.substr(0, j));
            }
            cur += strs[i].size();
        }
        return res;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
