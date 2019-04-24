__________________________________________________________________________________________________
8ms
int optimization = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for (int n : nums) {
            ans ^= n;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
9416 kb
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result ^= nums[i];
        }
        
        return result;
    }
};
__________________________________________________________________________________________________
