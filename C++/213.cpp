__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> c(n, -1);
        int ans1 = rob(nums, 0, n-2, c);
        c = vector<int>(n, -1);
        int ans2 = rob(nums, 1, n-1, c);
        return max(ans1, ans2);
    }
    
    
    int rob(const vector<int>& v, int i, int r, vector<int>& c) {
        if (i > r) return 0;
        if (c[i] >= 0) return c[i];
        c[i] = max(rob(v, i+1, r, c),
                   v[i] + rob(v, i+2, r, c));
        return c[i];
    }
};
__________________________________________________________________________________________________
sample 8672 kb submission
class Solution {
public:
    int rob(const vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        if (nums.size() == 1)
        {
            return nums[0];
        }
        
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        
        return max(rob_simple(nums1), rob_simple(nums2));
    }
    
    int rob_simple(const vector<int>& nums) 
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        // gain[i] = max{gain[i-2] + nums[i], gain[i-1]}
        int gain_i_2 = 0;
        int gain_i_1 = nums[0];
        int gain_i = gain_i_1;
        for (int i = 2; i <= nums.size(); ++i)
        {
            gain_i = max(gain_i_2 + nums[i - 1], gain_i_1);
            gain_i_2 = gain_i_1;
            gain_i_1 = gain_i;
        }
        
        return gain_i;
    }
};

int faster_io = [](){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________
