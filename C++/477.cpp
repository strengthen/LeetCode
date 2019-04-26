__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
public:
    
    int totalHammingDistance(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> cnt(32, 0);
        for (auto n : nums) {
            for (int i = 0; i < 32; i++) {
                cnt[i] += (n & 0x1);
                n >>= 1;
            }
        }
        int hd = 0;
        int sz = nums.size();
        for (auto c: cnt) {
            hd += c * (sz - c);
        }
        return hd;
    }
};
__________________________________________________________________________________________________
sample 10140 kb submission
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ret = 0, N = nums.size();
        for (int bit = 0; bit < 32; bit++) {
            int one = 0;
            for (int n: nums)
                if (n & 1 << bit) one++;
            ret += one * (N - one);
        }
        return ret;
                
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
