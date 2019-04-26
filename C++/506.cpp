__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int,int>> rank;
        for(int i = 0; i < nums.size(); ++i){
            rank.push_back({nums[i], i});
        }
        sort(rank.begin(), rank.end(), greater<pair<int,int>>());
        int idx = 1;
        for(auto [v, i]:rank){
            nums[i] = idx++;
        }
        vector<string> res;
        for(auto const i : nums){
            switch(i){
                case 1:
                res.push_back("Gold Medal");
                break;
                case 2:
                res.push_back("Silver Medal");
                break;
                case 3:
                res.push_back("Bronze Medal");
                break;
                default:
                res.push_back(to_string(i));
                break;
            }
        }
        return res;
        
    }
};

__________________________________________________________________________________________________
sample 10784 kb submission
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int rank = 1;
        vector<string> result(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int index = max_element(nums.begin(), nums.end())-nums.begin();    
            nums[index] = INT_MIN;
            if (rank == 1)
                result[index] = "Gold Medal";
            else if (rank == 2)
                result[index] = "Silver Medal";
            else if (rank == 3)
                result[index] = "Bronze Medal";
            else
                result[index] = to_string(rank);
            rank++;
        }
        return result;
    }
};
__________________________________________________________________________________________________
