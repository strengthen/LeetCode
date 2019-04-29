__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> p;
        for(int i = 0 ; i < S.size() ; ++i){
            if(!p.empty() && p.top()=='(' && S[i] == ')')
                p.pop();
            else
                p.push(S[i]);
        }
        return p.size();
    }
};
__________________________________________________________________________________________________
sample 8512 kb submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    int minAddToMakeValid(const std::string& S) {
        int res = 0;
        int open = 0;
        for (char ch : S) {
            if (ch == '(') {
                ++open;
            } else if (open == 0){
                ++res;
            } else {
                --open;
            }
        }
        res += open;
        return res;
    }
};
__________________________________________________________________________________________________
