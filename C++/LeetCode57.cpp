__________________________________________________________________________________________________
28ms
class Solution {
public:
     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int index = 0;
        while(index < intervals.size() && intervals[index][1] < newInterval[0]){
            ans.push_back({intervals[index][0], intervals[index++][1]});
        }
        while(index < intervals.size() && intervals[index][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        ans.push_back({newInterval[0], newInterval[1]});
        while(index < intervals.size()){
            ans.push_back({intervals[index][0], intervals[index++][1]});
        }
        return ans;
    }
};