__________________________________________________________________________________________________
4ms
static int fast_io = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
struct Solution {
int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for( auto num : nums){
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }
    return ones;
}
};
__________________________________________________________________________________________________
9432 kb
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        vector<int> bits(32);
        
        for (int n: nums) {
            for (int i = 0; i < bits.size(); ++i) {
                bits[i] += !!(n & (1<<i));
            }
        }
        
        int x = 0;
        
        for (int i = 0; i < bits.size(); ++i)            
            x += (!!(bits[i] % 3 != 0) << i);
        
        return x;
    }
};
__________________________________________________________________________________________________
