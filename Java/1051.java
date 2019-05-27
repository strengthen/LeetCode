__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int heightChecker(int[] heights) {
        int[] count = new int[101] ;
        for(int i : heights) {
            count[i]++;
        }
        int[] lower = new int[101] ;
        int[] heigher = new int[101] ;
        int cnt = 0 ;
        for(int i = 1 ; i < 101 ; i++) {
            if(count[i] != 0) {
                lower[i] = cnt ;
                cnt += count[i] ;
                heigher[i] = cnt - 1;
            }
        }
        int res = 0 ;
        for(int i = 0 ; i < heights.length ; i++) {
            if((i )< lower[heights[i]] || (i) > heigher[heights[i]]) {
                res++;
            }
        }
        return res ;
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int heightChecker(int[] heights) {
        int[] dup = (int[])heights.clone();
        Arrays.sort(dup);
        int res = 0;
        for (int i = 0; i < heights.length; i++) {
            if (heights[i] != dup[i]) {
                res++;
            }
        }
        return res;       
    }
}
__________________________________________________________________________________________________
