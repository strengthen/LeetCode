__________________________________________________________________________________________________
4ms
static const auto _____ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {

public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, countMax = INT_MIN;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] == nums[i] - 1){
                count++;
            } else if(nums[i - 1] == nums[i]){
                
            } else {
                count = 0;
            }
            if(count > countMax) countMax = count;
        }
        
        if(nums.size() == 0 || nums.size() == 1){
            return nums.size();
        }
        
        return countMax + 1;
    }
};
__________________________________________________________________________________________________
8912 kb
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        
        
        int maxNum = 1, curMax = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] - nums[i - 1] == 1) curMax++;
            else if(nums[i] == nums[i - 1]) continue;
            else 
            {
                maxNum = max(maxNum, curMax);
                curMax = 1;
            }
        }
        return max(maxNum, curMax);
    }
};
__________________________________________________________________________________________________
