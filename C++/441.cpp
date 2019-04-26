__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(1. + 8.*n) - 1)/2.;
    }
};
__________________________________________________________________________________________________
sample 8260 kb submission
class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        for (int i = 1; n > 0; ++i) {
            n -= i;
            if (n >= 0) ++count;
        }
        return count;
    }
};

static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
