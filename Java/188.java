__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int maxProfit(int k, int[] prices) {
        if (k < 1) {
            return 0;
        }
        if (k >= prices.length / 2) {
            int profit = 0;
            for (int i = 1; i < prices.length; i++) {
                if (prices[i - 1] < prices[i]) {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }
        int[] buys = new int[k + 1], sells = new int[k + 1];
        Arrays.fill(buys, Integer.MIN_VALUE);
        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                buys[i] = Math.max(buys[i], sells[i - 1] - price);
                sells[i] = Math.max(sells[i], buys[i] + price);
            }
        }
        return sells[k];
    }
}
__________________________________________________________________________________________________
sample 34296 kb submission
class Solution {
    public int maxProfit(int k, int[] prices) {
        int length = prices.length;
        if (k == 0 || length == 0) {
            return 0;
        }
        
        if (k >= length / 2) {
            int maxProfit = 0;
            for (int i = 0; i < length - 1; i++) {
                if (prices[i] < prices[i + 1]) {
                    maxProfit += prices[i + 1] - prices[i];
                }
            }
            return maxProfit;
        }
        
        int[] kSums = new int[k * 2];
        for (int i = 0; i < 2 * k; i += 2) {
            kSums[i] = Integer.MIN_VALUE;
        }
        
        for (int i = 0; i < length; i++) {
            for (int j = 0, sign = -1; j < 2 * k && j <= i; j++, sign *= -1) {
                kSums[j] = Math.max(kSums[j], sign * prices[i] + (j == 0 ? 0 : kSums[j - 1]));
            }
        }
        
        return kSums[2 * k - 1];
    }
}
__________________________________________________________________________________________________
