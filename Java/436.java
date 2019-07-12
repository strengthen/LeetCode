__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    
    public int[] findRightInterval(int[][] intervals) {
        int min = intervals[0][0], max = intervals[0][1];
        
        for (int[] i : intervals) {
            min = Math.min(min, i[0]);
            max = Math.max(max, i[1]);
        }
        
        int[] buckets = new int[max - min + 1];
        
        Arrays.fill(buckets, -1);
        for (int i = 0; i < intervals.length; i++) {
            buckets[intervals[i][0] - min] = i; 
        }
        
        for (int i = buckets.length - 2; i >= 0; i--) {
            if (buckets[i] == -1) buckets[i] = buckets[i + 1];
        }
        
        int[] res = new int[intervals.length];
        
        for (int i = 0; i < intervals.length; i++) {
            res[i] = buckets[intervals[i][1] - min];
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 42212 kb submission
class Solution {
    private int[][] startArray = null;
    
    public int[] findRightInterval(int[][] intervals) {
        // check param
        if (intervals == null || intervals.length == 0) {
            return new int[0];
        }
        
        // initialization
        startArray = new int[intervals.length][2];
        for (int i = 0; i < intervals.length; i++) {
            startArray[i][0] = intervals[i][0];
            startArray[i][1] = i;
        }
        
        // sort by start point
        Arrays.sort(startArray, (int[] a, int[] b) -> {
            if (a[0] == b[0]) {
                return 0;
            }
            
            if (a[0] > b[0]) {
                return 1;
            }
            
            return -1;
        });
        
        int[] result = new int[intervals.length];
        
        for (int i = 0; i < intervals.length; i++) {
            int endPoint = intervals[i][1];
            int index = findIndex(endPoint);
            result[i] = index;
        }
        
        return result;
    }
    
    private int findIndex(int endPoint) {
        return bs(0, startArray.length-1, endPoint);
    }
    
    private int bs(int low, int high, int target) {
        if (low == high) {
            return startArray[low][0] >= target ? startArray[low][1] : -1;
        }
        
        int mid = low + ((high - low) >> 1);
        
        if (startArray[mid][0] == target) {
            return startArray[mid][1];
        }
        
        if (startArray[mid][0] > target) {
            return bs(low, mid, target);
        } else {
            return bs(mid+1, high, target);
        }
    }
}
__________________________________________________________________________________________________
