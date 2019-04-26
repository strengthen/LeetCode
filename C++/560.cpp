__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        if(nums.size()==0)return 0;
        int sum=nums[0];
        int ans=(k==nums[0]);
        m[nums[0]]++;
        m[0]++;
        int lookup;
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            lookup=sum-k;
            ans+=(m.find(lookup)==m.end())?0:m[lookup];
            m[sum]++;
        }
        return ans;
        
    }
};
static auto _=[](){cin.tie(nullptr);ios::sync_with_stdio(false);return 0;}();
__________________________________________________________________________________________________
sample 10172 kb submission
class Solution {
public:
    // Runtime: O(N^2)
    // Space: O(1)
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k) ++ret;
            }
        }
        return ret;
    }
};
__________________________________________________________________________________________________
