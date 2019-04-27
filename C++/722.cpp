__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool comment = false;
        string s = "";
        
        for(auto &line : source) {
            int len = line.length();
            for(int i = 0; i < len; i++) {
                if(!comment and i + 1 < len and line[i] == '/' and line[i + 1] == '/') {
                    break;
                } else if(!comment and i + 1 < len  and line[i] == '/' and line[i + 1] == '*') {
                    comment = true;
                    i++; 
                } else if(comment and i + 1 < len and line[i] == '*' and line[i + 1] == '/') {
                    comment = false;
                    i++;
                } else if(!comment) {
                    s.push_back(line[i]);
                }
            }
            if(s.size() and !comment) {
                res.push_back(s);
                s.clear();
            }
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
sample 8920 kb submission
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool blocked = false;
        string out = "";
        for (string line : source) {
            for (int i = 0; i < line.size(); ++i) {
                if (!blocked) {
                    if (i == line.size() - 1) out += line[i];
                    else {
                        string t = line.substr(i, 2);
                        if (t == "/*") blocked = true, ++i;
                        else if (t == "//") break;
                        else out += line[i];
                    }
                } else {
                    if (i < line.size() - 1) {
                        string t = line.substr(i, 2);
                        if (t == "*/") blocked = false, ++i;
                    }
                }
            }
            if (!out.empty() && !blocked) {
                res.push_back(out);
                out = "";
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
