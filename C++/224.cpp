__________________________________________________________________________________________________
sample 4 ms submission

static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int i;
    int calculate(string s) {
        i = 0;
        return cal(s);
    }
    int cal(string& s) {
       int ans=0;
       bool sign = true;
       for(; i<s.size(); i++) {
           char a = s[i];
           if (a == '(') {
               i++;
               if (sign) {
                   ans += cal(s);
               } else {
                   ans -= cal(s);
               }
               sign = true;
               continue;
           } else if (a == ')') {
               return ans;
           } else if (a == ' ' || a == '+') continue;
           else if (a == '-') {
               sign = !sign;
               continue;
           }
           int next = 0;
           while (i<s.size() && s[i] >= '0' && s[i] <= '9') {
               next *= 10;
               next += s[i] - '0';
               i++;
           }
           i--;
           if (sign) ans += next;
           else ans -= next;
           sign = true;
       }
       return ans; 
    }
};

__________________________________________________________________________________________________
sample 10320 kb submission
class Solution {
public:
    int calculate(string & s) {
        stack<int> st;
        int sign = 1; // determine the next integer is positive or negative
        int result = 0; // current counted value with out reaching (, 一切都要reset遇到(
        long long curVal = 0; // 存上一个数字(不带符号)
        string res{};
        unordered_map<char, int> unseen;
        stack<int> letterSign;
        
        for (auto & c : s) {
            if (isdigit(c)) {
                curVal = curVal * 10 + c - '0'; //仅仅针对纯数字，比如说"123456", 输出的结果也需要是123456
                //注意不能直接写Integer.valueOf(c);
                continue;
            }
            else if(isalpha(c)){
                stack<int> tempSign(letterSign);
                while(!letterSign.empty()){
                    sign *= letterSign.top();
                    letterSign.pop();
                }
                letterSign = tempSign;
                unseen[c] += sign;
                continue;
            }
            
            if (c == '+') {
                result += curVal * sign;
                sign = 1;
                curVal = 0;
                continue;
            }
            
            if (c == '-') {
                result += curVal * sign;
                sign = -1;
                curVal = 0;
                continue;
            }
            
            if (c == '(') { //result清零
                st.push(result);
                st.push(sign);
                letterSign.push(sign);
                sign = 1;
                curVal = 0;
                result = 0;
                continue;
            }
            
            if (c == ')') {
                result += curVal * sign;
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
                letterSign.pop();
                curVal = 0;
                continue;
            }
        }
        
        if (curVal != 0) { //最后一个数如果是数字的话，并没有加到result里面去
            result += curVal * sign;
        }
        
        cout << unseen['c'] << endl;
        return result;
    }
};
__________________________________________________________________________________________________
