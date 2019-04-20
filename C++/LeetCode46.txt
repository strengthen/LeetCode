__________________________________________________________________________________________________
12ms
static int cheat = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        permuteImpl(result, std::move(nums), 0);
        return result;
    }
    
    void permuteImpl(std::vector<std::vector<int>>& result
                     , std::vector<int> nums
                     , int f)
    {        
        if (f == nums.size())
        {
            result.emplace_back(std::move(nums));
            return;
        }

        for (auto m = f; m != nums.size(); ++m)
        {
            std::swap(nums[f], nums[m]);
            permuteImpl(result, nums, f + 1);
        }
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        vector<int> out, visited(num.size(), 0);
        permuteDFS(num, 0, visited, out, res);
        return res;
    }
    void permuteDFS(vector<int>& num, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if (level == num.size()) {res.push_back(out); return;}
        for (int i = 0; i < num.size(); ++i) {
            if (visited[i] == 1) continue;
            visited[i] = 1;
            out.push_back(num[i]);
            permuteDFS(num, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};
__________________________________________________________________________________________________
16ms
class Solution {
private:
    unordered_set<int> visited;
    
    void util(vector<int>& nums,vector<vector<int>>& result,vector<int> res){
        if(res.size() == nums.size()){
            result.push_back(res);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(!visited.count(nums[i])){
                visited.insert(nums[i]);
                res.push_back(nums[i]);
                util(nums,result,res);
                res.pop_back();
                visited.erase(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> res;
        util(nums,result,res);
        return result;
    }
};
__________________________________________________________________________________________________
8944 kb 
class Solution {
public:
	void step( vector<int>* item, size_t n, size_t level, vector<int>& raw ) {
		if( raw.size() < level ) {
			return;
		}
		size_t istart = raw.size() - level;
		if( level == 2 ) {
			item[0][istart] = raw[istart];
			item[0][istart+1] = raw[istart+1];
			item[1][istart+1] = raw[istart];
			item[1][istart] = raw[istart+1];
			return;
		}
		else if( level == 1 ) {
			item[0][istart] = raw[istart];
			return;
		}
		
		size_t nGroup = n / level;
		for( size_t i = 0; i < level; i++ ) {
			std::swap(raw[istart], raw[istart+i]);
			for( size_t ig = 0; ig < nGroup; ig++ ) {
				item[i*nGroup + ig][istart] = raw[istart];
			}
			step(item + i * nGroup, nGroup, level - 1,raw);
			std::swap(raw[istart], raw[istart+i]);
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		size_t facn = 1;
		for( size_t i = 1; i <= nums.size(); i++ ) {
			facn *= i;
		}
		vector<vector<int>> ret;
		if( facn == 0 ) {
			return ret;
		}
		ret.resize(facn,nums);
		step((vector<int>*)ret.data(), ret.size(), nums.size(), nums );
		return std::move(ret);
	}
};
__________________________________________________________________________________________________
8968 kb 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        result.push_back(nums);
        
        while(next_permutation(nums.begin(),nums.end()))
            result.push_back(nums);
        
        return result;
    }
};
__________________________________________________________________________________________________