__________________________________________________________________________________________________
sample 8 ms submission
#define DEBUG 0
class LispExpr {
private:
    unordered_map<string, int> data; // store the data for current expression; a better name is "context"
public:
    LispExpr () {}
    LispExpr (unordered_map<string, int>& data) : data(data) {}
    int parse(string& expr, int& ind) {  // parse a value from expr, key, or number.
        if (expr[ind] == '(') return parseExpr(expr, ind);
        if (isdigit(expr[ind]) || expr[ind] == '-') return parseInt(expr, ind);
        if (isalpha(expr[ind])) return data[parseKey(expr, ind)];
        return -1;
    }
    int parseExpr(string& expr, int& ind) {  // deal with the expression parssing.
        if (expr.substr(ind + 1, 3) == "let") return processLet(expr, ind);
        if (expr.substr(ind + 1, 3) == "add") return processAdd(expr, ind);
        return processMult(expr, ind);
    }
    int processAdd(string& expr, int& ind) {
        ind += 5;
        int v1 = parse(expr, ind); // recursion with loops, parse -> parseExpr->processXXX -> parse -> ...
        ind++;
        int v2 = parse(expr, ind);
        ind++;
        return v1 + v2;
    }
    int processMult(string& expr, int& ind) {
        ind += 6;
        int v1 = parse(expr, ind); // recursion with loops, parse -> parseExpr->processXXX -> parse -> ...
        ind++;
        int v2 = parse(expr, ind);
        ind++;
        return v1 * v2;      
    }
    int processLet(string& expr, int& ind) { // for Let, it means a new level of string to be processed.
        ind += 5;
        LispExpr cur(data); // copy the data to the new level
        while (true) {      // Most difficult is about how to determine the current one is the final expression.
            string key = parseKey(expr, ind);  // try to get key
            if (expr[ind] == ')') {  // final loc reached case 1.
                ind++; // finish current level.
                if (key[0] == '-' || isdigit(key[0])) return stoi(key);
                return cur.getData(key); // it is the end
            } else if (key.empty()) { // final loc reached case 2.
                int res = cur.parse(expr, ind);
                ind++;
                return res;
            } else { // It is a key found, then, need to get data.
                ind++;
                int v = cur.parse(expr, ind);
                ind++; // move to the next key.
                cur.setData(key, v);
            }
        }
    }
    int getData(string key) {
        return data[key];
    }
    void setData(string key, int v) {
        data[key] = v;
    }
private:
    int parseInt(string& expr, int& ind) {  // this way, it is like treating the string as a stream
        int v = 0;  // I didn't expect negative values in the beginning.
        int sign = 1;
        if (expr[ind] == '-') {
            ind++;
            sign = -1;
        }
        while (isdigit(expr[ind])) v = v * 10 + (expr[ind++] - '0');
        return v * sign;
    }
    string parseKey(string& expr, int& ind) {  // I was assuming the key is pure alphabet, but it may contain number.
        string key;  // Now, parsing the key is the most carful stuff.
        while (expr[ind] != ' ' && expr[ind] != ')' && expr[ind] != '(') key += expr[ind++];
        return key;
    }
};
class Solution {
public:
    /*
    (let v1 e1 v2 e2 ... vn en expr) => value of expr
    (add e1 e2)
    (mult e1 e2)
   
    */
    int evaluate(string expression) {
        LispExpr parser;
        int index = 0;
        return parser.parseExpr(expression, index);
    }
};
__________________________________________________________________________________________________
sample 11740 kb submission
string get_str(string& exp, int i) {
    string s;
    while (i < exp.size() && exp[i] != ' ' && exp[i] != ')') {
        s += exp[i++];
    }
    return s;
}
class Solution {
    // eval exp from i, no left (, close with right )
    int eval(string& exp, int &i, unordered_map<string, int>& values) {
        if (exp[i] != '(') {
            int rtn = 0;
            string s = get_str(exp, i);
            i += s.size();
            if (isdigit(s[0]) || s[0] == '-')  rtn = stoi(s);
            else rtn = values[s];
            return rtn;
        }
        ++i;
        // first must be op, otherwise invalid
        string op = get_str(exp, i);
        i += op.size();
        ++i; // skip space
        
        // copy last variables
        
        if (op == "let") {
            unordered_map<string, int> new_val(values);
            while (true) {
                if (exp[i] == '(') {
                    int rtn = eval(exp, i, new_val);
                    ++i; // ')'
                    return rtn;
                } else {
                    string var = get_str(exp, i);
                    i += var.size();
                    if (isdigit(var[0]) || var[0] == '-') {
                        int rtn = stoi(var);
                        ++i; // ')'
                        return rtn;
                    } else if (exp[i] == ')') { // the return var
                        int rtn = new_val[var];
                        ++i; // ')'
                        return rtn;
                    } else { // not return value, parse the next expression
                        ++i; // ' '
                        int value = eval(exp, i, new_val);
                        new_val[var] = value;
                        ++i; // ')'
                    }
                }   
            }
        } else if (op == "add" || op == "mult") {
            int opnd1 = eval(exp, i, values);
            ++i; // ' '
            int opnd2 = eval(exp, i, values);
            ++i; // ')'
            if (op == "add") return opnd1 + opnd2;
            else return opnd1 * opnd2;
        }
        return 0;
    }
public:
    int evaluate(string expression) {
        unordered_map<string, int> values;
        int i = 0;
        return eval(expression, i, values);
    }
};
__________________________________________________________________________________________________
