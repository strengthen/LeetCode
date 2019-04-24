__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) { 
        std::ios::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);     
        if (nums.empty()) return {};        
        int x = 0; for (auto v: nums) x ^= v;
        int lsb = x&-x;
        int y = 0; for (auto v: nums) if (lsb & v) y^=v;
        return {y, x^y};
    }
};
__________________________________________________________________________________________________
sample 9652 kb submission
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int i;
        for (i = 0; i < n; ++i) {
            sum ^= nums[i];
        }
        sum = sum & -sum;
        int n1 = 0;
        int n2 = 0;
        for (i = 0; i < n; ++i) {
            if (nums[i] & sum) {
                n1 ^= nums[i];
            } else {
                n2 ^= nums[i];
            }
        }
        vector<int> res;
        res.push_back(n1);
        res.push_back(n2);
        return res;
    }
};
__________________________________________________________________________________________________
