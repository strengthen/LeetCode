__________________________________________________________________________________________________
8ms
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        sort(nums.begin(), nums.end());
        helper(nums, 0, out, res);
        return res;
    }
    
    void helper(vector<int>& nums, int level, vector<int>& out, vector<vector<int>>& res) {
        res.push_back(out);
        int n = nums.size();
        for (int i = level; i < n; ++i) {
            if (i > level && nums[i] == nums[i - 1]) continue;
            out.push_back(nums[i]);
            helper(nums, i + 1, out, res);
            out.pop_back();
        }
    }
};
__________________________________________________________________________________________________
9096 kb
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtrack(res, cur, nums, 0);
        return res;
    }
private:
    void backtrack(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int start) {
        res.push_back(cur);
        for(int i=start; i<nums.size(); i++) {
            if(i>start && nums[i]==nums[i-1]) continue;
            cur.push_back(nums[i]);
            backtrack(res, cur, nums, i+1);
            cur.pop_back();
        }
    }
};
__________________________________________________________________________________________________
