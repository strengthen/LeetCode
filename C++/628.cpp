__________________________________________________________________________________________________
sample 16 ms submission

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() == 3)
            return nums[0]*nums[1]*nums[2];
        
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN; 
        int min1 = INT_MAX, min2 = INT_MAX; 
        
        for(auto i: nums){
            if( i >= max1 )
            {
                max3 = max2; 
                max2 = max1; 
                max1 = i;
            } 
            else if (i >= max2)
            {
                max3 = max2; 
                max2 = i;
            }
            else if( i > max3 )
            {
                max3 = i; 
            }; 
            
            if( i <= min1 )
            {
                min2 = min1; 
                min1 = i;
            }
            else if( i < min2 )
            {
                min2 = i;
            }; 
        };
        
        return(max(max1*max2*max3, min1*min2*max1));
    };
};
    static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
sample 10728 kb submission
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        for(auto n:nums){
            cout << n << endl;
        }
        int result=INT_MIN;
        for(int i=0;i<nums.size()-2;i++){
            result=max(result,nums[i]*nums[i+1]*nums[i+2]);
            result=max(result,nums[i]*nums[i+1]*nums[nums.size()-1]);
            result=max(result,nums[i]*nums[nums.size()-2]*nums[nums.size()-1]);
        }
        return result;
    }
};
static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
