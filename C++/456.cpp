__________________________________________________________________________________________________
sample 12 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int cur_min = numeric_limits<int>::max();
        stack <pair <int, int>> range;
        for(const auto& num : nums)
        {
            if(num <= cur_min)
                cur_min = num;
            else
            {
                while(!range.empty() && num >= range.top().second)
                    range.pop();
                if(!range.empty() && num > range.top().first)
                    return true; // range.top().first < num < range.top().second -> 132 pattern
                range.push({cur_min, num});
            }
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 10324 kb submission
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.empty())
            return false;
    
        
        int small = INT_MAX;
        
        for(int i = 0; i < nums.size() ; i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] > nums[j] && nums[j] > small)
                    return true;
            }
            small = min(small, nums[i]);
        }
        
        return false;
    }
};
__________________________________________________________________________________________________
