__________________________________________________________________________________________________
8ms
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res(1);
        for(int i = 0; i<nums.size(); ++i){
            int size = res.size();
            for(int j = 0; j<size; ++j){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
        
    }
};
__________________________________________________________________________________________________
8812 kb
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        // 【二周目】
        vector<vector<int>> results;
        // sort [nums] into non-descending order
        sort(nums.begin(), nums.end());
        vector<int> subset;
        // [1]-root has nums.size() children and every node in tree is a subset
        // DFS_helper_1(results, subset, nums, 0);
        // [2]-it is a binary tree and every leaf is a subset
        // DFS_helper_2(results, subset, nums, 0);
        // [3]-use bit operation
        BitHelper(results, subset, nums);
        return results;
    }
private:
    void DFS_helper_1(vector<vector<int>>& results,
                      vector<int>& subset,
                      vector<int>& nums,
                      int start)
    {
        results.push_back(subset);
        for (int i = start; i < nums.size(); i ++)
        {
            subset.push_back(nums[i]);
            DFS_helper_1(results, subset, nums, i + 1);
            subset.pop_back();
        }
    }
    void DFS_helper_2(vector<vector<int>>& results,
                      vector<int>& subset,
                      vector<int>& nums,
                      int index)
    {
        if (index == nums.size())
        {
            results.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        DFS_helper_2(results, subset, nums, index + 1);
        subset.pop_back();
        DFS_helper_2(results, subset, nums, index + 1);
    }
    void BitHelper(vector<vector<int>>& results,
                   vector<int>& subset,
                   vector<int>& nums)
    {
        int amount = 1 << nums.size();
        for (int i = 0; i < amount; i ++)
        {
            subset.clear();
            for (int j = 0; j < nums.size(); j ++)
            {
                int tmp = 1 << j;
                if (i & tmp)
                    subset.push_back(nums[j]);
            }
            results.push_back(subset);
        }
    }
};
__________________________________________________________________________________________________
