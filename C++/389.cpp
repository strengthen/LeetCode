__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (char c : s) res ^= c;
        for (char c : t) res ^= c;
        return res;
    }
};
__________________________________________________________________________________________________
sample 8888 kb submission
auto fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    char findTheDifference(string s, string t) {
        char flag[26] = {0};
        for (auto i:s) ++flag[i - 'a'];
        for (auto i:t) {
            --flag[i - 'a'];
            if (flag[i - 'a'] < 0) return i;
        }
        
        return -1;
    }
};
__________________________________________________________________________________________________
