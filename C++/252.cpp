__________________________________________________________________________________________________
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        for (int i = 0; i < intervals.size(); ++i) {
            for (int j = i + 1; j < intervals.size(); ++j) {
                if ((intervals[i].start >= intervals[j].start && intervals[i].start < intervals[j].end) || (intervals[j].start >= intervals[i].start && intervals[j].start < intervals[i].end)) return false;
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){return a.start < b.start;});
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
