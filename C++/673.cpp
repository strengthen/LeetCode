__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        vector<vector<pair<int, int>>> dyn(nums.size() + 1);
        int max_so_far = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // bsearch insertion point
            int l = 0, r = max_so_far;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (dyn[mid].back().first < nums[i]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            
            // bsearch number of options
            int options = 1;
            int row = l - 1;
            if (row >= 0) {
                int l1 = 0, r1 = dyn[row].size();
                while (l1 < r1) {
                    int mid = l1 + (r1 - l1) / 2;
                    if (dyn[row][mid].first < nums[i]) {
                        r1 = mid;
                    } else {
                        l1 = mid + 1;
                    }
                }
                
                options = dyn[row].back().second;
                options -= (l1 == 0) ? 0 : dyn[row][l1 - 1].second;
            }
            
            
            dyn[l].push_back({nums[i], (dyn[l].empty() ? options : dyn[l].back().second + options)});
            if (l == max_so_far) {
                max_so_far++;
            }
        }
        
        return dyn[max_so_far-1].back().second;
        
    }
};
__________________________________________________________________________________________________
sample 10004 kb submission
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int ans=0;
        if(nums.size()==0)return 0;
        int dp[nums.size()]{0};
        int dp2[nums.size()]{1};
        for(int i=0;i<nums.size();i++)
        {
            int res=1;
            for(int j=i-1;j>=0;j--)
            {
                
                if(nums[i]>nums[j])
                {
                    if(dp[i]<dp[j]+1)
                    {
                        res=1*dp2[j];
                        dp[i]=dp[j]+1;
                        ans=max(ans,dp[i]);
                    }
                    else if(dp[i]==dp[j]+1)
                    {
                        res+=dp2[j];
                    }
                   
                }
                
            }
            dp2[i]=res;
            cout<<dp[i]<<" "<<dp2[i]<<endl;
        }
    
     
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
           // cout<<dp[i]<<" "<<dp2[i]<<" " ;
            if(ans==dp[i])
            {
                res+=dp2[i];
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
