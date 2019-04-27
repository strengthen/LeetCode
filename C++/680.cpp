__________________________________________________________________________________________________
sample 24 ms submission
auto speedup =[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool validPalindrome(string s, int left, int right)
    {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left += 1;
            right -= 1;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        if (s.length() <= 2)
            return true;
        
        int left = 0;
        int right = s.length() - 1;
        int count = 1;
        
        while (left < right) {
            if (s[left] != s[right])
                return validPalindrome(s, left, right - 1) || validPalindrome(s, left + 1, right);
            left += 1;
            right -= 1;
        }
        
        return true;
    }
};
__________________________________________________________________________________________________
sample 21040 kb submission
class Solution {
public:

    bool validPalindrome(const string &s)
    {
        for (size_t i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                size_t i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;

                while (i1 < j1 && s[i1] == s[j1])
                    ++i1, --j1;

                while (i2 < j2 && s[i2] == s[j2])
                    ++i2, --j2;

                return i1 >= j1 || i2 >= j2;
            }
        }

        return true;
    }
};
__________________________________________________________________________________________________
