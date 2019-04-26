__________________________________________________________________________________________________
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cur = 0, cnt = 0;
        for (int num : nums) {
            ++cnt;
            if (num == 0) {
                cur = cnt;
                cnt = 0;
            } 
            res = max(res, cnt + cur);
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, zero = 0, left = 0, k = 1;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++zero;
            while (zero > k) {
                if (nums[left++] == 0) --zero;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, left = 0, k = 1;
        queue<int> q;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) q.push(right);
            if (q.size() > k) {
                left = q.front() + 1; q.pop();
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};