__________________________________________________________________________________________________
sample 4 ms submission
auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        const int n = nums.size();

        int v1 = INT_MAX;
        int v2 = v1;
        
        for (int i = 0;i < n;i++) {
            if (nums[i] <= v1) {
                v1 = nums[i];
            } else if (nums[i] <= v2) {
                v2 = nums[i];
            } else {
                return true;
            }
        }
        
        return false;
    }
};
__________________________________________________________________________________________________
sample 8996 kb submission
static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min{INT32_MAX}, s_min{INT32_MAX};
        for(int n : nums) {
            if(n <= min) {
                min = n;
            } else if(n <= s_min) {
                s_min = n;
            } else {
                return true;
            }
        }
        return false;
    }
};
__________________________________________________________________________________________________
