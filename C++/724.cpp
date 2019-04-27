__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int length = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int left_sum = 0;
        int prev = 0;
        for (int i = 0; i< length; ++i) {
            left_sum += prev;
            prev = nums[i];
            sum -= nums[i];
            if (left_sum == sum) return i;
        }
        return -1;
    }
};

auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
sample 13796 kb submission
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s = 0;
        for (int num: nums)
            s += num;

        int curr_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (curr_sum * 2 + nums[i] == s)
                return i;

            curr_sum += nums[i];
        }

        return -1;
    }
};
__________________________________________________________________________________________________
