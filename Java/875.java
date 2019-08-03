__________________________________________________________________________________________________
sample 2 ms submission
class Solution 
{
    public int minEatingSpeed(int[] piles, int H) 
    {
        int max = 0;
        long sum = 0;
        
        for (int pile : piles)
        {
            max = Math.max(max, pile);
            sum += pile;
        }
        
        if (piles.length == H)
        {
            return max;
        }
        
        int lowerbound = (int) (sum / (long) H) + 1;
        
        while (true)
        {
            int hours = 0;
            for (int pile : piles)
            {
                hours += (pile - 1) / lowerbound + 1;
            }
            
            if (hours <= H)
            {
                return lowerbound;
            }
            
            ++lowerbound;
        }
    }
}
__________________________________________________________________________________________________
sample 40500 kb submission
class Solution {
    public int minEatingSpeed(int[] piles, int H) {
        int lo = 1;
        int hi = 0;
        for(int num : piles) {
            hi = Math.max(hi, num);
        }
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(canEatAll(piles, mid, H)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    
    private boolean canEatAll(int[] piles, int K, int H) {
        int hours = 0;
        for(int num : piles) {
            hours += num % K == 0? num / K : num / K + 1;
        }
        return hours <= H;
    }
}
__________________________________________________________________________________________________
