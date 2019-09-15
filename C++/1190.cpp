__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
  string reverseParentheses(string s) {
    if (s.empty()) return "";
    int p = 0;
    while (p < s.size() && s[p] != '(') ++ p;
    if (p == 0) {
      int c = 0, q;
      for (q = 0; q < s.size(); ++ q) {
        if (s[q] == '(') {
          ++ c;
        } else if (s[q] == ')') {
          -- c;
        }
        if (c == 0) break;
      }
      string t = reverseParentheses(s.substr(1, q - p - 1));
      reverse(t.begin(), t.end());
      return t + reverseParentheses(s.substr(q + 1));
    }
    return s.substr(0, p) + reverseParentheses(s.substr(p));
  }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push("");
        for (auto c : s) {
            if (c == '(')
                st.push("");
            else if (c == ')') {
                auto p = st.top(); st.pop();
                reverse(p.begin(), p.end());
                st.top() += p;
            } else st.top().push_back(c);
        }
        return st.top();
    }
};
__________________________________________________________________________________________________
