__________________________________________________________________________________________________
sample 4 ms submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string reverseStr(string s, int k) {
        if (k == 0) return s;
        int i = 0;
        while (i < (int) s.size() - k + 1) {
            for (int j = 0; j < k / 2; j++) {
                swap(s[i + j], s[i + k - j - 1]);
            }
            i += (2 * k);
        }
        // i -= (2 * k);
        int len = (int) s.size() - i;
        if (len < k) {
            for (int j = 0; j < len / 2; j++) {
                swap(s[i + j], s[s.size() - j - 1]);
            }
        }
        return s;
    }
};
__________________________________________________________________________________________________
sample 9396 kb submission
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k)
            reverse(s, i, min(k, (int) s.size() - i));
        
        return s;
    }
    
    void reverse(string &s, int begin, int length) {
        for (int i = 0; i < length / 2; ++i)
            swap(s[begin + i], s[begin + length - i - 1]);
    }
};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
