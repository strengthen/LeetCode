__________________________________________________________________________________________________
4ms
class Solution {
public:
    #define max(x, y) (x > y ? x : y)
    #define min(x, y) (x < y ? x : y)
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int dmax = nums[0], dmin = nums[0];
        int tmax = nums[0];
        int tmpmax;
        for (int i = 1; i < nums.size(); ++i) {
            tmpmax = max(nums[i], max(dmax*nums[i], dmin*nums[i]));
            dmin = min(nums[i], min(dmax*nums[i], dmin*nums[i]));
            dmax = tmpmax;
            tmax = max(dmax, tmax);
        }
        return tmax;
    }
};
__________________________________________________________________________________________________
8828 kb
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int currMax = nums[0];
        int currMin = nums[0];
        int maxP = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            const int val = nums[i];
            int cmax = currMax * val;
            int cmin = currMin * val;
            currMax = max(val, max(cmax, cmin));
            currMin = min(val, min(cmax, cmin));
            maxP = max(currMax, maxP);
        }
        return maxP;
    }
};
__________________________________________________________________________________________________
