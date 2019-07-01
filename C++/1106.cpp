__________________________________________________________________________________________________
sample 0 ms submission
static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    bool parseBoolExpr(string expr) {int i = 0;
        stack<char> val, op;
        while (expr[i]) {
            if (expr[i] == 't' || expr[i] == 'f' || expr[i] == '(') val.push(expr[i]);
            else if (expr[i] == '&' || expr[i] == '|' || expr[i] == '!') op.push(expr[i]);
            else if (expr[i] == ')') {
                char p = op.top(); op.pop();
                bool v = val.top() == 't'; val.pop();
                if (p == '!') v = !v;
                while (val.top() != '(') {
                    if (p == '&') v = v && (val.top() == 't');
                    else v = v || (val.top() == 't');
                    val.pop();
                }
                val.pop();
                val.push(v ? 't' : 'f');
            }
            i++;
        }
        return val.top() == 't';
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool f_not(const string& s,int& i){
        i += 2;
        auto res = f(s,i);
        i++;
        return !res;
    }
    
    bool f_and(const string& s,int& i){
        i += 2;
        bool res = true;
        res &= f(s,i);
        while(s[i]!=')'){
            i++;
            res &= f(s,i);
        }
        i++;
        return res;
    }
    
    bool f_or(const string& s,int& i){
        i += 2;
        bool res = false;
        res |= f(s,i);
        while(s[i]!=')'){
            i++;
            res |= f(s,i);
        }
        i++;
        return res;
    }
    
    bool f(const string& s, int& i){
        if(s[i] == 't'){
            i++;
            return true;
        } else if(s[i] == 'f'){
            i++;
            return false;
        } else if(s[i] == '!'){
            return f_not(s,i);
        } else if(s[i] == '&'){
            return f_and(s,i);
        } return f_or(s,i);
    }
    bool parseBoolExpr(string expression) {
        int i = 0;
        return f(expression,i);
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    bool parseBoolExpr(string expression) {
        function<bool (string&, size_t, size_t)> parse =
            [&parse](string& expression, size_t beg, size_t end) -> bool
            {
                //cout<<"parse  "<<expression.substr(beg, end - beg)<<endl;
                if(expression[beg] == 't')
                    return true;
                else if(expression[beg] == 'f')
                    return false;
                else if(expression[beg] == '!')
                    return !parse(expression, beg + 2, end - 1);
                else
                {
                    int level = 0;
                    size_t idx;
                    bool res = true;
                    for(size_t i = beg + 1; i < end; i++)
                        if(expression[i] == '(')
                        {
                            if(!level) idx = i;
                            level++;
                        }
                        else if(expression[i] == ')')
                        {
                            level--;
                            if(!level) return parse(expression, idx + 1, i);
                        }
                        else if(expression[i] == ',' && level == 1)
                        {
                            res = parse(expression, idx + 1, i);
                            if(expression[beg] == '|' and res) return res;
                            if(expression[beg] == '&' and !res) return res;
                            idx = i;
                        }
                    return res;
                }
            };
        return parse(expression, 0, expression.length());
    }
};