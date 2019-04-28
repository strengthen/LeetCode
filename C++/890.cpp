__________________________________________________________________________________________________
sample 4 ms submission
#include <iostresam>
#include <vector>

class Solution {
public:
    string toPattern(string word) {
            map<char,char> M;
            int curr = 97; // a = 97 
            for ( char& w : word ) {
                if ( M.count(w) == 0 )  M[w] = (char) curr++;
            }
            for ( int i = 0 ; i < word.length() ; i++) { 
                word[i] = M[word[i]]; 
            }
            return word;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> result;
        string p = toPattern (pattern);
        for (string& word: words) if (toPattern(word).compare(p) == 0) {
            result.push_back(word);
        }
        return result;
    }            
};
__________________________________________________________________________________________________
sample 9028 kb submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    std::vector<std::string> findAndReplacePattern(
        std::vector<std::string>& words, std::string pattern) {
        const std::string pattern_sig = signatur(pattern);
        std::vector<std::string> res;
        res.reserve(words.size());
        for (const string& word : words) {
            if (pattern_sig == signatur(word)) {
                res.push_back(word);
            }
        }
        return res;
    }

private:
    std::string signatur(const std::string& s) {
        char i ='\1';
        std::array<char, 256> m = {0};
        std::string res;
        res.reserve(s.size());
        for (char ch : s) {
            if (m[ch] == '\0') {
                m[ch] = i++;
            }
            res.push_back(m[ch]);
        }
        return res;
    }
};
__________________________________________________________________________________________________
