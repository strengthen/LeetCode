__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string customSortString(string S, string T) {
        multiset<char> a;
        string res;
        for (int i = 0; i < T.size(); i++) {
            a.insert(T[i]);            
        }
        for (int i = 0; i < S.size(); i++) {
            int c = a.count(S[i]);
            a.erase(S[i]);
            for (int j = 0; j < c; j++) {
                res.push_back(S[i]);
            }
        }
        for (multiset<char>::iterator i = a.begin(); i != a.end(); ++i) {
            res.push_back(*i);            
        }
        return res;
        
    }
};
__________________________________________________________________________________________________
sample 8340 kb submission
class Solution {
public:
    string customSortString(string S, string T) {
        
        size_t next_pos = 0;
        
        for (const char c : S) {
            for (size_t i = next_pos; i < T.size(); ++i) {
                if (T[i] == c) {
                    std::swap(T[i], T[next_pos]);
                    ++next_pos;
                }
            }
        }
        
        return T;
    }
};
__________________________________________________________________________________________________
