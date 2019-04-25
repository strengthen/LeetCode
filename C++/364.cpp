__________________________________________________________________________________________________
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int res = 0;
        vector<vector<int>> v;
        for (auto a : nestedList) {
            helper(a, 0, v);
        }
        for (int i = v.size() - 1; i >= 0; --i) {
            for (int j = 0; j < v[i].size(); ++j) {
                res += v[i][j] * (v.size() - i);
            }
        }
        return res;
    }
    void helper(NestedInteger &ni, int depth, vector<vector<int>> &v) {
        vector<int> t;
        if (depth < v.size()) t = v[depth];
        else v.push_back(t);
        if (ni.isInteger()) {
            t.push_back(ni.getInteger());
            if (depth < v.size()) v[depth] = t;
            else v.push_back(t);
        } else {
            for (auto a : ni.getList()) {
                helper(a, depth + 1, v);
            }
        }
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int res = 0;
        vector<int> v;
        for (auto a : nestedList) {
            helper(a, 0, v);
        }
        for (int i = v.size() - 1; i >= 0; --i) {
            res += v[i] * (v.size() - i);
        }
        return res;
    }
    void helper(NestedInteger ni, int depth, vector<int> &v) {
        if (depth >= v.size()) v.resize(depth + 1);
        if (ni.isInteger()) {
            v[depth] += ni.getInteger();
        } else {
            for (auto a : ni.getList()) {
                helper(a, depth + 1, v);
            }
        }
    }
};
__________________________________________________________________________________________________
