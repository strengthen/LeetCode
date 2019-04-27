__________________________________________________________________________________________________
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string res = "";
        int n = s.size(), end = 0;
        vector<bool> bold(n, false);
        for (int i = 0; i < n; ++i) {
            for (string word : dict) {
                int len = word.size();
                if (i + len <= n && s.substr(i, len) == word) {
                    end = max(end, i + len);
                }
            }
            bold[i] = end > i;
        }
        for (int i = 0; i < n; ++i) {
            if (!bold[i]) {
                res.push_back(s[i]);
                continue;
            }
            int j = i;
            while (j < n && bold[j]) ++j;
            res += "<b>" + s.substr(i, j - i) + "</b>";
            i = j - 1;
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string res = "";
        int n = s.size();
        unordered_set<int> bold;
        for (string word : dict) {
            int len = word.size();
            for (int i = 0; i <= n - len; ++i) {
                if (s[i] == word[0] && s.substr(i, len) == word) {
                    for (int j = i; j < i + len; ++j) bold.insert(j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (bold.count(i) && !bold.count(i - 1)) res += "<b>";
            res += s[i];
            if (bold.count(i) && !bold.count(i + 1)) res += "</b>";
        }
        return res;
    }
};
__________________________________________________________________________________________________
