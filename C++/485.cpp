__________________________________________________________________________________________________
sample 20 ms submission
static int fast_io = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int begin=0;
        int end = 0;
        int len = 0;
        for(int i = 0; i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                end++;
            }
            else
            {
                begin++;
                end = begin;
            }
            if(end-begin>len)
                len =end-begin;
        }
        return len;
    }
};
__________________________________________________________________________________________________
sample 11684 kb submission
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_cnt = 0, cnt = 0;
        for (auto n : nums) {
            if (n == 1) max_cnt = max(++cnt, max_cnt);
            else cnt = 0;
        }
        return max_cnt;
    }
};
__________________________________________________________________________________________________
