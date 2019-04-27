__________________________________________________________________________________________________
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int n = S.size();
        string res = "";
        vector<bool> bold(n, false);      
        for (string word : words) {
            int len = word.size();
            for (int i = 0; i <= n - len; ++i) {
                if (S[i] == word[0] && S.substr(i, len) == word) {
                    for (int j = i; j < i + len; ++j) bold[j] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (bold[i]) {
                if (i == 0 || !bold[i - 1]) res += "<b>";
                res.push_back(S[i]);
                if (i == n - 1 || !bold[i + 1]) res += "</b>";
            } else {
                res.push_back(S[i]);
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int n = S.size();
        string res = "";
        unordered_set<int> bold;      
        for (string word : words) {
            int len = word.size();
            for (int i = 0; i <= n - len; ++i) {
                if (S[i] == word[0] && S.substr(i, len) == word) {
                    for (int j = i; j < i + len; ++j) bold.insert(j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (bold.count(i) && !bold.count(i - 1)) res += "<b>";
            res.push_back(S[i]);
            if (bold.count(i) && !bold.count(i + 1)) res += "</b>";
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int n = S.size(), end = 0;
        string res = "";
        vector<bool> bold(n, false);      
        for (int i = 0; i < n; ++i) {
            for (string word : words) {
                int len = word.size();
                if (i + len <= n && S.substr(i, len) == word) {
                    end = max(end, i + len);
                }
            }
            bold[i] = end > i;
        }
        for (int i = 0; i < n; ++i) {
            if (!bold[i]) {
                res.push_back(S[i]);
                continue;
            }
            int j = i;
            while (j < n && bold[j]) ++j;
            res += "<b>" + S.substr(i, j - i) + "</b>";
            i = j - 1;
        }
        return res;
    }
};