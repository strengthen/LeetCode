__________________________________________________________________________________________________
sample 12 ms submission

class Solution {
public:
    enum TokenType {
        TT_Num,
        TT_Var,
        TT_Op,
        TT_End
    };
    
    struct Token {
        int val = 0;
        TokenType type;                
    };
    
    class Tokenizer {
    public:
        Tokenizer(const string& exp, vector<string>& evalvars, vector<int>& evalints) {
            it = exp.begin();
            end = exp.end();
            for(int i = 0; i < evalvars.size(); ++i) {
                varMap[evalvars[i]] = evalints[i];
            }
        }
        
        Token getToken() {
            while(it != end && *it == ' ') {
                ++it;
            }
            if(it == end) {
                return Token{0, TT_End};
            }
            
            if(*it >= '0' && *it <= '9') {
                int num = 0;
                while(it != end && *it >= '0' && *it <= '9') {
                    num *= 10;
                    num += *(it++) - '0';
                }
                return Token{num, TT_Num};
            } else if(*it >= 'a' && *it <= 'z') {
                string var;
                while(it != end && *it >= 'a' && *it <= 'z') {
                    var += *(it++);
                }
                auto it = varMap.find(var);
                if(it == varMap.end()) {
                    if(varInd.count(var) == 0) {
                        vars.push_back(var);
                        varInd[var] = vars.size() - 1;
                    }
                    return Token{varInd[var], TT_Var};
                } else {
                    return Token{it->second, TT_Num};
                }
            } else {
                return Token{*(it++), TT_Op};
            }
        }
        
        const string& getVar(int ind) const {
            return vars[ind];
        }
        
    private:
        string::const_iterator it;
        string::const_iterator end;
        unordered_map<string, int> varMap;
        vector<string> vars;
        unordered_map<string, int> varInd;
    };
    
    class Expr {
    public:
        Expr(const Token& tk) {
            assert(tk.type != TT_Op);
            if(tk.type == TT_Num) {
                freeTerm = tk.val;
            } else {
                string term;
                term += tk.val;
                terms[term] = 1;
            }
        }
        
        void mul(const Expr& e) {
            unordered_map<string, int> res;
            for(const auto& t1 : terms) {
                for(const auto& t2 : e.terms) {
                    auto prod = mul(t1, t2);
                    res[prod.first] += prod.second;
                    if(res[prod.first] == 0) {
                        res.erase(prod.first);
                    }
                }
                if(e.freeTerm != 0) {
                    auto prod1 = mul(t1, {"", e.freeTerm});
                    res[prod1.first] += prod1.second;
                    if(res[prod1.first] == 0) {
                        res.erase(prod1.first);
                    }
                }
            }
            if(freeTerm != 0) {
                for(const auto& t2 : e.terms) {
                    auto prod2 = mul({"", freeTerm}, t2);
                    res[prod2.first] += prod2.second;
                    if(res[prod2.first] == 0) {
                        res.erase(prod2.first);
                    }
                }                
            }
                        
            freeTerm *= e.freeTerm;
            terms = move(res);
        }
        
        void add(const Expr& e) {
            freeTerm += e.freeTerm;
            for(auto t : e.terms) {
                terms[t.first] += t.second;
                if(terms[t.first] == 0) {
                    terms.erase(t.first);
                }
            }
        }
        
        void sub(const Expr& e) {
            freeTerm -= e.freeTerm;
            for(auto t : e.terms) {
                terms[t.first] -= t.second;
                if(terms[t.first] == 0) {
                    terms.erase(t.first);
                }
            }
        }
        
        vector<string> print(const Tokenizer& tk) {
            vector<pair<pair<int, string>, int>> result;
            for(const auto& t : terms) {
                if(t.second != 0) {
                    result.push_back(print(t.first, t.second, tk));
                }
            }
            
            sort(result.begin(), result.end());
            vector<string> finalResult;
            for(const auto& r : result) {
                string s = to_string(r.second);
                s += '*';
                s += r.first.second;
                finalResult.push_back(s);
            }
            
            if(freeTerm != 0) {
                finalResult.push_back(to_string(freeTerm));
            }
            
            return finalResult;
        }
        
