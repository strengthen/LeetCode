__________________________________________________________________________________________________
sample 8 ms submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int m = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + m, nums.end());
        int median = nums[m];
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            ret += abs(nums[i] - median);
        }
        return ret;
    }
};
__________________________________________________________________________________________________
sample 9420 kb submission
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int size = nums.size();
        int sizehalf = nums.size()/2;
        int ans = 0;
        sort(nums.begin() , nums.end());
        for(int i=0 ; i<sizehalf ; i++){
            ans+=abs(nums[i] - nums[size-i-1]);
        }
        return ans;
        
    }
};
__________________________________________________________________________________________________
