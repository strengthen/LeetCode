__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int res = 0;
        if (timeSeries.length == 0) return res;
        int next = 0;
        for (int i : timeSeries) {
            if (i < next) {
                res -= next - i;
                
            }
next = i + duration;
                res += duration;
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 38920 kb submission
class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int res = 0;
        if(timeSeries == null || timeSeries.length == 0)
            return res;
        for(int i = 1; i < timeSeries.length; i++) {
            if(timeSeries[i]-duration > timeSeries[i-1])
                res += duration;
            else
                res += timeSeries[i]-timeSeries[i-1];
        }
        return res+duration;
    }
}
__________________________________________________________________________________________________
