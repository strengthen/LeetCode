__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        
        int res = 0;
        
        for (auto ch: s) {
            if (ch == 'R') {
                count++;
            }
            else {
                count--;
            }
            
            if (count == 0) {
                res++;
            }
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
0ms
class Solution {
public:
    int balancedStringSplit(string s) {
    int res = 0, cnt = 0;
    for (const auto& c : s) {
        cnt += c == 'L' ? 1 : -1;
        if (cnt == 0) ++res;
    }
    return res;
}
};
__________________________________________________________________________________________________
