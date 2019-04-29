__________________________________________________________________________________________________
sample 68 ms submission
class Solution {
public:
    string hashKey(string& w) {
        string key = w;
        for (auto& c : key) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        }
        return key;
    }
    void buildDict(vector<string>& wordlist, unordered_map<string,vector<string>>& dict) {
        for (auto& w : wordlist) {
            string key = hashKey(w);
            dict[key].push_back(w);
        }
    }
    bool matchCap(string& a, string& b) {
        for (int i = 0; i < a.size(); i++) {
            if (tolower(a[i]) != tolower(b[i]))
                return false;
        }
        return true;
    }
    string search(string& w, unordered_map<string,vector<string>>& dict) {
        string key = hashKey(w);
        if (dict.count(key) == 0)
            return "";
        for (auto& match : dict[key]) {
            if (match == w)
                return match;
        }
        for (auto& match : dict[key]) {
            if (matchCap(w, match))
                return match;
        }
        return dict[key][0];
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> res;
        unordered_map<string,vector<string>> dict;
        buildDict(wordlist, dict);
        for (auto& w : queries) {
            res.push_back(search(w, dict));
        }
        return res;
    }
};
__________________________________________________________________________________________________
× Close
sample 19248 kb submission
class Solution {
private:
    const int gap = 'a' - 'A';
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||    
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    
    int match(string& a, string& b) {
        int na = a.length();
        int nb = b.length();
        int r = 1;
        if (na != nb) return 0;
        for(int i = 0; i < na; i++) {
            char c = a[i], d = b[i];
            if (c != d) { 
                 if (abs(c-d) == gap) {
                     if (r != 3) r = 2;    
                 }else {
                    if (isVowel(c) && isVowel(d)) r = 3; 
                    else return 0;                     
                 }   
            }
        }
        
        return r;
    }
    
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> r;
        for(auto s: queries) {
            int tt = 0; string ss;
            for(auto w: wordlist) {
                int t = match(s, w); 
                //cout << s << " " << w << ":" << t << endl;
                if (t == 1) { 
                    ss = w; break;
                }else if (t == 2) { 
                    if (tt == 3 || tt == 0) { tt = t; ss = w; } 
                }else if (t == 3) {
                    if (tt == 0) { tt = t; ss = w; }
                } 
            }
            
            r.emplace_back(ss);
        }
        
        return r;
    }
};
__________________________________________________________________________________________________
