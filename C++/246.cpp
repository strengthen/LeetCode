__________________________________________________________________________________________________
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int l = 0, r = num.size() - 1;
        while (l <= r) {
            if (num[l] == num[r]) {
                if (num[l] != '1' && num[l] != '0' && num[l] != '8'){
                    return false;
                }
            } else {
                if ((num[l] != '6' || num[r] != '9') && (num[l] != '9' || num[r] != '6')) {
                    return false;
                }
            }
            ++l; --r;
        }
        return true;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        for (int i = 0; i <= num.size() / 2; ++i) {
            if (m[num[i]] != num[num.size() - i - 1]) return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
