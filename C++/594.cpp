__________________________________________________________________________________________________
sample 60 ms submission
static const auto fast = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
} ();

class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        std::unordered_map<ssize_t, ssize_t> freq;
        for (ssize_t i = 0; i < nums.size(); ++i) {
            ++freq[nums[i]];
        }
        
        ssize_t max = 0;
        for (const auto& pair : freq) {
            auto it = freq.find(pair.first + 1);
            if (it != freq.end()) {
                max = std::max(max, pair.second + it->second);
            }
        }
        
        return max;
    }
};
__________________________________________________________________________________________________
sample 12456 kb submission
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        int res=0,sum=0,j=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            sum=0;
            j=i+1;
            while(j<nums.size()&&nums[i]>=nums[j]-1)
            {
                sum++;
                j++;
            }
            if(nums[j-1]>nums[i])
                res=max(res,sum+1);
        }
        return res;
    }
};
__________________________________________________________________________________________________
