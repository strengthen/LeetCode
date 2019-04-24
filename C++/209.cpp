__________________________________________________________________________________________________
sample 4 ms submission
auto opt = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}();
struct Solution {
    int minSubArrayLen(int s, std::vector<int> &nums) {
        const int N = nums.size();
        const int target = s;
        int sum = 0, left = 0, right = 0;
        int minlen = N + 1;
        for (; right < N; ++right) {
            sum += nums[right];
            if (sum >= target) {
                for (; left <= right && sum >= target; ++left) {
                    minlen = std::min(minlen, right - left + 1);
                    if (minlen == 1) return 1; // Return early if possible.
                    sum -= nums[left];
                }
            }
        }
        return minlen == (N + 1) ? 0 : minlen;
    }
};
__________________________________________________________________________________________________
sample 9752 kb submission
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int residual = s;
            int curLen = 0;
            for (int j = i; j < nums.size(); j++) {
                residual -= nums[j];
                curLen += 1;
                if (residual <= 0) {
                    minLen = min(minLen, curLen);
                    break;
                }
            }
        }
        if (minLen == INT_MAX)
            return 0;
        return minLen;
    }
};
__________________________________________________________________________________________________
