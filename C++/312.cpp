__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int base = applyHeuristic(nums);
        return base + applyDP(nums);
    }
    int applyHeuristic(vector<int>& nums) {
        const int n = nums.size() - 2;
        const int maximum = *std::max_element(nums.begin(), nums.end());
        int result = 0;
        int i = 1;
        int j = 2;
        while (j <= n + 1) {
            int a = nums[i - 1];
            int b = nums[i];
            int c = nums[j];
            if (b <= a && b <= c && (a * c * (b + maximum)) >= (b * maximum * (a + c))) {
                result += a * b * c;
                if (i > 1) {
                    --i;
                } else {
                    nums[i] = nums[j];
                    ++j;
                }
            } else {
                ++i;
                nums[i] = nums[j];
                ++j;
            }
        }
        nums.resize(i + 1);
        return result;
    }
    int applyDP(const vector<int>& nums) {
        const int n = nums.size();
        vector<int> dr(n, 0);
        vector<vector<int>> dp(n, dr);
        for (int k = 2; k < n; ++k){
            for (int left = 0; left < n - k; ++left) { 
                int right = left + k;
                for (int i = left + 1; i < right; ++i) {
                    dp[left][right] = max(
                        dp[left][right],
                        nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
                }
            }
        }        
        return dp[0][n - 1];  
    }
};
__________________________________________________________________________________________________
sample 8536 kb submission
class Solution 
{
public:
    int maxCoins(vector<int>& nums) 
    {
        int arr[nums.size()+2];
        for(int i=1;i<nums.size()+1;++i)arr[i] = nums[i-1];
        arr[0] = arr[nums.size()+1] = 1;
        
        int dp[nums.size()+2][nums.size()+2]={};
        int n = nums.size()+2;
        
        for(int k=2;k<n;++k)
        {
            for(int left = 0;left<n-k;++left)
            {
                int right = left + k;
                for(int i=left+1;i< right; ++i)
                {
                    dp[left][right] = max(dp[left][right],arr[left]*arr[i]*arr[right] + dp[left][i] + dp[i][right]);
                }
            }    
        }
        return dp[0][n-1];
    }
};
__________________________________________________________________________________________________