        pair<pair<int, string>, int> print(const string& term, int c, const Tokenizer& tk) {
            vector<pair<string, int>> tt;
            int count = 0;
            int prev = -1;
            for(int i : term) {
                if(prev == -1) {
                    prev = i;
                    count = 0;
                } else if(i != prev) {
                    tt.push_back({tk.getVar(prev), count});
                    prev = i;
                    count = 0;
                }
                ++count;
            }
            if(prev != -1) {
                tt.push_back({tk.getVar(prev), count});
            }
            
            sort(tt.begin(), tt.end());
            
            string res;
            int degree = 0;
            for(const auto& t : tt) {
                for(int i = 0; i < t.second; ++i) {
                    if(!res.empty()) {
                        res += '*';
                    }
                    res += t.first;
                }
                degree += t.second;
            }
                        
            return make_pair(make_pair(-degree, res), c);
        }
        
    private:
        unordered_map<string, int> terms;
        int freeTerm = 0;
        
        pair<string, int> mul(const pair<string, int>& t1, const pair<string, int>& t2) {
            string t;
            auto i1 = t1.first.begin();
            auto i2 = t2.first.begin();
            auto e1 = t1.first.end();
            auto e2 = t2.first.end();
            while(i1 < e1 || i2 < e2) {
                if(i2 == e2 || i1 < e1 && *i1 < *i2) {
                    t += *(i1++);
                } else {
                    t += *(i2++);
                }
            }            
            return {t, t1.second * t2.second};
        }
    };
    
    void eval(stack<Expr>& expStack, int op) {
        Expr r = expStack.top();
        expStack.pop();
        switch(op) {
            case '+' : expStack.top().add(r); break;
            case '-' : expStack.top().sub(r); break;
            case '*' : expStack.top().mul(r); break;
        }
    }
    
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        Tokenizer tk(expression, evalvars, evalints);
        stack<Expr> expStack;
        stack<int> opStack;
        for(Token t = tk.getToken(); t.type != TT_End; t = tk.getToken()) {
            //cout << t.val << " " << t.type << endl;
            if(t.type == TT_Op) {
                int op = t.val;
                switch(op) {
                    case ')':
                        while(opStack.top() != '(') {
                            eval(expStack, opStack.top());
                            opStack.pop();
                        }
                        opStack.pop();
                        break;
                    case '(':
                        opStack.push(op);
                        break;
                    case '+':
                    case '-':
                        while(!opStack.empty() && (opStack.top() == '*' || opStack.top() == '-')) {
                            eval(expStack, opStack.top());
                            opStack.pop();
                        }
                        opStack.push(op);
                        break;
                    case '*':
                        opStack.push(op);
                        break;
                }        
            } else {
                expStack.push(Expr(t));
            }
        }
        
        while(!opStack.empty()) {
            eval(expStack, opStack.top());
            opStack.pop();
        }
        
        vector<string> result = expStack.top().print(tk);
        return result;
    }
};
__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, int> eval;                // construct the map from evalvars to evalints
        for (int i = 0; i < evalvars.size(); ++i) {
            eval[evalvars[i]] = evalints[i];
        }
        auto resmp = helper(expression, eval);          // solve the problem
        vector<string> res;                             // construct the results
        vector<string> keys;
        for (auto param : resmp) {
            if (param.second == 0) {
                continue;
            }
            keys.push_back(param.first);
        }
        sort(keys.begin(), keys.end(), cmp);
        for (string key : keys) {
            if (key == "") {
                res.push_back(to_string(resmp[key]));
            } else {
                res.push_back(to_string(resmp[key]) + "*" + key);
            }            
        }
        return res;
    }
    
