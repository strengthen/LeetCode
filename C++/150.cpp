__________________________________________________________________________________________________
12ms
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i = 0; i < tokens.size(); ++i)
        {
            if(isdigit(tokens[i][0]) || (tokens[i][0] == '-' && isdigit(tokens[i][1])))
            {
                stk.push(atoi(tokens[i].c_str()));
            }
            else if(tokens[i][0] == '+')
            {
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();
                stk.push(val2+val1);
            }
            else if(tokens[i][0] == '-')
            {
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();
                stk.push(val2-val1);
            }
            else if(tokens[i][0] == '*')
            {
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();
                stk.push(val2*val1);                
            }
            else if(tokens[i][0] == '/')
            {
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();
                stk.push(val2/val1);                      
            }
        }
        return stk.top();
    }
};
__________________________________________________________________________________________________
11244 kb
class Solution {
public:
    int evalRPN(vector<string>& token) {
        int i=0,a,b;
        int end = token.size() - 1;
        stack<int> stk;
        while(i<=end)
        {
            //cout<<token[i]<<endl;
            if((token[i] != "+") && (token[i] != "-") && (token[i] != "/") && (token[i] != "*"))
                stk.push(stoi(token[i]));
            else
            {
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                
                if(token[i] == "+")
                    stk.push(a+b); 
                else if(token[i] == "/")
                    stk.push(b/a);
                else if(token[i] == "-")
                    stk.push(b-a);
                else
                    stk.push(a*b);
            }
            i++;
        }
        return stk.top();
    }
};
__________________________________________________________________________________________________
