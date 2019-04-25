__________________________________________________________________________________________________
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int res = 0;
        for (auto a : nestedList) {
            res += getSum(a, 1);
        }
        return res;
    }
    int getSum(NestedInteger ni, int level) {
        int res = 0;
        if (ni.isInteger()) return level * ni.getInteger();
        for (auto a : ni.getList()) {
            res += getSum(a, level + 1);
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return helper(nestedList, 1);
    }
    int helper(vector<NestedInteger>& nl, int depth) {
        int res = 0;
        for (auto a : nl) {
            res += a.isInteger() ? a.getInteger() * depth : helper(a.getList(), depth + 1);
        }
        return res;
    }
};
__________________________________________________________________________________________________
