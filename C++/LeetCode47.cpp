__________________________________________________________________________________________________
20ms
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
	vector<int> tmp = nums;
	sort(nums.begin(), nums.end());
	do{
	    std::copy(nums.begin(), nums.end(), tmp.begin());
	    result.push_back(tmp);
	}while(next_permutation(nums.begin(), nums.end()));
	return result;
    }    
};
__________________________________________________________________________________________________
24ms
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out, visited(nums.size(), 0);
        sort(nums.begin(), nums.end());
        permuteUniqueDFS(nums, 0, visited, out, res);
        return res;
    }
    void permuteUniqueDFS(vector<int>& nums, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if (level >= nums.size()) {res.push_back(out); return;}
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == 1) continue;
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
            visited[i] = 1;
            out.push_back(nums[i]);
            permuteUniqueDFS(nums, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};
__________________________________________________________________________________________________
28ms
class Solution {
private:
    void perm(vector<int>& nums, vector<vector<int>>& result, int begin)
    {
        if(begin >=nums.size())
        {
            result.push_back(nums);
            return;
        }
        unordered_set<int> myset;
        perm(nums, result, begin + 1);
        myset.insert(nums[begin]);
        for(int i = begin + 1;i<nums.size();i++)
        {  
            if(myset.count(nums[i] )== 0)
            {
                swap(nums[begin], nums[i]);
                perm(nums, result, begin + 1);
                swap(nums[begin], nums[i]);
                myset.insert(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        perm(nums, result, 0);
        return result;
    }
};
__________________________________________________________________________________________________
9596 kb
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector< vector<int> > v;
        sort(nums.begin(), nums.end());
        
        do {
            v.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        
        return v;                    
    }
};
__________________________________________________________________________________________________
9652 kb
class Solution {
public:
    void print_vector(vector<int> &nums) {
        for (size_t i = 0 ; i <  nums.size(); i++) {
            cout<<nums[i]<<",";
        }
        cout<<endl;
    }
    void next_perm(vector<int> &nums) {
        int pivot = nums.size()-1;
        while(pivot >=1 && nums[pivot-1] >= nums[pivot]) { 
            pivot--;    
        }
        if (pivot == 0) {
            sort(nums.begin(), nums.end());
            return ;
        }
        int swap_point = pivot-1;
        for(int j = pivot; j<nums.size() ; j++) {
            if (nums[j]>nums[pivot-1]) {
                swap_point = j;
            }
        }
        cout<<swap_point<<pivot;
        print_vector(nums);
        swap(nums[pivot -1], nums[swap_point]);
        reverse(nums.begin() + pivot, nums.end());
        print_vector(nums);
        return;
        
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> solution;
        sort(nums.begin(), nums.end());
        vector<int> new_nums (nums);
        do{
            solution.push_back(new_nums);
            next_perm(new_nums);
            
        }while(new_nums!=nums);
            return solution;
        
    }
};
__________________________________________________________________________________________________