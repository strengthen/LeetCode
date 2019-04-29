__________________________________________________________________________________________________
sample 44 ms submission
static const auto fast = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
} ();

class Solution {
public:
    int sumSubarrayMins(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        constexpr ssize_t mod = 10e8 + 7;
        ssize_t sum = 0;
        std::deque<ssize_t> dq;
        std::vector<ssize_t> aux(nums.size(), 1);
        for (ssize_t i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && nums[dq.back()] > nums[i]) dq.pop_back();
            
            aux[i] *= 1 + i - ((dq.empty() ? -1 : dq.back()) + 1);
            dq.push_back(i);
        }
        
        dq.clear();
        for (ssize_t i = nums.size() - 1; i >= 0; --i) {
            while (!dq.empty() && nums[dq.back()] >= nums[i]) dq.pop_back();
            
            aux[i] *= 1 + (((dq.empty() ? nums.size() : dq.back()) - 1) - i);
            dq.push_back(i);
            
            sum = ((sum % mod) + ((nums[i] * aux[i]) % mod)) % mod;
        }
        
        return sum % mod;
    }
};
__________________________________________________________________________________________________
sample 12576 kb submission
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        constexpr int kMod = 1e9 + 7;
        int ans = 0;
        
        for(int i = 0; i < A.size(); ++i)
        {
            int left = 0;
            for(int j = i - 1; j >= 0 && A[j] > A[i]; --j, ++left);
            int right = 0;
            for(int j = i + 1; j < A.size() && A[j] >= A[i]; ++j, ++right);
            ans = (ans + static_cast<long>(A[i]) * (left + 1) * (right + 1)) % kMod;        
        }
        return ans;
    }
};
__________________________________________________________________________________________________
