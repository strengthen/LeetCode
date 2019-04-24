__________________________________________________________________________________________________
sample 36 ms submission
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> result(n, 1);
        int left_fac = 1, right_fac = 1, i = 0;
        while (i < n)
        {
            result[i] *= left_fac;
            left_fac *= nums[i];
            result[n - ++i] *= right_fac;
            right_fac *= nums[n - i];
        }
        
        return result;
    }
};
__________________________________________________________________________________________________
sample 12284 kb submission
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(),1);
        int forward = 1;
        int backward = 1;
        int n = nums.size();
        for(int i = 0; i < nums.size(); ++i)
        {
            output[i] *= forward;
            forward *= nums[i];
            output[n-1-i] *= backward;
            backward *= nums[n-1-i];
        }    
        return output;
    }
};
__________________________________________________________________________________________________
