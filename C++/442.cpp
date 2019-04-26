__________________________________________________________________________________________________
sample 72 ms submission
static int x = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         int len = nums.size();
        
        vector<int> res;
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = -nums[m];
            
            if(nums[m] > 0) res.push_back(m+1);
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
sample 14416 kb submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> res;
        res.reserve(nums.size() / 2);
        std::vector<bool> seen(nums.size() + 1, false);
        for (int num : nums) {
            if (seen[num]) {
                res.push_back(num);
            }
            seen[num] = true;
        }
        return res;
    }
};
__________________________________________________________________________________________________
