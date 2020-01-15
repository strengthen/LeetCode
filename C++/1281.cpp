__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int subtractProductAndSum(int n) {
        string s = to_string(n);
        int sum= 0, product = 1;
        for (auto i: s)
        {
            sum += i - '0';
            product *= i - '0';
        
        }
        return (product - sum);
        
    }
};
__________________________________________________________________________________________________
0ms
class Solution {
public:
    int subtractProductAndSum(int n) {
        string num = to_string(n);
        int mult,add,solution;
        mult=1;
        add=0;
        solution=0;
        for(int i = 0; i<num.length();i++)
        {
            mult*=(num[i]-'0');
            add+=(num[i]-'0');
        }
        solution = mult-add;
        return solution;
    }
};
__________________________________________________________________________________________________
