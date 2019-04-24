__________________________________________________________________________________________________
sample 4 ms submission
static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

class Solution {
public:
    int calculate(string s)
    {
        if (s.empty())
            return 0;
        
        int currentValue = 0;
        int currentNumber = 0;
        int lastNumber = 0;
        char operation = '+';
        int index = 0;
        int n = s.length();
        
        while (index < n)
        {
            while (index < n && s[index] == ' ') ++index;
            
            currentNumber = 0;
            
            while (index < n && std::isdigit(s[index]))
            {
                currentNumber = currentNumber * 10 + (s[index] - '0');
                ++index;
            }
            
            if (operation == '+')
            {
                currentValue += currentNumber;
                lastNumber = currentNumber;
            }
            else if (operation == '-')
            {
                currentValue -= currentNumber;
                lastNumber = -currentNumber;
            }
            else if (operation == '*')
            {
                currentValue = currentValue - lastNumber + lastNumber * currentNumber;
                lastNumber = lastNumber * currentNumber;
            }
            else if (operation == '/')
            {
                currentValue = currentValue - lastNumber + lastNumber / currentNumber;
                lastNumber = lastNumber / currentNumber;
            }
            
            while (index < n && s[index] == ' ') ++index;
            
            if (index < n)
                operation = s[index];
            
            ++index;
        }
        
        return currentValue;
    }
};
__________________________________________________________________________________________________
sample 9464 kb submission
class Solution {
public:
    int calculate(string s) {
        if (s.empty()) return 0;
        
        int res = 0, tmp = 0, num = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                while (i < s.size() && isdigit(s[i])) {
                    num = 10 * num + (s[i] - '0');
                    i++;
                }
                i--; //NOTE: the i already points to the next chars in above while-loop
                
                if (op == '+') {
                    res += tmp;
                    tmp = num; 
                    num = 0; //reset num as it is already used
                } else if (op == '-') {
                    res += tmp;
                    tmp = -1 * num;
                    num = 0;
                } else if (op == '*') {
                    tmp *= num;
                    num = 0;
                } else if (op == '/') {
                    tmp /= num;
                    num = 0;
                }
            } else if (s[i] != ' ') {
                op = s[i];
            }
        }
    
        res += tmp;
        
        return res;
    }
};
__________________________________________________________________________________________________
