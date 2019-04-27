__________________________________________________________________________________________________
class Solution {
public:
    string similarRGB(string color) {
        return "#" + helper(color.substr(1, 2)) + helper(color.substr(3, 2)) + helper(color.substr(5, 2));
    }
    string helper(string str) {
        string dict = "0123456789abcdef";
        int num = stoi(str, nullptr, 16);
        int idx = num / 17 + (num % 17 > 8 ? 1 : 0);
        return string(2, dict[idx]);
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    string similarRGB(string color) {
        for (int i = 1; i < color.size(); i += 2) {
            int num = stoi(color.substr(i, 2), nullptr, 16);
            int idx = num / 17 + (num % 17 > 8 ? 1 : 0);
            color[i] = color[i + 1] = (idx > 9) ? (idx - 10 + 'a') : (idx + '0');
        }
        return color;
    }
};
__________________________________________________________________________________________________
