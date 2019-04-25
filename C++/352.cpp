__________________________________________________________________________________________________
sample 92 ms submission
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    vector<Interval> v;
    SummaryRanges() 
    {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        v.clear();
    }
    
    void addNum(int val) 
    {
        for(int i = 0; i < v.size(); i++)
        {
            if(val < v[i].start - 1)
            {
                v.insert(begin(v) + i, Interval(val, val));
                return;
            }
            else if(val == v[i].start - 1)
            {
                v[i].start--;
                return;
            }
            else if(val >= v[i].start && val <= v[i].end)
                return;
            else if(val == v[i].end + 1)
            {
                if(i + 1 < v.size() && v[i + 1].start == val + 1)
                {
                    int newEnd = v[i + 1].end;
                    v.erase(begin(v) + i + 1);
                    v[i].end = newEnd;
                }
                else
                    v[i].end++;
                return;
            }
        }
        v.push_back(Interval(val, val));
    }
    
    vector<Interval> getIntervals() 
    {
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<Interval> param_2 = obj->getIntervals();
 */
__________________________________________________________________________________________________
sample 21936 kb submission
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
private:
    vector<Interval> ranges;
public:
    /** Initialize your data structure here. */
    SummaryRanges() { }
    
    vector<Interval>::iterator getStart(int num) {
        vector<Interval>::iterator l;
        l = lower_bound(ranges.begin(), ranges.end(), Interval(num, num), 
                             [](Interval a, Interval b) {return a.start < b.start;});
        
        if (l != ranges.begin() && prev(l)->end >= (num-1) ) {
            l = prev(l);
        }
        
        return l;
    }
    
    void addNum(int val) {
        vector<Interval>::iterator l = getStart(val);
        
        int start = val; int end = val;
        while (l != ranges.end() && l->start <= val+1) {
            start = min(start, l->start);
            end = max(end, l->end);
            l = ranges.erase(l);
            
        }
        ranges.insert(l, Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        return ranges;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<Interval> param_2 = obj->getIntervals();
 */
__________________________________________________________________________________________________
