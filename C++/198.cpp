__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> dp(nums.size()+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i<dp.size(); i++){
            dp[i] = max(dp[i-2]+nums[i-1],dp[i-1]);
        }
        return dp[nums.size()];
    }
};
__________________________________________________________________________________________________
sample 8696 kb submission
static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size >= 2) nums[1] = max(nums[0], nums[1]);
        for(unsigned int i=2; i<size; ++i)
            nums[i] = max((nums[i]+nums[i-2]), nums[i-1]);
        
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        return max(nums[size-1], nums[size-2]);
    }
};
__________________________________________________________________________________________________
