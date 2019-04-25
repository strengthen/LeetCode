__________________________________________________________________________________________________
sample 60 ms submission
#define myswap(x, y) {(x) ^= (y); (y) ^= (x); (x) ^= (y);}

class Solution {
    using size_type = vector<int>::size_type;
public:
    void wiggleSort(vector<int>& nums) {
        size_type s = nums.size();
        if (s < 2) return;
        
        const auto midptr = nums.begin() + (s >> 1);
        std::nth_element(nums.begin(), midptr, nums.end());
        const auto mid = *midptr;
        
        for (size_type j = ((s - 1) >> 1) << 1, k = 1, i = j, c = 0; c != s; ++c) {
            if (nums[j] < mid) {
                if (i != j) myswap(nums[i], nums[j]);
                i -= 2;
                j -= 2;
            } else if (nums[j] > mid) {
                if (j != k) myswap(nums[j], nums[k]);
                k += 2;
            } else {
                j -= 2;
            }
            if (j >= s) j = ((s >> 1) << 1) - 1;
        }
    }
};


auto gucciGang = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
__________________________________________________________________________________________________
sample 10920 kb submission
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int sz = nums.size();
        if (sz < 2) {
            return;
        }
        auto mid_iter = std::next(std::begin(nums), sz / 2);
        std::nth_element(std::begin(nums), mid_iter, std::end(nums));
        const auto median = *mid_iter;
        for (auto beg = std::begin(nums), larger_pos = beg + 1, smaller_pos = beg + (sz - 1) / 2 * 2; 
             beg < std::end(nums); ) {
            //std::cout << *beg << ": ";
            if (*beg < median && ((beg - std::begin(nums)) % 2 || beg <= smaller_pos)) {
                std::iter_swap(smaller_pos, beg);
                smaller_pos -= 2;
            }
            else if (*beg > median && ((beg - std::begin(nums)) % 2 == 0 || beg >= larger_pos)) {
                std::iter_swap(larger_pos, beg);
                larger_pos += 2;
            }
            else {
                ++beg;
            }
            //std::copy(std::begin(nums), std::end(nums), std::ostream_iterator<int>(std::cout, ","));
            //std::cout << "\n";
        }
    }
};
__________________________________________________________________________________________________