private:
    
    static void splitByStars(string s, vector<string>& vars) {        
        int i = 0;
        size_t pos = s.find("*", i);
        while (pos != string::npos) {
            vars.push_back(s.substr(i, pos - i)); 
            i = pos + 1;
            pos = s.find("*", i);
        }        
        vars.push_back(s.substr(i, s.length() - i));
    }
    
    static bool cmp(const string& a, const string& b) {
        if (a.empty()) {
            return false;
        }
        if (b.empty()) {
            return true;
        }
        vector<string> va, vb;
        Solution::splitByStars(a, va);
        Solution::splitByStars(b, vb);
        if (va.size() == vb.size()) {
            for (int i = 0; i < va.size(); ++i) {
                if (va[i] != vb[i]) {
                    return va[i] < vb[i];
                }
            }
            return true;
        }
        return va.size() > vb.size();
    }

    unordered_map<string, int> helper(string& expr, unordered_map<string, int>& eval) {
        unordered_map<string, int> global, mult;
        string sub = "";
        int sign = 1, n = expr.size();
        for (int i = 0; i <= n; ++i) {
            if (i < n && expr[i] == ' ') {          // skip space
                continue;  
            }
            if (i < n && isalnum(expr[i])) {        // number and alphabet, add to sub expression
                sub += expr[i];
            } else if (i < n && expr[i] == '(') {     // parenthesis
                ++i;
                for (int p = 1; ; ++i) {            // get the sub expression in parenthesis
                    if (expr[i] == '(') {
                        ++p;
                    }
                    else if (expr[i] == ')') {
                        --p;
                    }
                    if (p == 0) {
                        break;
                    }
                    sub += expr[i];
                }
            } else {                                  // '+', '-', '*' or i == n
                if (sub.size() == n) {              // the whole expression is a number or variable
                    if (eval.count(sub)) {
                        return {{"", eval[sub]}};   // variable is found in eval list 
                    }
                    if (isdigit(sub[0])) {
                        return {{"", stoi(sub)}};   // number
                    }
                    return {{sub, 1}};            // variable
                }
                auto local = helper(sub, eval);
                
                if (sign != 0) {     // '+' or '-'
                    for (auto& x : local) { // add local to global
                        global[x.first] += sign * x.second;
                        local[x.first] = sign * x.second;
                    }
                } else {
                    updateMult(global, local, mult);
                }
                if (i < n) {
                    if (expr[i] == '*') {
                        sign = 0;
                        if (mult.empty()) {
                            mult = local;
                        }
                    } else if (expr[i] == '-') {
                        sign = -1;
                        mult.clear();
                    } else {
                        sign = 1;
                        mult.clear();
                    }
                }
                sub = "";                           // reset sub
            }
        }
        return global;
    }

    void updateMult(unordered_map<string, int>& global, unordered_map<string, int>& local, 
                    unordered_map<string, int>& mult) {        
        unordered_map<string, int> mult1;
        for (auto& x : mult) {
            global[x.first] -= x.second;
            for (auto& y : local) {
                string varName;
                if (x.first.empty() && y.first.empty()) {
                    varName = "";
                } else if (x.first.empty()) {
                    varName = y.first; 
                } else if (y.first.empty()) {
                    varName = x.first; 
                } else {
                    vector<string> vars;
                    splitByStars(x.first, vars);
                    splitByStars(y.first, vars);
                    sort(vars.begin(), vars.end());
                    varName = vars[0];
                    for (int i = 1; i < vars.size(); ++i) {
                        varName += ("*" + vars[i]);
                    }           
                }
                global[varName] += x.second * y.second;
                mult1[varName] += x.second * y.second;
            }
        }
        mult = mult1;        
    }
       
};
__________________________________________________________________________________________________
sample 20 ms submission
class Solution {

public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, int> eval;
        for (int i = 0; i < evalvars.size(); ++i) {
            eval[evalvars[i]] = evalints[i];
        }
        auto resmp = helper(expression, eval);
        vector<string> res;
        for (auto a : resmp) {
            if (a.second == 0) continue;
            res.push_back(to_string(a.second));
            for (auto p : a.first) {
                res.back() += "*" + p;
            }
        }
        return res;
    }
