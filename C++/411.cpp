__________________________________________________________________________________________________
class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        if (dictionary.empty()) return to_string((int)target.size());
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
        q = generate(target);
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            bool no_conflict = true;
            for (string word : dictionary) {
                if (valid(word, t.second)) {
                    no_conflict = false;
                    break;
                }
            }
            if (no_conflict) return t.second;
        }
        return "";
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> generate(string target) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> res;
        for (int i = 0; i < pow(2, target.size()); ++i) {
            string out = "";
            int cnt = 0, size = 0;
            for (int j = 0; j < target.size(); ++j) {
                if ((i >> j) & 1) ++cnt;
                else {
                    if (cnt != 0) {
                        out += to_string(cnt);
                        cnt = 0;
                        ++size;
                    }
                    out += target[j];
                    ++size;
                }
            }
            if (cnt > 0) {
                out += to_string(cnt);
                ++size;
            }
            res.push({size, out});
        }
        return res;
    }
    
    bool valid(string word, string abbr) {
        int m = word.size(), n = abbr.size(), p = 0, cnt = 0;
        for (int i = 0; i < abbr.size(); ++i) {
            if (abbr[i] >= '0' && abbr[i] <= '9') {
                if (cnt == 0 && abbr[i] == '0') return false;
                cnt = 10 * cnt + abbr[i] - '0';
            } else {
                p += cnt;
                if (p >= m || word[p++] != abbr[i]) return false;
                cnt = 0;
            }
        }
        return p + cnt == m;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
