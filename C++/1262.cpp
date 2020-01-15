__________________________________________________________________________________________________
sample 12 ms submission
#pragma GCC optimize(3)
static auto FASTIO = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();

class Solution {
public:
    int maxSumDivThree(vector<int> &nums) {
        int p1 = 100000, p2 = 100000, q1 = 100000, q2 = 100000;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 3 == 0) return sum;
        else {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] % 3 == 1) {
                    if (nums[i] <= p1) {
                        q1 = p1;
                        p1 = nums[i];
                    } else if (nums[i] <= q1) {
                        q1 = nums[i];
                    }
                }
                if (nums[i] % 3 == 2) {
                    if (nums[i] <= p2) {
                        q2 = p2;
                        p2 = nums[i];
                    } else if (nums[i] <= q2) {
                        q2 = nums[i];
                    }
                }
            }
            if (sum % 3 == 1) {
                if (q2 == 100000) {
                    if (p1 == 100000) {
                        return 0;
                    } else {
                        return sum - p1;
                    }
                } else {
                    return sum - min(p1, p2 + q2);
                }
            } else {
                if (p1 == 100000) {
                    if (p2 == 100000)
                        return 0;
                    else {
                        return sum - p2;
                    }
                } else {
                    return sum - min(p2, q1 + p1);
                }
            }
        }
    }
};
__________________________________________________________________________________________________
sample 20 ms submission
#pragma GCC optimize(3)
static auto FASTIO = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();

class Solution {
public:
    int maxSumDivThree(vector<int> &nums) {
        int p1 = 100000, p2 = 100000, q1 = 100000, q2 = 100000;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 3 == 0) return sum;
        else {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] % 3 == 1) {
                    if (nums[i] <= p1) {
                        q1 = p1;
                        p1 = nums[i];
                    } else if (nums[i] <= q1) {
                        q1 = nums[i];
                    }
                }
                if (nums[i] % 3 == 2) {
                    if (nums[i] <= p2) {
                        q2 = p2;
                        p2 = nums[i];
                    } else if (nums[i] <= q2) {
                        q2 = nums[i];
                    }
                }
            }
            if (sum % 3 == 1) {
                if (q2 == 100000) {
                    if (p1 == 100000) {
                        return 0;
                    } else {
                        return sum - p1;
                    }
                } else {
                    return sum - min(p1, p2 + q2);
                }
            } else {
                if (p1 == 100000) {
                    if (p2 == 100000)
                        return 0;
                    else {
                        return sum - p2;
                    }
                } else {
                    return sum - min(p2, q1 + p1);
                }
            }
        }
    }
};
__________________________________________________________________________________________________
