__________________________________________________________________________________________________
sample 74 ms submission
/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class SummaryRanges {

    /** Initialize your data structure here. */
    //List + simple binary search O(longN)
    List<Interval> intervals;
    public SummaryRanges() {
        intervals = new ArrayList();
    }
    
    public void addNum(int val) {
        // get idx to insert val, -1 if already exist in some interval
        int idx = getIndex(val);
        if (idx == -1) return;
        
        Interval value = new Interval(val, val);
        
        //check and merge left interval
        if (idx > 0) {
            Interval left = intervals.get(idx - 1);
            if (val == left.end + 1) {
                left.end = val;
                value = left;
            }
        }
        
        //check and merge right interval
        if (idx < intervals.size()) {
            Interval right = intervals.get(idx);
            if (val == right.start - 1){
                right.start = val;
                value = right;
            }
        }
        
        // check if val has merged with any adjacent intervals, 
	    // if so check if adjecent intervals needs to be merged
        if (!equal(value, new Interval(val, val))) {
            Interval left = (idx > 0) ? intervals.get(idx - 1) : null;
            Interval right = (idx < intervals.size()) ? intervals.get(idx) : null;
            if (left != null && right != null && left.end == right.start) {
                left.end = right.end;
                intervals.remove(right);
            }            
        }else {
            intervals.add(idx, value);
        }
        
    }
    
    public List<Interval> getIntervals() {     
        return intervals;
    }
    
    private int getIndex(int val) {
        if (intervals.isEmpty()) return 0;
        
        int start = 0, end = intervals.size();
        while (start < end) {
            int mid = start + (end-start) / 2;
            Interval m = intervals.get(mid);
            if (val >= m.start && val <= m.end) return -1;
            else if (val > m.end) start = mid + 1;
            else end = mid;
        }
        
        return end; // we can do "return start;" too
    }
    
    private boolean equal(Interval a, Interval b) {
        return (a.start == b.start) && (a.end == b.end);
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * List<Interval> param_2 = obj.getIntervals();
 */
__________________________________________________________________________________________________
sample 41520 kb submission
/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class SummaryRanges {

    /** Initialize your data structure here. */
    TreeSet<Interval> intervals;
    public SummaryRanges() {
        intervals = new TreeSet<>(Comparator.comparing(a->a.start));
    }
    
    public void addNum(int val) {
        Interval higher = intervals.higher(new Interval(val, 0));//least interval among all intervals greater than (val, 0)
        Interval lower = intervals.lower(new Interval(val, 0));
        
        //If higher is not null, val < higher.start and hence val cannot be on interval higher and we already have a new val
        //If lower is not null, val >lower.start and hence it is possible for val to be on interval lower, and we need to double check on it
        if (lower != null && val >= lower.start && val <= lower.end) return;
        
        // we check if the higher or lower need to be expanded if so 
        // we just remove them and add a new interval
        int start = val, end = val;
        if (higher != null && val == higher.start - 1) {
            end = higher.end;
            intervals.remove(higher);
        }
        
        if (lower != null && val == lower.end + 1) {
            start = lower.start;
            intervals.remove(lower);
        }
        
        intervals.add(new Interval(start, end));
    }
    
    public List<Interval> getIntervals() {     
       return new ArrayList(intervals);
    }    
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * List<Interval> param_2 = obj.getIntervals();
 */
__________________________________________________________________________________________________
