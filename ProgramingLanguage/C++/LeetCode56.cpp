348 ms
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)return {};
        if(intervals.size() == 1)return intervals;
        vector<vector<int>> res;
        
        vector<int> cur;
        //[[1,3],[0,6],[9,10],[100,101],[4,99]]
        
        for(int i=0;i<intervals.size();i++){
            int start,last;
            start = intervals[i][0];//1,
            last = intervals[i][1];//3,
            if(start == -10000 or last == -10000){
                continue;//no
            }
            for(int j=i+1;j<intervals.size();j++){
                // [1,3][4,6] => [1,3][4,6]
                if(intervals[j][0] > last){
                    
                    continue;
                }
                //[1,3][2,6] => [1,6]
                else if (intervals[j][0] >= start and intervals[j][0] <= last and last <= intervals[j][1]){
                    last = intervals[j][1];
                    intervals[j][0] = -10000;
                    intervals[j][1] = -10000;
                    j = i;
                }
                //[1,3][-1,0] => [1,3][-1,0]
                else if(intervals[j][1] < start){
                    continue;
                }
                //[1,3][-1,2] => [-1,3]
                else if(intervals[j][0] <= start and start <= intervals[j][1] and last >= intervals[j][1]){
                    start = intervals[j][0];
                    intervals[j][0] = -10000;
                    intervals[j][1] = -10000;
                    j = i;
                }
                //[1,3][0,6] => [0,6]
                else if(intervals[j][0] <= start and last <= intervals[j][1]){
                    start = intervals[j][0];
                    last = intervals[j][1];
                    intervals[j][0] = -10000;
                    intervals[j][1] = -10000;
                    j = i;
                }
                else if(intervals[j][0] >= start and last >= intervals[j][1]){
                    intervals[j][0] = -10000;
                    intervals[j][1] = -10000;
                    j = i;
                }
            }
            cur.push_back(start);
            cur.push_back(last);
            res.push_back(cur);
            cur.clear();
        }
        return res;
    }
};