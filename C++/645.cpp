__________________________________________________________________________________________________
sample 12 ms submission
#define LL long long
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        LL sum = 0;
        LL sum2 = 0;
        for(auto &num:nums){
            sum+=num;
            sum2+=num*num;
        }
        LL n = nums.size();
        sum = n*(n+1)/2 - sum;
        sum2 = n*(n+1)*(2*n+1)/6 - sum2;
        sum2 = sum2/sum;
        
        return {(sum2-sum)/2,(sum2+sum)/2};
        
    }
};
static int x = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
sample 10620 kb submission
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        auto i = 0;
        auto missing = -1, duplicate = -1;            
        
        sort(nums.begin(), nums.end());        
        while ((missing==-1 || duplicate==-1) && i < nums.size()-1) {            
            if (nums[i] == nums[i+1]) {
                duplicate = nums[i];                
            }
            
            if (missing == -1 && nums[i] > i+1 ) {
                missing = i+1;
            } else if (missing == -1 && nums[i] < i+1 && nums[i+1]==i+2) {
                missing = i+1;
            }
           
            ++i;
        }
        
        if (nums[nums.size()-1] < nums.size()) {
            missing = nums.size();
        }
        
        vector<int> ans({duplicate, missing});
        return ans;
    }
};
__________________________________________________________________________________________________
