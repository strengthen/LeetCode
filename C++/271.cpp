__________________________________________________________________________________________________
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto a : strs) {
            res.append(to_string(a.size())).append("/").append(a);
        }
        return res;
    }
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            auto found = s.find("/", i);
            int len = stoi(s.substr(i, found - i));
            res.push_back(s.substr(found + 1, len));
            i = found + len + 1;
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto a : strs) {
            res.append(to_string(a.size())).append("/").append(a);
        }
        return res;
    }
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        while (!s.empty()) {
            int found = s.find("/");
            int len = stoi(s.substr(0, found));
            s = s.substr(found + 1);
            res.push_back(s.substr(0, len));
            s = s.substr(len);
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (string str : strs) res += str + '\0';
        return res;
    }
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        stringstream ss(s);
        string t;
        while (getline(ss, t, '\0')) {
            res.push_back(t);
        }
        return res;
    }
};