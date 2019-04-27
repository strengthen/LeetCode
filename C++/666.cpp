__________________________________________________________________________________________________
class Solution {
public:
    int pathSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num / 10] = num % 10;
        }
        helper(nums[0] / 10, m, 0, res);
        return res;
    }
    void helper(int num, unordered_map<int, int>& m, int cur, int& res) {
        int level = num / 10, pos = num % 10;
        int left = (level + 1) * 10 + 2 * pos - 1, right = left + 1;
        cur += m[num];
        if (!m.count(left) && !m.count(right)) {
            res += cur;
            return;
        }
        if (m.count(left)) helper(left, m, cur, res);
        if (m.count(right)) helper(right, m, cur, res);
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int pathSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0, cur = 0;
        unordered_map<int, int> m;
        queue<int> q{{nums[0] / 10}};
        for (int num : nums) {
            m[num / 10] = num % 10;
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            int level = t / 10, pos = t % 10;
            int left = (level + 1) * 10 + 2 * pos - 1, right = left + 1;
            if (!m.count(left) && !m.count(right)) {
                res += m[t];
            }
            if (m.count(left)) {
                m[left] += m[t];
                q.push(left);
            }
            if (m.count(right)) {
                m[right] += m[t];
                q.push(right);
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
