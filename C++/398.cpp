__________________________________________________________________________________________________
sample 40 ms submission
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution{
    vector<int>nums;
    int size;
public:
    Solution(vector<int>nums) {
        size = (int)nums.size();
        this->nums = move(nums);
    };
    int pick(int target) const {
        if (size) {
            const int*pNums = &nums[0], *p = pNums, *pe = p + size;
            int count = 0, result = 0;
            while (p < pe) {
                if (*p == target) {
                    if (!(rand() % ++count)) { result = (int)(p - pNums); }
                }
                ++p;
            }
            return result;
        }
        return -1;
    };
};
__________________________________________________________________________________________________
sample 17868 kb submission
class Solution {
    vector<int> nums_;
public:
    Solution(vector<int> nums) 
    {
        nums_ = move(nums);
    }
    
    int pick(int target) 
    {
        int times = 1;
        int ret = -1;
        for(int i = 0;i < nums_.size();i++)
        {
            int n = nums_[i];
            if(target == n)
            {
                if(0 == rand() % (times))
                {
                    ret = i;
                }
                times++;
            }
        }
        
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
__________________________________________________________________________________________________
