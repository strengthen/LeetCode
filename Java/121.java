__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int maxProfit(int[] prices) {
        int res = 0;
        if (prices.length < 2) return res;
        int min = prices[0];
        for (int p: prices) {
            if (p > min) res = Math.max(res, p - min);
            if (p < min) min = p;
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 34412 kb submission
class Solution {
    public int maxProfit(int[] prices) {
        if(prices==null || prices.length<=1){
            return 0;
        }
        int min = prices[0];
        int max = 0;
        for(int i=1; i<prices.length; i++){
            if(min>prices[i]){
                min=prices[i];
            }
            if(prices[i]-min>max){
                max=prices[i]-min;
            }
        }
        
        return max;
    }
}
__________________________________________________________________________________________________
