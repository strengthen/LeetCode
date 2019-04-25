__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
public:
    int number(const string &s, int &i){
        int ans = 0;
        while(s[i] >= '0' && s[i] <= '9'){
            ans *= 10;
            ans += s[i] - '0';
            i++;
        }
        return ans;
    }
    
    NestedInteger deserialize(string s) {
        if(s[0] != '['){
            int i = 0;
            if(s[0] == '-'){
                i++;
                return NestedInteger(-1 * number(s, i));
            }
            return NestedInteger(number(s, i));
        }   
        stack<NestedInteger> stack;
        NestedInteger ans;
        stack.push(ans);
        size = s.size();
        int i = 0;
        do{
            if(s[i] == '['){
                NestedInteger temp;
                stack.push(temp);
            }
            else if(s[i] == ']'){
                NestedInteger temp = stack.top();
                stack.pop();
                stack.top().add(temp);
            }
            else if(s[i] == '-'){
                i++;
                int num = -1 * number(s, i);
                i--;
                stack.top().add(NestedInteger(num));
            }
            else if(s[i] == ','){
            }
            else{ //number
                int num = number(s, i);
                i--;
                stack.top().add(NestedInteger(num));
            }
            i++;
        }
        while(stack.size() > 1);
        
        return stack.top().getList()[0];
    }
    int size;
};
__________________________________________________________________________________________________
× Close
sample 13712 kb submission
#include <cctype>
#include <stack>
using std::isdigit;
using std::stack;

class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger *> st;
        int ls = s.size();
        int i = 0;
        NestedInteger *item;
        NestedInteger *res;
        while (i < ls) {
            if (s[i] == '[') {
                item =  new NestedInteger();
                if (!st.empty()) {
                    st.top()->getList().push_back(*item);
                    st.push(&(st.top()->getList().back()));
                } else {
                    res = item;
                    st.push(item);
                }
                
            } else if (s[i] == ']') {
                if (st.size() == 1) {
                    res = st.top();
                }
                st.pop();
            } else if (s[i] == '-' || s[i] == '+' || isdigit(s[i])) {
                int sign = 1;
                if (s[i] == '-') {
                    sign = -1;
                    ++i;
                } else if (s[i] == '+') {
                    ++i;
                }
                int val = 0;
                while (i < ls && isdigit(s[i])) {
                    val = val * 10 + (s[i] - '0');
                    ++i;
                }
                item = new NestedInteger(sign * val);
                if (!st.empty()) {
                    st.top()->getList().push_back(*item);
                } else {
                    res = item;
                }
                --i;
            }
            ++i;
        }
        return *res;
    }
};
__________________________________________________________________________________________________
