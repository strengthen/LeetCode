__________________________________________________________________________________________________
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        for (int i = 0; i < pow(2, word.size()); ++i) {
            string out = "";
            int cnt = 0, t = i;
            for (int j = 0; j < word.size(); ++j) {
                if (t & 1 == 1) {
                    ++cnt;
                    if (j == word.size() - 1) out += to_string(cnt);
                } else {
                    if (cnt != 0) {
                        out += to_string(cnt);
                        cnt = 0;
                    }
                    out += word[j];
                }
                t >>= 1;
            }
            res.push_back(out);
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        for (int i = 0; i < pow(2, word.size()); ++i) {
            string out = "";
            int cnt = 0;
            for (int j = 0; j < word.size(); ++j) {
                if ((i >> j) & 1) ++cnt;
                else {
                    if (cnt != 0) {
                        out += to_string(cnt);
                        cnt = 0;
                    }
                    out += word[j];
                }
            }
            if (cnt > 0) out += to_string(cnt);
            res.push_back(out);
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res{word};
        helper(word, 0, res);
        return res;
    }
    void helper(string word, int pos, vector<string> &res) {
        for (int i = pos; i < word.size(); ++i) {
            for (int j = 1; i + j <= word.size(); ++j) {
                string t = word.substr(0, i);
                t += to_string(j) + word.substr(i + j);
                res.push_back(t);
                helper(t, i + 1 + to_string(j).size(), res);
            }
        }
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        helper(word, 0, 0, "", res);
        return res;
    }
    void helper(string word, int pos, int cnt, string out, vector<string> &res) {
        if (pos == word.size()) {
            if (cnt > 0) out += to_string(cnt);
            res.push_back(out);
        } else {
            helper(word, pos + 1, cnt + 1, out, res);
            helper(word, pos + 1, 0, out + (cnt > 0 ? to_string(cnt) : "") + word[pos], res);
        }
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        res.push_back(word.size() == 0 ? "" : to_string(word.size()));
        for (int i = 0; i < word.size(); ++i) {
            for (auto a : generateAbbreviations(word.substr(i + 1))) {
                string left = i > 0 ? to_string(i) : "";
                res.push_back(left + word.substr(i, 1) + a);
            }
        }
        return res;
    }
};