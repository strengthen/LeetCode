__________________________________________________________________________________________________
sample 180 ms submission
class Solution {
public:
    bool isUsed(vector<int> &A, int start, int index) {
		for (int i = start;i < index;i++)
			if (A[i] == A[index])
				return true;
		return false;
	}
    
	void subfind(vector<int> & nums, vector<int> & tmp, int indx, vector<vector<int>> & ans, set<vector<int>> & m) {
		int len = nums.size();
		// exit condition sequence is very important!!
		//if (indx >= len && tmp.size() >= 2) {
		if (tmp.size() >= 2) {
			ans.push_back(tmp);
		}
		if (indx >= len)
			return;

		// consider optimize the duplicates
		for (int i = indx; i < len; i++) {
            if (i > indx && isUsed(nums, indx, i)) // repeating element
				    continue;
			if (tmp.size() == 0 || (tmp.back() <= nums[i])) {  
				tmp.push_back(nums[i]);
				//pre = nums[i];
				subfind(nums, tmp, i + 1, ans, m);
				tmp.pop_back();
				//pre = nums[i];
				//subfind(nums, tmp, i + 1, ans, m);
			}
			// no need for this one: as pop back next loop will natually deal with this
			// subfind(nums, tmp, i + 1, ans, m); // not using this element
		}
	}

	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> tmp;
        // sort(nums.begin(), nums.end());
        // cannot sort it
		int indx = 0;
		set<vector<int>> map;
		//int pre = INT_MAX;
		subfind(nums, tmp, indx, ans, map);
		return ans;
	}
};
__________________________________________________________________________________________________
sample 21296 kb submission
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<vector<int>> result;
        
        vector<int> curr;
        
        dfs(nums, result, curr, 0);
        
        return result;
    }
    
    void dfs(vector<int> &nums, vector<vector<int>> &result, vector<int> &curr, int pos){
        
        if(curr.size() > 1) result.push_back(curr);
        
        unordered_set<int> hash;        // to eliminate adding the same number in the same call
        
        for(int i=pos; i<nums.size(); i++){
            
            // that means, number has not been called in the same call (i.e. to avoid [4,7] to appear twice)
            if((curr.empty() || curr.back() <= nums[i]) && (hash.find(nums[i]) == hash.end()) ){
                
                curr.push_back(nums[i]);   
                
                dfs(nums, result, curr, i+1);
                
                curr.pop_back();
                
                hash.insert(nums[i]);
            }
        }
        
        return;
    }
};
__________________________________________________________________________________________________
