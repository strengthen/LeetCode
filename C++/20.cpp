__________________________________________________________________________________________________
4ms
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for (char c : s) {
            if (c == '(') stk.push(')');
            else if (c == '{') stk.push('}');
            else if (c == '[') stk.push(']');
            else if (stk.empty() || stk.top() != c) {
                return false;
            } else {
                stk.pop();
            }
        }
        
        return stk.empty();
    }
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') parentheses.push(s[i]);
            else {
                if (parentheses.empty()) return false;
                if (s[i] == ')' && parentheses.top() != '(') return false;
                if (s[i] == ']' && parentheses.top() != '[') return false;
                if (s[i] == '}' && parentheses.top() != '{') return false;
                parentheses.pop();
            }
        }
        return parentheses.empty();
    }
};
__________________________________________________________________________________________________
8424 kb
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    bool isMatch(char s1, char s2) {
        if(s1 == '(' && s2 == ')')
            return true;
        else if(s1 == '[' && s2 == ']')
            return true;
        else if(s1 == '{' && s2 == '}')
            return true;
        return false;
    }
    bool isStart(char s1) {
        switch(s1) {
            case '(': case '{': case '[':
                return true;
            default:
                return false;
        }
    }
public:
    bool isValid(string s) {
        stack<char> stack1;
        // ( ) [] {}
        for(int i=0; i<s.size(); ++i) {
            if(isStart(s[i])) stack1.push(s[i]);
            else {
                if(stack1.empty()) return false;
                char alphabet = stack1.top();
                if(!isMatch(alphabet, s[i])) return false;
                stack1.pop();
            }
        }
        return stack1.empty();
    }
};
__________________________________________________________________________________________________
8480 kb
#include <stack>

static int fast = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        
        for(int i=0; i<s.length(); i++)
        {
            if((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
            {
                brackets.push(s[i]);
            }
            else if(s[i] == ')')
            {
                if(brackets.empty() || (brackets.top() != '('))
                    return false;
                
                brackets.pop();
            }
            else if(s[i] == '}')
            {
                if(brackets.empty() || (brackets.top() != '{'))
                    return false;
                
                brackets.pop();
            }
            else if(s[i] == ']')
            {
                if(brackets.empty() || (brackets.top() != '['))
                    return false;
                
                brackets.pop();
            }
        }
        
        if(brackets.empty())
            return true;
        
        return false;
    }
};
__________________________________________________________________________________________________
8600 kb
class Solution {
public:
    string tmp_s;
    bool isValid(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                tmp_s.push_back(s[i]);
                continue;
            }
            if (tmp_s.size() == 0) {
                return false;
            }
            if (s[i] == ')') {
                if (tmp_s.back() == '(') {
                    tmp_s.pop_back();
                    continue;
                }
                return false;
            }
            if (s[i] == '}') {
                if (tmp_s.back() == '{') {
                    tmp_s.pop_back();
                    continue;
                }
                return false;
            }
            if (s[i] == ']') {
                if (tmp_s.back() == '[') {
                    tmp_s.pop_back();
                    continue;
                }
                return false;
            }
        }
        if (tmp_s.size() != 0) {
            return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
