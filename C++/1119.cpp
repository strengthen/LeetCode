__________________________________________________________________________________________________
class Solution {
public:
    string removeVowels(string S) {
        string ret;
        for (auto c : S)
            if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
                ret += c;
        return ret;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    string removeVowels(string S) {
        string ret = "";
        for (int i = 0;i < S.size();i++) {
            if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u') {
                
            } else {
                ret.push_back(S[i]);
            }
        }
        return ret;
    }
};
__________________________________________________________________________________________________
