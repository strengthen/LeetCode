__________________________________________________________________________________________________
class Solution {
public:
    string parseTernary(string expression) {
        string res = expression;
        stack<int> s;
        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] == '?') s.push(i);
        }
        while (!s.empty()) {
            int t = s.top(); s.pop();
            res = res.substr(0, t - 1) + eval(res.substr(t - 1, 5)) + res.substr(t + 4);
        }
        return res;
    }
    string eval(string str) {
        if (str.size() != 5) return "";
        return str[0] == 'T' ? str.substr(2, 1) : str.substr(4);
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    string parseTernary(string expression) {
        stack<char> s;
        for (int i = expression.size() - 1; i >= 0; --i) {
            char c = expression[i];
            if (!s.empty() && s.top() == '?') {
                s.pop();
                char first = s.top(); s.pop();
                s.pop();
                char second = s.top(); s.pop();
                s.push(c == 'T' ? first : second);
            } else {
                s.push(c);
            }
        }
        return string(1, s.top());
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    string parseTernary(string expression) {
        string res = expression;
        while (res.size() > 1) {
            int i = res.find_last_of("?");
            res = res.substr(0, i - 1) + string(1, res[i - 1] == 'T' ? res[i + 1] : res[i + 3]) + res.substr(i + 4);
        }
        return res;
    }
};