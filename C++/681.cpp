__________________________________________________________________________________________________
class Solution {
public:
    string nextClosestTime(string time) {
        string res = time;
        set<int> s{time[0], time[1], time[3], time[4]};
        string str(s.begin(), s.end());
        for (int i = res.size() - 1; i >= 0; --i) {
            if (res[i] == ':') continue;
            int pos = str.find(res[i]);
            if (pos == str.size() - 1) {
                res[i] = str[0];
            } else {
                char next = str[pos + 1];
                if (i == 4) {
                    res[i] = next;
                    return res;
                } else if (i == 3 && next <= '5') {
                    res[i] = next;
                    return res; 
                } else if (i == 1 && (res[0] != '2' || (res[0] == '2' && next <= '3'))) {
                    res[i] = next;
                    return res;
                } else if (i == 0 && next <= '2') {
                    res[i] = next;
                    return res;
                }
                res[i] = str[0];
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    string nextClosestTime(string time) {
        string res = "0000";
        vector<int> v{600, 60, 10, 1};
        int found = time.find(":");
        int cur = stoi(time.substr(0, found)) * 60 + stoi(time.substr(found + 1));
        for (int i = 1, d = 0; i <= 1440; ++i) {
            int next = (cur + i) % 1440;
            for (d = 0; d < 4; ++d) {
                res[d] = '0' + next / v[d]; 
                next %= v[d];
                if (time.find(res[d]) == string::npos) break;
            }
            if (d >= 4) break;
        }
        return res.substr(0, 2) + ":" + res.substr(2);
    }
};
__________________________________________________________________________________________________
