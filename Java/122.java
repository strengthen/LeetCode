__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }

        int res = 0;
        for (int i = 0; i < prices.length; i++) {
            if (i == 0) {
                continue;
            }
            int incr = prices[i] - prices[i - 1];
            if (incr > 0) {
                res += incr;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 34476 kb submission
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length==0||prices==null)return 0;
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.length - 1) {
            while (i < prices.length - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.length - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
}
__________________________________________________________________________________________________
