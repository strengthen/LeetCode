__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int, vector<int>> um;
        vector<vector<int>> ans;
        if(n==0)
            return ans;
        
        for(int i =0;i<n;i++)
        {
            if(um[groupSizes[i]].size()==groupSizes[i])
            {
                ans.push_back(um[groupSizes[i]]);
                um[groupSizes[i]].clear();
            }
            um[groupSizes[i]].push_back(i);
        }
        for(auto elem: um)
        {
            ans.push_back(elem.second);
        }
        return ans;
    }
};
static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        if(groupSizes.size() == 0) {
            return ans;
        }
        
        unordered_map<int,vector<int>> groups;
        for(int i = 0; i < groupSizes.size(); ++ i){
            groups[groupSizes[i]].push_back(i);
        }
        for(pair<int, vector<int>> group : groups){
            int i = 0, groupSize = group.first;
            for(; i < group.second.size(); i += groupSize){
                vector<int> curGroup(groupSize, 0);
                for(int j = 0; j < groupSize; ++ j){
                    curGroup[j] = group.second[i + j];
                }
                ans.push_back(curGroup);
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int> >v;
        vector<vector<int> >ans;
        v.resize(groupSizes.size()+1);
        for(int i=0;i<groupSizes.size();i++){
            v[groupSizes[i]].push_back(i);
            if(v[groupSizes[i]].size()==groupSizes[i]){
                ans.push_back(v[groupSizes[i]]);
                v[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};