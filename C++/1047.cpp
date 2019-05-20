__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    string removeDuplicates(string S) {
        string s2;
        
        for (auto& c: S) {
            if (!s2.empty() && c == s2.back()) {
                s2.pop_back();
            } else {
                s2.push_back(c);
            }
        }
        
        return s2;
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    string removeDuplicates(string S) {
        string s;
        for (char c : S) {
            s.push_back(c);
            if (s.size() >= 2 && s.back() == s[s.size() - 2])
                s.resize(s.size() - 2);
        }
        return s;
    }
};
__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    string removeDuplicates(string S) {
        int tail = 0;
        string ret = S;
        for (int i = 1; i < S.size(); i++) {
            if (tail >= 0 && S[i] == ret[tail]) {
                    tail--;
            }
            else {
                tail++;
                ret[tail] = S[i];
            }
        }
        return ret.substr(0, tail+1);
    }
};