private:
    struct cmp {
        bool operator()(const vector<string> x, const vector<string> y) const {
            return x.size() > y.size() || (x.size() == y.size() && x < y);
        }
    };
    map<vector<string>, int, cmp> helper(string &expr, unordered_map<string, int> &eval) {
        map<vector<string>, int, cmp> local = {{{}, 1}}, global;
        string sub;
        int n = expr.size(), sign = 1;
        for (int i = 0; i <= n; ++i) {
            if (i < n && expr[i] == ' ') continue;
            if (i < n && isalnum(expr[i])) sub += expr[i];
            else if (i < n && expr[i] == '(') {
                int j = i, cnt = 0;
                for (; i < n; ++i) {
                    if (expr[i] == '(') ++cnt;
                    else if (expr[i] == ')') --cnt;
                    if (cnt == 0) break;
                }
                sub += expr.substr(j + 1, i - 1 - j);
            } else {
                if (sub.size() == n) {
                    if (eval.count(sub)) {
                        return {{{}, eval[sub]}};
                    } 
                    if (isdigit(sub[0])) {
                        return {{{}, stoi(sub)}};
                    }
                    return {{{sub}, 1}};
                } 
                
                map<vector<string>, int, cmp> mult, submp = helper(sub, eval);
                for (auto l : local) {
                    for (auto a : submp) {
                        vector<string> t = l.first;
                        t.insert(t.end(), a.first.begin(), a.first.end());
                        sort(t.begin(), t.end());
                        mult[t] += l.second * a.second;
                    }
                }
                
                local = move(mult);
                if (i == n || expr[i] == '+' || expr[i] == '-') {
                    for (auto a : local) {
                        global[a.first] += sign * a.second;
                    }
                    sign = i < n && expr[i] == '-' ? -1 : 1; // sign = 1 for '+' or number              
                    local = {{{}, 1}};
                } 
                sub.clear();
            }
        }
        return global;
    }
};
__________________________________________________________________________________________________
sample 20 ms submission
class Solution {

public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, int> eval;
        for (int i = 0; i < evalvars.size(); ++i) {
            eval[evalvars[i]] = evalints[i];
        }
        auto resmp = helper(expression, eval);
        vector<string> res;
        for (auto a : resmp) {
            if (a.second == 0) continue;
            res.push_back(to_string(a.second));
            for (auto p : a.first) {
                res.back() += "*" + p;
            }
        }
        return res;
    }
