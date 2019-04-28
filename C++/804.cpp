__________________________________________________________________________________________________
sample 4 ms submission
#include <unordered_set>
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> morses{};
        for (const auto& i : words) {
            string morse{};
            for (auto j : i) {
                morse += MORSES[j - 'a'];
            }
            morses.emplace(move(morse));
        }
        return morses.size();
    }
    
private:
    const static vector<string> MORSES;
};

const vector<string> Solution::MORSES{
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
    };

__________________________________________________________________________________________________
sample 9116 kb submission
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<long long, int> tbl;
        char * scode[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int code[26];
        int len[26];
        for (int i=0, j; i<26; i++)
        {
            code[i] = 0;
            for (j=0; scode[i][j]; j++)
            {
                code[i] = (code[i] << 1) + (scode[i][j] == '.' ? 1 : 0);
            }
            len[i] = j;
        }
        for (int i=0; i<words.size(); i++)
        {
            long long res = 0;
            string s = words[i];
            for (int j=0; j<s.size(); j++)
            {
                res = (res << len[s[j]-'a']) + code[s[j]-'a'];
            }
            tbl[res] = 1;
        }
        return tbl.size();
    }
};
__________________________________________________________________________________________________
