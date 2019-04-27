__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string solveEquation(string equation) {
        // ax + b = 0
        int a = 0, b = 0, coef;
        bool sign = true, on_right = false;
        
        int i = 0;
        while (i < equation.size()) {
            if (equation[i] == 'x') {
                a += (2 * sign - 1) * (1 - 2 * on_right);
                ++i;
            } else if (equation[i] == '+' || equation[i] == '-') {
                sign = equation[i] == '+' ? true : false;
                ++i;
            } else if (equation[i] == '=') {
                on_right = true;
                sign = true;
                ++i;
            } else {
                tie(coef, i) = readCoef(equation, i);
                if (i < equation.size() && equation[i] == 'x') {
                    a += (2 * sign - 1) * (1 - 2 * on_right) * coef;
                    ++i;
                } else {
                    b += (2 * sign - 1) * (1 - 2 * on_right) * coef;
                }
            }
        }
                
        // ax + b = 0
        if (a == 0 && b == 0) {
            return "Infinite solutions";
        } else if (a == 0 && b != 0) {
            return "No solution";
        } else {
            return "x=" + to_string(-b / a);
        }
    }
    
private:
    tuple<int, int> readCoef(const string & equation, const int i) {
        int j = i + 1;
        while (j < equation.size() && isdigit(equation[j])) {
            ++j;
        }
        return {stoi(equation.substr(i, j - i)), j};
    }
};
__________________________________________________________________________________________________
sample 8488 kb submission
class Solution {
public:
    string solveEquation(string equation) {
        int sign = 1, coeff = 0, num = 0, flag = 1, sum = 0;
        for (int i = 0; i < equation.size(); i++) {
            char c = equation[i];
            if (c == '=') {
                if (num != 0) {
                    sum += flag*sign*num;
                    num = 0;
                    sign = 1;
                }
                flag = -1; 
            }
            if (isdigit(c)) {
                num = num*10 + c - '0';
            }
            if (c == 'x') {
                if (num == 0 && (i == 0 || !isdigit(equation[i-1]))) {
                    num = 1;
                }
                coeff += flag*sign*num;
                num = 0;
                sign = 1;
            }
            if (c == '+' || c == '-' || i == equation.size()-1) {
                sum += flag*sign*num;
                num = 0;
                sign = c == '+' ? 1 : -1;
            }
        }
        if (coeff == 0 && sum == 0) {
            return "Infinite solutions";
        } else if (coeff == 0 && sum != 0) {
            return "No solution";
        } else {
            return "x=" + to_string(-sum/coeff);
        }
    }
};
__________________________________________________________________________________________________
