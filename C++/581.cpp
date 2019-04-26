__________________________________________________________________________________________________
sample 16 ms submission
#include <bits/stdc++.h>
using namespace std;

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    // 2 6 4 8 10 9 15
    //   l
    //            r
    // mn = 4, mx = 10
    //
    int findUnsortedSubarray(std::vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l + 1 < nums.size() && nums[l+1] >= nums[l]) {
            ++l;
        }
        while (r > 0 && nums[r-1] <= nums[r]) {
            --r;
        }

        if (l >= r) {
            return 0;
        }

        const int mn = *std::min_element(&nums[l], &nums[r+1]),
                  mx = *std::max_element(&nums[l], &nums[r+1]);
        while (l > 0 && nums[l-1] > mn) {
            --l;
        }
        while (r < nums.size()-1 && nums[r+1] < mx) {
            ++r;
        }
        return r - l + 1;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
