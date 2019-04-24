__________________________________________________________________________________________________
// O(n^3)
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < int(nums.size() - 2); ++i) {
            int left = i + 1, right = nums.size() - 1, sum = target - nums[i];
            for (int j = left; j <= right; ++j) {
                for (int k = j + 1; k <= right; ++k) {
                    if (nums[j] + nums[k] < sum) ++res;
                }
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
// O(n^2)
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    res += right - left;
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
