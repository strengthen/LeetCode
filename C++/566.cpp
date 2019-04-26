__________________________________________________________________________________________________
sample 32 ms submission
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> ans(r);
        int k=0,cnt=0;
        int c1,r1=nums.size();
        if(r1)
            c1=nums[0].size();
        if(c1*r1<r*c)
            return nums;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                cnt++;
                ans[k].push_back(nums[i][j]);
                if(cnt==c)
                    k++,cnt=0;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 11788 kb submission
static auto x = [](){std::ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();

class Solution{
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c){
		int row=nums.size(),col=nums[0].size();
		
		if(row*col!=r*c) return nums;
		
		vector<vector<int>> ans(r,vector<int> (c,0));
		
		 for(int x=0;x<row;x++)
			 for(int y=0;y<col;y++)
				 ans[(x*col+y)/c][(x*col+y)%c]=nums[x][y];
		
		return ans;
	}
};
__________________________________________________________________________________________________
