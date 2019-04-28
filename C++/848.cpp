__________________________________________________________________________________________________
sample 16 ms submission
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0; 
}();

class Solution {
public:
    string shiftingLetters(string &S, vector<int>& shifts) {
        int len = shifts.size();
        shifts[len-1] %= 26;
        for(int i=1;i<len;i++){
            shifts[len-i-1] =shifts[len-i-1]%26 + shifts[len-i];
        }
        
        for(int i=0;i<len;i++){
            S[i] = 'a'+(shifts[i] + S[i]-'a')%26;
        }
        return S;
    }
};
__________________________________________________________________________________________________
sample 11492 kb submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    std::string shiftingLetters(std::string S,
                                std::vector<int>& shifts) {
        std::partial_sum(shifts.rbegin(), shifts.rend(), shifts.rbegin(),
                        [](int a, int b) {
                            return (a + b) % 26;
                        });
        for (int i = 0; i < S.size(); ++i) {
            S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
        }
        return S;
    }
};
__________________________________________________________________________________________________
