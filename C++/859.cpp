__________________________________________________________________________________________________
sample 4 ms submission
auto speedup =[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool buddyStrings(const string& A, const string& B) 
    {
        if (A.size() != B.size()) {
            return false;
        } else if (A == B) {
            return unordered_set<char>(A.begin(), A.end()).size() < A.size();
        } else {   
            vector<int> pos;
            for (int i = 0; i < A.size(); ++i) {
                if (A[i] != B[i])
                    pos.push_back(i);
            }
            return pos.size() == 2 && A[pos[0]] == B[pos[1]] && A[pos[1]] == B[pos[0]];
        }
    }
};
__________________________________________________________________________________________________
sample 8948 kb submission
class Solution {
public:
    bool buddyStrings(string A, string B) {        
        if (A.length() != B.length()) return false;
        vector<int> ca(26), cb(26);
        int diff = 0;
        for (int i = 0; i < A.length(); ++i) {
            if (A[i] != B[i] && diff++ > 2) return false;
            ++ca[A[i]-'a'];
            ++cb[B[i]-'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (diff == 0 && ca[i] > 1) return true;            
            if (ca[i] != cb[i]) return false;
        }
        return diff == 2; 
        //return true;
    }
};
__________________________________________________________________________________________________
