__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> curArray;
        help(ret, curArray, k, n, 1, 0);
        return ret;
    }
    
    void help(vector<vector<int>>& ret, vector<int>& curArray, int k, int target, int curIndex, int curSum) {
        if(curArray.size() > k)
            return;
        if(curSum == target && curArray.size() == k) {
            ret.push_back(curArray);
            return;
        }else if(curSum > target) {
            return;
        }
        for(int i = curIndex; i <= 9; i++) {
            curArray.push_back(i);
            curSum += i;
            help(ret, curArray, k, target, i+1, curSum);
            curSum -= i;
            curArray.pop_back();
        }
        
    }
};
__________________________________________________________________________________________________
sample 8396 kb submission
class Solution {
    int n;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->n = n;
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res, tmp, 0, k, 1);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& tmp, int sum, int k, int start) {
        if (k == 0) {
            if (sum == n) {
                res.emplace_back(tmp);
            }
            return;
        }
        if (sum >= n) {
            return;
        }
        for (int i = start; i <= 9; ++i) {
            tmp.emplace_back(i);
            helper(res, tmp, sum + i, k - 1, i + 1);
            tmp.pop_back();
        }
    }
};
__________________________________________________________________________________________________
