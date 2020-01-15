__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    bool isvalid(int i)
    {
        string str = to_string(i);
        for (auto c:str)
        {
            if (c == '0')
                return false;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        for (int i = 1; i <= n/2; i++)
        {
            if (isvalid(i) && (isvalid(n-i)))
            {
                res.push_back(i);
                res.push_back(n-i);
                return res;
            }
        }
        return (res);
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            if (to_string(a).find('0') == string::npos && to_string(b).find('0') == string::npos)
                return {a, b};
        }
        return {}; // unreachable because at least one valid solution
    }
};
__________________________________________________________________________________________________
