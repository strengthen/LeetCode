__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n < 1 || k <1 ) return false;
        if (n>1000) return false;
        map<int,int> m;
        for(int i = 0;i<n;i++){
            
            if(m[nums[i]] == 1)
                return true;
            if(i>=k)
                m.erase(nums[i-k]);
            
            m[nums[i]] = 1;
            
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 10640 kb submission
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        for (int i=0;i<nums.size();i++)
        {
            for(unsigned int j=i+1;j<nums.size();j++)
            {
                if ((nums[i] == nums[j]) && (i-j<=k || j-i<=k))
                {
                    return true;
                }   
            }   
        }   
        return false;
    }
};
__________________________________________________________________________________________________
