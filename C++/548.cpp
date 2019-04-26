__________________________________________________________________________________________________
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if (nums.size() < 7) return false;
        int n = nums.size();
        vector<int> sums = nums;
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        for (int j = 3; j < n - 3; ++j) {
            unordered_set<int> s;
            for (int i = 1; i < j - 1; ++i) {
                if (sums[i - 1] == (sums[j - 1] - sums[i])) {
                    s.insert(sums[i - 1]);
                }
            }
            for (int k = j + 1; k < n - 1; ++k) {
                int s3 = sums[k - 1] - sums[j], s4 = sums[n - 1] - sums[k];
                if (s3 == s4 && s.count(s3)) return true;
            }
        }
        return false;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if (nums.size() < 7) return false;
        int n = nums.size(), target = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 1; i < n - 5; ++i) {
            if (i != 1 && nums[i] == 0 && nums[i - 1] == 0) continue;
            target += nums[i - 1];
            if (helper(nums, target, sum - target - nums[i], i + 1, 1)) {
                return true;
            }
        }
        return false;
    }
    bool helper(vector<int>& nums, int target, int sum, int start, int cnt) {
        if (cnt == 3) return sum == target;
        int curSum = 0, n = nums.size();
        for (int i = start + 1; i < n - 5 + 2 * cnt; ++i) {
            curSum += nums[i - 1];
            if (curSum == target && helper(nums, target, sum - curSum - nums[i], i + 1, cnt + 1)) {
                return true;
            }
        }
        return false;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums = nums;
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        for (int i = 1; i <= n - 5; ++i) {
            if (i != 1 && nums[i] == 0 && nums[i - 1] == 0) continue;
            for (int j = i + 2; j <= n - 3; ++j) {
                if (sums[i - 1] != (sums[j - 1] - sums[i])) continue;
                for (int k = j + 2; k <= n - 1; ++k) {
                    int sum3 = sums[k - 1] - sums[j];
                    int sum4 = sums[n - 1] - sums[k];
                    if (sum3 == sum4 && sum3 == sums[i - 1]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};