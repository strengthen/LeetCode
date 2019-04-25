__________________________________________________________________________________________________
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int res = 0;
        unordered_map<int, vector<int>> m;
        m[nums[0]].push_back(0);
        vector<int> sum = nums;
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] += sum[i - 1];
            m[sum[i]].push_back(i);
        }
        for (auto it : m) {
            if (it.first == k) res = max(res, it.second.back() + 1);
            else if (m.find(it.first - k) != m.end()) {
                res = max(res, it.second.back() - m[it.first - k][0]);
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == k) res = i + 1;
            else if (m.count(sum - k)) res = max(res, i - m[sum - k]);
            if (!m.count(sum)) m[sum] = i;
        }
        return res;
    }
};
__________________________________________________________________________________________________
