__________________________________________________________________________________________________
sample 4 ms submission
//dp[i]: the maximum points can be earned from the value <= i;

static auto x = [](){std::ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();

class Solution{
public:
	int deleteAndEarn(vector<int>& nums){
		if(!nums.size()) return 0;
		
		int n=*max_element(nums.begin(),nums.end());
		int count[n+1]={};
		for(int i=0;i<nums.size();i++)
			count[nums[i]]++;
		
		int dp[n+1];
		dp[0]=0;
		dp[1]=count[1];
		
		for(int i=2;i<=n;i++)
			dp[i]=max(dp[i-1],dp[i-2]+i*count[i]);
		
		return dp[n];
	}
};
__________________________________________________________________________________________________
sample 8868 kb submission
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int cnt[10000]={0};
        for (int v:nums) ++cnt[v-1];
        int pre_use=0, pre_no=0, use=0, no=0;
        for (int i=0;i<10000;++i){
            use=cnt[i]*(i+1)+pre_no;
            no=max(pre_use, pre_no);
            pre_use=use;
            pre_no=no;
        }
        return max(use, no);
    }
};
__________________________________________________________________________________________________
