__________________________________________________________________________________________________
sample 20 ms submission
//n-1个元素加1跟1个元素减1的效果是相同的
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0; 
}();


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_value = nums[0];
        int64_t sum = min_value;
        for(int i=1;i<nums.size();i++){
            sum += nums[i];
            min_value =  min_value>nums[i] ?  nums[i]:min_value;
        }
        return sum - min_value*nums.size();
    }
};
__________________________________________________________________________________________________
sample 11240 kb submission
class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() <= 1)    return 0;
        int min  = INT_MAX;
        for (int n : nums) 
            if(n < min) min = n;
        int res = 0;
        for (int n : nums) 
            res += n - min;
        return res;
    }
};
__________________________________________________________________________________________________
