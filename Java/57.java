__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        // if (intervals == null) return new int[1][2] (newInterval);
        int n = intervals.length;        
        
        List<int[]> res = new ArrayList<>();
        int i = 0;
        for(; i<n; ++i){
            if(intervals[i][1] >= newInterval[0]) break;
            res.add(intervals[i]);
        }
        
        for(; i<n && intervals[i][0] <= newInterval[1]; ++i){
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
        }
        res.add(newInterval);
        for(; i<n; ++i){
            res.add(intervals[i]);
        }
        
        int[][] result = new int[res.size()][2];
        for(i = 0; i<res.size(); ++i){
            result[i] = res.get(i);
        }
        return result;
        
    }
}
__________________________________________________________________________________________________
sample 36136 kb submission
/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        
       List<Interval> result = new ArrayList<>();
       int i = 0;
       int start = newInterval.start;
       int end = newInterval.end;
    

        while (i < intervals.size() && intervals.get(i).end < start) {
            result.add(intervals.get(i++));
        }

        while (i < intervals.size() && intervals.get(i).start <= end) {
            start = Math.min(start, intervals.get(i).start);
            end = Math.max(end, intervals.get(i).end);
            i++;
        }
        result.add(new Interval(start,end)); 

        while (i < intervals.size()) result.add(intervals.get(i++)); 

        return result;
    }
}
__________________________________________________________________________________________________
