__________________________________________________________________________________________________
7868 kb
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            res.push_back((char)((n - 1) % 26) + 'A');
            n = (n - 1) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
__________________________________________________________________________________________________
sample 7904 kb submission
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n) {
            result.push_back('A' + (n - 1) % 26), n = (n - 1) / 26;    
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
};
__________________________________________________________________________________________________
