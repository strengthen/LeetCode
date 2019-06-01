__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int maxProfit(int[] prices) {
    int sell = 0, prev_sell = 0, buy = Integer.MIN_VALUE, prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = Math.max(prev_sell - price, prev_buy);
        prev_sell = sell;
        sell = Math.max(prev_buy + price, prev_sell);
    }
    return sell;
 }
}
__________________________________________________________________________________________________
sample 35328 kb submission
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 1)
            return 0;
        int prevsell =0;
        int sell =0;
        int buy = Integer.MIN_VALUE;
        int prevbuy = Integer.MIN_VALUE;
        for (int i =0 ; i < prices.length; i ++){
          //  int temp = buy;
            prevbuy = buy;
            buy = Math.max(prevsell - prices[i], prevbuy);
           // prevbuy = temp;
            //temp = sell;
            prevsell = sell;
            sell = Math.max(prevsell, prevbuy+prices[i]);
           // prevsell = temp;
        }
        return sell;
    }
}
__________________________________________________________________________________________________
