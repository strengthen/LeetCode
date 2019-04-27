__________________________________________________________________________________________________
sample 4 ms submission
static auto x = [](){std::ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
      if(nums.size()==0) 
           return 0;
        int ma=INT_MIN;
        
        int len=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                //ma=nums[i];
                len++;
            }
            else
            {
              ma=max(len,ma);
                len=1;
            }
            
        }
           ma=max(len,ma);
        return ma;
    }
};
__________________________________________________________________________________________________
sample 9164 kb submission
static auto x = [](){std::ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();

class Solution{
public:
	int findLengthOfLCIS(vector<int>& nums){
		if(!nums.size()) return 0;
                
		int lon=1,rec=1;

		for(int i=1;i<nums.size();i++)
			if(nums[i]>nums[i-1]) lon=max(lon,++rec);
			else rec=1;

		return lon;
	}
};
__________________________________________________________________________________________________
