__________________________________________________________________________________________________
class Solution {
public:
    void reverseWords(vector<char>& str) {
        int left = 0, n = str.size();
        for (int i = 0; i <= n; ++i) {
            if (i == n || str[i] == ' ') {
                reverse(str, left, i - 1);
                left = i + 1;
            }
        }
        reverse(str, 0, n - 1);
    }
    void reverse(vector<char>& str, int left, int right) {
        while (left < right) {
            char t = str[left];
            str[left] = str[right];
            str[right] = t;
            ++left; --right;
        }
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        for (int i = 0, j = 0; i < str.size(); i = j + 1) {
            for (j = i; j < str.size(); ++j) {
                if (str[j] == ' ') break;
            }
            reverse(str.begin() + i, str.begin() + j);
        }
    }
};
__________________________________________________________________________________________________
