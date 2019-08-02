__________________________________________________________________________________________________
sample 9 ms submission
class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        int len = intervals.length;
        if(len == 1) return 2;
        Arrays.sort(intervals, new Comparator<int[]>(){
            public int compare(int[] i1, int[] i2){
                if(i1[0] == i2[0])
                    return i1[1] - i2[1];
                return i1[0] - i2[0];
            }
        });
        int res = 2;
        int v1 = intervals[len - 1][0], v2 = v1 + 1;
        for(int i = len - 2; i >= 0; --i){
            if(v1 >= intervals[i][0] && v2 <= intervals[i][1])
                continue;
            if(v1 >= intervals[i][1]){
                if(v1 == intervals[i][1]){
                    res += 1;
                    v2 = v1; v1 = intervals[i][0];
                }
                else{
                    res += 2;
                    v1 = intervals[i][0]; v2 = v1 + 1;
                }
            }
            else if(v2 > intervals[i][1]){
                res += 1;
                if(v1 != intervals[i][0]){
                    v2 = v1; v1 = intervals[i][0];
                }
                else
                    v2 = v1 + 1;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 37976 kb submission
class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
      
        if (intervals.length == 0) 
            return 0;
        Arrays.sort(intervals, (a, b)-> a[1] != b[1] ? a[1] - b[1] : b[0] - a[0]);
    
        int left = intervals[0][1] - 1;
        int right = intervals[0][1];  
        int res = 2;
        for (int i = 1; i < intervals.length; i++) {
            int[] curr = intervals[i];
         
            if (curr[0] > left && curr[0] <= right) {
                res++;  // case1: have one element overlopping, +1
                left = right;
                right = curr[1];
            } else if (curr[0] > right) {
                res += 2;  //case2: have no elemnet overlapping, +2
                left = curr[1] - 1;
                right = curr[1];
            }   // case3: have two elemets overlapping, do nothing
        }
        return res;
    }
}
__________________________________________________________________________________________________
