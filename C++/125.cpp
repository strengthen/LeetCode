__________________________________________________________________________________________________
4ms
int optimization = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int l = 0, r = s.size() - 1;
        
        while (l < r) {
            while (l < r && !isalnum(s[l])) ++l;
            while (l < r && !isalnum(s[r])) --r;
            if (l < r && tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            ++l;
            --r;
        }
        
        return true;
    }
};
__________________________________________________________________________________________________
8904 kb
class Solution {
public:
    bool isPalindrome(string& s) {
        if (s.empty()) return true;

        int l = 0, r = s.size() - 1;
        while (l < r) {
            // find left alphanumeric character
            if (!isalnum(s[l])) {
                ++l;
                continue;
            }
            // find right alphanumeric character
            if (!isalnum(s[r])) {
                --r;
                continue;
            }
            // case insensitive compare
            if (tolower(s[l]) == tolower(s[r])) {
                ++l;
                --r;
            } else {
                return false;
            }
        }

        return true;
    }
};
__________________________________________________________________________________________________