private:
    struct cmp {
        bool operator()(const vector<string> x, const vector<string> y) const {
            return x.size() > y.size() || (x.size() == y.size() && x < y);
        }
    };
    map<vector<string>, int, cmp> helper(string &expr, unordered_map<string, int> &eval) {
        map<vector<string>, int, cmp> local = {{{}, 1}}, global;
        string sub;
        int n = expr.size(), sign = 1;
        for (int i = 0; i <= n; ++i) {
            if (i < n && expr[i] == ' ') continue;
            if (i < n && isalnum(expr[i])) sub += expr[i];
            else if (i < n && expr[i] == '(') {
                int j = i, cnt = 0;
                for (; i < n; ++i) {
                    if (expr[i] == '(') ++cnt;
                    else if (expr[i] == ')') --cnt;
                    if (cnt == 0) break;
                }
                sub += expr.substr(j + 1, i - 1 - j);
            } else {
                if (sub.size() == n) {
                    if (eval.count(sub)) {
                        return {{{}, eval[sub]}};
                    } 
                    if (isdigit(sub[0])) {
                        return {{{}, stoi(sub)}};
                    }
                    return {{{sub}, 1}};
                } 
                
                map<vector<string>, int, cmp> mult, submp = helper(sub, eval);
                for (auto l : local) {
                    for (auto a : submp) {
                        vector<string> t = l.first;
                        t.insert(t.end(), a.first.begin(), a.first.end());
                        sort(t.begin(), t.end());
                        mult[t] += l.second * a.second;
                    }
                }
                
                local = move(mult);
                if (i == n || expr[i] == '+' || expr[i] == '-') {
                    for (auto a : local) {
                        global[a.first] += sign * a.second;
                    }
                    sign = i < n && expr[i] == '-' ? -1 : 1; // sign = 1 for '+' or number              
                    local = {{{}, 1}};
                } 
                sub.clear();
            }
        }
        return global;
    }
};
__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
public:
    
    vector<string> split(const string &s)
    {
        stringstream iss(s);
        vector<string> res;
        string tok;
        while(getline(iss, tok , '*'))
        {
            res.push_back(tok);
        }

        return res;
    };
    
    string combine(const string &s1, const string &s2)
    {
        if(s1 == "")
        {
            return s2;
        }
        
        if(s2 == "")
        {
            return s1;
        }
        vector<string> temp1 = split(s1);
        vector<string> temp2 = split(s2);
        temp1.insert(temp1.end(), temp2.begin(), temp2.end());
        std::sort(temp1.begin(), temp1.end());
        string res;
        for(auto t : temp1)
        {
            res+=t;
            res+="*";
        }
        res.pop_back();
        return res;
    }
    
    map<string,int> multiply(map<string,int> &m1, map<string,int> &m2)
    {
        map<string, int> m;
        for(auto p1: m1)
        {
            for(auto p2: m2)
            {
                //std::cout << p1.first << ":" << p2.first << std::endl;
                string temp = combine(p1.first, p2.first);
                m[temp] += p1.second*p2.second;
                //std::cout << temp << std::endl;
            }
        }
        return m;
    }
    
    
    map<string,int> reduce(vector<map<string, int>> &operands, vector<char> &operators)
    {
        map<string,int> m;
        int i = operators.size()-1;
        while(i >= 0)
        {
            map<string,int> op1 = operands[i];
            while(i > 0 && operators[i] == '*')
            {
                op1 = multiply(op1, operands[--i]);
            }
            
            int sign = (operators[i--] == '+' ? 1 : -1);
            for(auto respair : op1)
            {
                 //std::cout << respair.first << ":" << std::endl;
                 m[respair.first] += sign*respair.second;
            }
         
        }
        return m;
    }
    
    map<string,int> helper(map<string,int> &em, string &exp, int &pos)
    {
        vector<map<string,int>> operands;
        vector<char> operators;
        operators.push_back('+');
        while(pos < exp.size() && exp[pos] != ')')
        {
            if(exp[pos] == '(')
            {
                pos++;
                operands.push_back(helper(em, exp , pos));
            }
            else
            {
                map<string, int> op;
                int start  = pos;
                bool isnum = true;
                while(pos < exp.size() && exp[pos] != ')' && not std::isspace(exp[pos]))
                {
                    if(not std::isdigit(exp[pos]))
                    {
                        isnum = false;
                    }
                    pos++;
                }
                
                string curr = exp.substr(start, pos-start);
                //std::cout << curr << std::endl;
                if(isnum)
                {
                    op[""] = std::stoi(curr);
                }
                else if(em.count(curr))
                {
                    op[""] = em[curr];
                }
                else
                {
                    op[curr] = 1;
                }
                operands.push_back(op);
            }
            
            if(pos < exp.size() && std::isspace(exp[pos]))
            {
                pos++;
                operators.push_back(exp[pos]);
                pos+=2;
            }
        }
        
        pos++;
        return reduce(operands, operators);
        
    }
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        
        map<string,int> em;
        for(int i = 0 ; i < evalvars.size(); i++)
        {
            em[evalvars[i]] = evalints[i];
        }
        
        int start = 0;
        map<string,int> m = helper(em, expression, start);
        vector<pair<string,int>> temp;
        for(auto p : m)
        {
            temp.push_back(p);
        }
        
        auto f = [&](pair<string, int> &p1, pair<string, int> &p2)
        {
            vector<string> t1 = split(p1.first);
            vector<string> t2 = split(p2.first);
            return t1.size() > t2.size() || t1.size() == t2.size() && t1 < t2;
        };
        
        sort(temp.begin(), temp.end(), f);
        vector<string> res;
        for(auto p : temp)
        {
            if(p.second == 0)
            {
                continue;
            }
            
            string val = std::to_string(p.second) ;
            if(p.first != "")
            {
                val+="*";
                val+=p.first;
            }
            res.push_back(val);
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 28 ms submission
class Solution {
public:
    
    vector<string> split(const string &s)
    {
        stringstream iss(s);
        vector<string> res;
        string tok;
        while(getline(iss, tok , '*'))
        {
            res.push_back(tok);
        }

        return res;
    };
    
    string combine(const string &s1, const string &s2)
    {
        if(s1 == "")
        {
            return s2;
        }
        
        if(s2 == "")
        {
            return s1;
        }
        vector<string> temp1 = split(s1);
        vector<string> temp2 = split(s2);
        temp1.insert(temp1.end(), temp2.begin(), temp2.end());
        std::sort(temp1.begin(), temp1.end());
        string res;
        for(auto t : temp1)
        {
            res+=t;
            res+="*";
        }
        res.pop_back();
        return res;
    }
    
    map<string,int> multiply(map<string,int> &m1, map<string,int> &m2)
    {
        map<string, int> m;
        for(auto p1: m1)
        {
            for(auto p2: m2)
            {
                //std::cout << p1.first << ":" << p2.first << std::endl;
                string temp = combine(p1.first, p2.first);
                m[temp] += p1.second*p2.second;
                //std::cout << temp << std::endl;
            }
        }
        return m;
    }
    
    
    map<string,int> reduce(vector<map<string, int>> &operands, vector<char> &operators)
    {
        map<string,int> m;
        int i = operators.size()-1;
        while(i >= 0)
        {
            map<string,int> op1 = operands[i];
            while(i >= 0 && operators[i] == '*')
            {
                op1 = multiply(op1, operands[--i]);
            }
            
            int sign = (operators[i--] == '+' ? 1 : -1);
            for(auto respair : op1)
            {
                 //std::cout << respair.first << ":" << std::endl;
                 m[respair.first] += sign*respair.second;
            }
         
        }
        return m;
    }
    
    map<string,int> helper(map<string,int> &em, string &exp, int &pos)
    {
        vector<map<string,int>> operands;
        vector<char> operators;
        operators.push_back('+');
        while(pos < exp.size() && exp[pos] != ')')
        {
            if(exp[pos] == '(')
            {
                pos++;
                operands.push_back(helper(em, exp , pos));
            }
            else
            {
                map<string, int> op;
                int start  = pos;
                bool isnum = true;
                while(pos < exp.size() && exp[pos] != ')' && not std::isspace(exp[pos]))
                {
                    if(not std::isdigit(exp[pos]))
                    {
                        isnum = false;
                    }
                    pos++;
                }
                
                string curr = exp.substr(start, pos-start);
                //std::cout << curr << std::endl;
                if(isnum)
                {
                    op[""] = std::stoi(curr);
                }
                else if(em.count(curr))
                {
                    op[""] = em[curr];
                }
                else
                {
                    op[curr] = 1;
                }
                operands.push_back(op);
            }
            
            if(pos < exp.size() && std::isspace(exp[pos]))
            {
                pos++;
                operators.push_back(exp[pos]);
                pos+=2;
            }
        }
        
        pos++;
        return reduce(operands, operators);
        
    }
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        
        map<string,int> em;
        for(int i = 0 ; i < evalvars.size(); i++)
        {
            em[evalvars[i]] = evalints[i];
        }
        
        int start = 0;
        map<string,int> m = helper(em, expression, start);
        vector<pair<string,int>> temp;
        for(auto p : m)
        {
            temp.push_back(p);
        }
        
        auto f = [&](pair<string, int> &p1, pair<string, int> &p2)
        {
            vector<string> t1 = split(p1.first);
            vector<string> t2 = split(p2.first);
            return t1.size() > t2.size() || t1.size() == t2.size() && t1 < t2;
        };
        
        sort(temp.begin(), temp.end(), f);
        vector<string> res;
        for(auto p : temp)
        {
            if(p.second == 0)
            {
                continue;
            }
            
            string val = std::to_string(p.second) ;
            if(p.first != "")
            {
                val+="*";
                val+=p.first;
            }
            res.push_back(val);
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 13940 kb submission
class Solution {
    struct cmp {
        bool operator()(const vector<string> &x, const vector<string> &y) const {   // sort terms by degree
            if (x.size() == y.size()) return x < y;
            else return x.size() > y.size();
        }
    };
    
    map<vector<string>, int, cmp> helper(string& expr,  unordered_map<string, int>& eval) {
        map<vector<string>, int, cmp> local = {{{}, 1}}, global;
        string sub = "";
        for (int i = 0, sign = 1, n = expr.size(); i <= n; ++i) {
            if (i < n && expr[i] == ' ') continue;  // skip space
            if (i < n && isalnum(expr[i])) sub += expr[i];  // number and alphabet, add to sub expression
            else if (i < n && expr[i] == '(') { // parenthesis
                i ++;
                for (int p = 1; ; ++i) {    // get the sub expression in parenthesis
                    if (expr[i] == '(') p ++;
                    else if (expr[i] == ')') p --;
                    if (p == 0) break;
                    sub += expr[i];
                }
            }
            else {  // '+', '-', '*' or i == n
                if (sub.size() == n) {  // the whole expression is a number or variable
                    if (eval.count(sub)) return {{{}, eval[sub]}};  // variable is found in eval list 
                    if (isdigit(sub[0])) return {{{}, stoi(sub)}};  // number
                    return {{{sub}, 1}};    // variable
                }
                map<vector<string>, int, cmp> mult, submp = helper(sub, eval);
                for (auto l : local) {  // multiply local with sub
                    for (auto r : submp) {
                        auto k = l.first;
                        k.insert(k.end(), r.first.begin(), r.first.end());
                        sort(k.begin(), k.end());
                        mult[k] += l.second * r.second;
                    }
                }
                local = move(mult);
                if (i == n || expr[i] != '*') {  // '+' or '-'
                    for (auto& t : local)   // add local to global
                        global[t.first] += sign * t.second;
                    sign = i < n && expr[i] == '-' ? -1 : 1;
                    local = {{{}, 1}};  // reset local
                }
                sub = "";   // reset sub
            }
        }
        return global;
    }
    
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, int> eval;
        for (int i = 0; i < evalvars.size(); ++i)
            eval[evalvars[i]] = evalints[i];
        vector<string> res;
        auto resmp = helper(expression, eval);
        for (auto param : resmp) {
            if (param.second == 0) continue;    // skip zero coefficient
            res.push_back(to_string(param.second));
            for (auto p : param.first) res.back() += "*" + p;
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 14564 kb submission
class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, int> mp;
        int n = evalvars.size();
        // create a map for variable value pairs
        for (int i = 0; i < n; ++i) mp[evalvars[i]] = evalints[i];
        // helper function is recursion using implicit stack
        int pos = 0;
        unordered_map<string, int> output = helper(expression, mp, pos);
        vector<pair<string, int>> ans(output.begin(), output.end());
        // sort result based on variable degree
        sort(ans.begin(), ans.end(), mycompare);
        vector<string> res;
        for (auto& p: ans) {
            // only consider non-zero coefficient variables
            if (p.second == 0) continue;
            res.push_back(to_string(p.second));
            if (p.first != "") res.back() += "*"+p.first;
        }
        return res;
    }
private:
    unordered_map<string, int> helper(string& s, unordered_map<string, int>& mp, int& pos) {
        // every operand is an unordered_map, including single variable or nested (a * b + a * c); 
        // if the operand is a number, use pair("", number)
        vector<unordered_map<string, int>> operands;
        vector<char> ops;
        ops.push_back('+');
        int n = s.size();
        while (pos < n && s[pos] != ')') {
            if (s[pos] == '(') {
               pos++;
               operands.push_back(helper(s, mp, pos));
            }
            else {
               int k = pos;
               while (pos < n && s[pos] != ' ' && s[pos] != ')') pos++;
               string t = s.substr(k, pos-k);
               bool isNum = true;
               for (char c: t) {
                   if (!isdigit(c)) isNum = false;
               }
               unordered_map<string, int> tmp;
               if (isNum) 
                   tmp[""] = stoi(t);
               else if (mp.count(t)) 
                   tmp[""] = mp[t];
               else              
                   tmp[t] = 1;
               operands.push_back(tmp);
            }
            if (pos < n && s[pos] == ' ') {
               ops.push_back(s[++pos]);
               pos += 2;
            }
        }
        pos++;
        return calculate(operands, ops);
    }
    unordered_map<string, int> calculate(vector<unordered_map<string, int>>& operands, vector<char>& ops) {
        unordered_map<string, int> ans;
        int n = ops.size();
        for (int i = n-1; i >= 0; --i) {
            unordered_map<string, int> tmp = operands[i];
            while (i >= 0 && ops[i] == '*')
                tmp = multi(tmp, operands[--i]);
            int sign = ops[i] == '+'? 1: -1;
            for (auto& p: tmp) ans[p.first] += sign*p.second;
        }
        return ans;
    }
    unordered_map<string, int> multi(unordered_map<string, int>& lhs, unordered_map<string, int>& rhs) {
        unordered_map<string, int> ans;
        int m = lhs.size(), n = rhs.size();
        for (auto& p: lhs) {
            for (auto& q: rhs) {
                // combine and sort the product of variables
                string t = combine(p.first, q.first);
                ans[t] += p.second*q.second;
            }
        }
        return ans;
    }
    string combine(const string& a, const string& b) {
        if (a == "") return b;
        if (b == "") return a;
        vector<string> strs = split(a, '*');
        for (auto& s: split(b, '*')) strs.push_back(s);
        sort(strs.begin(), strs.end());
        string s;
        for (auto& t: strs) s += t +'*';
        s.pop_back();
        return s;
    }
    static vector<string> split(const string& s, char c) {
        vector<string> ans;
        int i = 0, n = s.size();
        while (i < n) {
            int j = i;
            i = s.find(c, i);
            if (i == -1) i = n;
            ans.push_back(s.substr(j, i-j));
            i++;
        }
        return ans;
    }
    static bool mycompare(pair<string, int>& a, pair<string, int>& b) {
        string s1 = a.first, s2 = b.first;
        vector<string> left = split(s1, '*'); 
        vector<string> right = split(s2, '*');
        return left.size() > right.size() || (left.size() == right.size() && left < right);
    } 
};