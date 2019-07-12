__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if(intervals.length <= 1) return 0;
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[0]-b[0];
            }
        });
        
        int count = 0;
        int curRight = intervals[0][1];
        for(int i=1; i<intervals.length; i++) {
            if(intervals[i][0] < curRight) {
                count++;
                curRight = Math.min(curRight, intervals[i][1]);
            } else {
                curRight = intervals[i][1];
            }
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 34476 kb submission
class Solution {
    	 public class Interval {
		      int start;
		      int end;
		      Interval() { start = 0; end = 0; }
		      Interval(int s, int e) { start = s; end = e; }
		  }
    
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return 0;
        }
        
        Interval[] input = new Interval[intervals.length];
        for (int i = 0; i < intervals.length; i++) {
            input[i] = new Interval(intervals[i][0], intervals[i][1]);
        }
        return eraseOverlapIntervalsImp(input);
    }
    
        // sort by start
    /*
    public int eraseOverlapIntervalsImp(Interval[] intervals) {
        if (intervals == null || intervals.length == 0) return 0;
        int n = intervals.length;
        int[] count = new int[n];
        Arrays.sort(intervals, (Interval i1, Interval i2)->i1.start - i2.start);
        count[0] = 1;
        int max = 1;
        for (int i = 1; i < n; i++) {
            count[i] = 1;
            for (int j = 0; j < i; j++) {
                if (intervals[j].end <= intervals[i].start) {
                    count[i] = Math.max(count[i], count[j]+1);
                }
            }
        }
        return n - count[n-1];  
    }
    */
    
    // sort by end
    /*
    public int eraseOverlapIntervalsImp(Interval[] intervals) {
        if (intervals == null || intervals.length == 0) return 0;
        int n = intervals.length;
        int[] count = new int[n];
        Arrays.sort(intervals, (Interval i1, Interval i2)->i1.end - i2.end);
        count[0] = 1;
        int max = 1;
        for (int i = 1; i < n; i++) {
            count[i] = 1;
            for (int j = 0; j < i; j++) {
                if (intervals[j].end <= intervals[i].start) {
                    count[i] = Math.max(count[i], count[j]+1);
                }
                max = Math.max(max, count[i]);
            }
        }
        return n - max;
    }
    */
    
    // greedy
    public int eraseOverlapIntervalsImp(Interval[] intervals) {
        if (intervals == null || intervals.length == 0) return 0;
        int n = intervals.length;
        Arrays.sort(intervals, (Interval i1, Interval i2)->i1.start - i2.start);
        Interval pre = intervals[0];
        int result = 1;
        for (int i = 1; i < n; i++) {
            Interval cur = intervals[i];
            if (cur.end <= pre.end) { // case 2
                pre = cur;
            } else if (pre.end <= cur.start) { // case 3
                pre = cur;
                result++;
            }
        }
        return n - result;
    }
}
__________________________________________________________________________________________________
