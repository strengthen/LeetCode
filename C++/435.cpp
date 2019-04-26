__________________________________________________________________________________________________
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto comp = [](const Interval& i1, const Interval& i2){ return i1.start < i2.start; };
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0, pre = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[pre].end) {
                res++;
                if (intervals[i].end < intervals[pre].end) pre = i;
            }
            else pre = i;
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
    
    int n = intervals.size();
    if(n <= 1) {return 0;}

    // Sort intervals based on earliest 'end' time - Greedy
    sort(intervals.begin(), intervals.end(), [] (Interval &a, Interval &b) {return a.end < b.end;});
    
    int finishTime = intervals[0].end;
    int len = 1;
    
    for(int i = 1; i < n; i++)
    {
        if(intervals[i].start >= finishTime) // This activity is compatible with our list.
        {
            len++;
            finishTime = intervals[i].end;
        }
    }
    
    return n - len;
    }
};
__________________________________________________________________________________________________
