__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        helper(n, 2, {}, res);
        return res;
    }
    void helper(int n, int start, vector<int> out, vector<vector<int>> &res) {
        if (n == 1) {
            if (out.size() > 1) res.push_back(out);
        } else {
            for (int i = start; i <= n; ++i) {
                if (n % i == 0) {
                    out.push_back(i);
                    helper(n / i, i, out, res);
                    out.pop_back();
                }
            }
        }
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        helper(n, 2, {}, res);
        return res;
    }
    void helper(int n, int start, vector<int> out, vector<vector<int>> &res) {
        for (int i = start; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                vector<int> new_out = out;
                new_out.push_back(i);
                helper(n / i, i, new_out, res);
                new_out.push_back(n / i);
                res.push_back(new_out);
            }
        }
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                vector<vector<int>> v = getFactors(n / i);
                vector<int> out{i, n / i};
                res.push_back(out);
                for (auto a : v) {
                    if (i <= a[0]) {
                        a.insert(a.begin(), i);
                        res.push_back(a);
                    }
                }
            }
        }
        return res;
    }
};