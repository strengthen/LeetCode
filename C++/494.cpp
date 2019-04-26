__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=(S+sum)/2; //这是需要找到的目标值
        return sum<S || (S+sum)%2!=0?0:helper(nums,target); //先来检验是否能够划分
    }
private:
    int helper(vector<int>& nums,int target){
        vector<int> dp(target+1,0);
        dp[0]=1; //和为0只有一种可能
        for(auto it:nums)
            for(int j=target;j>=it;--j)
                dp[j]+=dp[j-it];
        return dp[target];
    }
};
__________________________________________________________________________________________________
sample 9136 kb submission
class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int count = 0;
        calculate(nums,S,0,0,count);  
        return count;
    }
    
    void calculate(vector<int>& nums, int S, int len, int sum, int &count)
    {
        if(len == nums.size())
        {
            if(sum == S)
                count++;
        }
        else
        {
            calculate(nums,S,len+1,sum+nums[len],count);
            calculate(nums,S,len+1,sum-nums[len],count);
        }        
    }
};
__________________________________________________________________________________________________
