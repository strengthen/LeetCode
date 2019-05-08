__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int mySqrt(int x) {
        long start = 1, end = x;
        while (start + 1 < end) {
            long mid = start + (end - start) / 2;
            if (mid * mid <= x) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (start * start <= x) {
            return (int) start;
        }
        return (int) end;
    }
}
__________________________________________________________________________________________________
sample 37652 kb submission
class Solution {
    public int mySqrt(int x) {
        
        long low = 0;
        long high = x;
        long mid = 0;
        while(low <= high) {
            mid = low + (high-low)/2;
            long midSquared = mid*mid;
            if(midSquared == x) return (int)mid;
            else if(midSquared < x) low = mid+1;
            else high = mid-1;
        }
        
        return (int)low-1;        
    }
}
__________________________________________________________________________________________________
