__________________________________________________________________________________________________
sample 56 ms submission
auto __ = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //this part of course is dp method
        //this part we try to use the method ,we call slide  window, this is good method to deal with this problem.
        //so we try to do it using the slide window method
        if(k<=1)
            return 0; 
        int left = 0;
        int product = 1;
        int retv =  0;
        for(int right =0;right<nums.size();right++)
        {
            product *= nums[right];
            while(product>=k)
            {
                product /= nums[left];
                left++;
            }
            retv +=(right-left +1);
        }
        return retv;
    }
};
__________________________________________________________________________________________________
sample 18452 kb submission
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        // vector<long long>dp(n,0);
        int count=0;
        long long prod=1;
        int left=0;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            while(prod>=k&&left<=i){
                prod/=nums[left++];
                
            }
            count+=i-left+1;
            
        }
        return count;
    }
};
__________________________________________________________________________________________________
