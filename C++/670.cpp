__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
    int len = (int)s.size();
    string t = s;
    for(int i = 0; i < len; i++)
        for(int j = i + 1; j < len; j++)
        {
            swap(s[i], s[j]);
            if(s > t) t = s;
            swap(s[i], s[j]);
        }
    return stoi(t);
    }
};
__________________________________________________________________________________________________
sample 8664 kb submission
class Solution {
public:
    int maximumSwap(int num) {
        string digits = to_string(num);
        int left = 0, right = 0;
        int max_idx = digits.length() - 1;
        for (int i = digits.length() - 1; i >= 0; --i) {
            if (digits[i] > digits[max_idx]) {
                max_idx = i;
            } else if (digits[max_idx] > digits[i]) {
                left = i;
                right = max_idx;
            }
        }
        swap(digits[left], digits[right]);
        return stoi(digits);
    }
};
__________________________________________________________________________________________________
