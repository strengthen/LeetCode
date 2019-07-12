__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int arrangeCoins(int n) {
        if (n <= 1) {
            return n;
        }
        long low = 1;
        long high = n;
        long result = 0;
        while (low <= high) {
            long mid = low + (high - low) / 2;
            if ((mid * (mid + 1) / 2) < n) {
                low = mid + 1;
            } else {
                result = mid;
                high = mid - 1;
            }
        }
        if (result * (result + 1) / 2 == n) {
            return (int)result;
        } else {
            return (int)result - 1;
        }
    }
}
__________________________________________________________________________________________________
sample 32140 kb submission
class Solution {
    public int arrangeCoins(int n) {
        int i = 1;
        int rows = 0;
        while (n >= 0) {
            n-= i;
            if (n >= 0) rows++;
            i++;
        }
        
        return rows;
    }
}
__________________________________________________________________________________________________
