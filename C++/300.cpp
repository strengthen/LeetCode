__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            vector<int> dp(nums.size());
            int len = 0;
            for (int num : nums)
            {
                int l = 0, r = len;
                while (l != r)
                {
                    int mid = (r + l) / 2;
                    if (dp[mid] < num)
                        l = mid + 1;
                    else
                        r = mid;
                }
                dp[l] = num;
                if (l == len)
                    len++;
            }
            return len;
        }
};
__________________________________________________________________________________________________
sample 8384 kb submission
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(),1);
        int res=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
__________________________________________________________________________________________________
