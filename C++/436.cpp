__________________________________________________________________________________________________
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> hash;
        vector<int> res;
        int n = intervals.size();
        for (int i = 0; i < n; ++i)
            hash[intervals[i].start] = i;
        for (auto in : intervals) {
            auto itr = hash.lower_bound(in.end);
            if (itr == hash.end()) res.push_back(-1);
            else res.push_back(itr->second);
        }
        return res;
    }
};
__________________________________________________________________________________________________
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> res (intervals.size());
        if(intervals.empty()) return res;
        
        vector<Interval> copy;
        
		//copy[i].start = intervals[i].start, yet copy[i].end = i (so we don't lose information after sorting)
        for(int i = 0; i < intervals.size(); i++)
            copy.push_back(Interval(intervals[i].start, i));
        
        sort(copy.begin(), copy.end(), myComp);
        
        for(int i = 0; i < intervals.size(); i++){
            //make a temporary Interval for lower_bound to use
            auto it = lower_bound(copy.begin(), copy.end(), Interval(intervals[i].end,0), myComp);
            res[i] = (it == copy.end()) ? -1 : copy[it-copy.begin()].end;
        }
        return res;
    }
    
    static bool myComp(Interval a, Interval b){
        return a.start < b.start;
    }
};
__________________________________________________________________________________________________
