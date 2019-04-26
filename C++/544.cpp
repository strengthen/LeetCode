__________________________________________________________________________________________________
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> v;
        for (int i = 1; i <= n; ++i) v.push_back(to_string(i));
        while (n > 1) {
            for (int i = 0; i < n / 2; ++i) {
                v[i] = "(" + v[i] + "," + v[n - i - 1] + ")";
            }
            n /= 2;
        }
        return v[0];
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> v;
        for (int i = 1; i <= n; ++i) v.push_back(to_string(i));
        helper(n, v);
        return v[0];
    }
    void helper(int n, vector<string>& v) {
        if (n == 1) return;
        for (int i = 0; i < n; ++i) {
            v[i] = "(" + v[i] + "," + v[n - i - 1] + ")";
        }
        helper(n / 2, v);
    }
};
__________________________________________________________________________________________________
