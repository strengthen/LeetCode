__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length == 0) {
            return 0;
        }
        int buy1 = Integer.MIN_VALUE;
        int sell1 = 0;
        int buy2 = Integer.MIN_VALUE;
        int sell2 = 0;
        for(int i = 0; i < prices.length; i++) {
            buy1 = Math.max(buy1, -prices[i]);
            sell1 = Math.max(sell1, prices[i] + buy1);
            buy2 = Math.max(buy2, sell1 - prices[i]);
            sell2 = Math.max(sell2, prices[i] + buy2);
        }
        return sell2;
    }
}
__________________________________________________________________________________________________
sample 34556 kb submission
class Solution {
    public int maxProfit(int[] prices) {
        int oneBuyOneSell = 0;
        int twoBuyTwoSell = 0;
        int oneBuy = Integer.MAX_VALUE;
        int twoBuy = Integer.MAX_VALUE;

        for(int i = 0; i < prices.length; i++) {
            int p = prices[i];
            oneBuy = Math.min(oneBuy, p);
            oneBuyOneSell = Math.max(oneBuyOneSell, p - oneBuy);
            twoBuy = Math.min(twoBuy, p - oneBuyOneSell);
            twoBuyTwoSell = Math.max(twoBuyTwoSell, p - twoBuy);
        }

        return twoBuyTwoSell;
    }
}
__________________________________________________________________________________________________
