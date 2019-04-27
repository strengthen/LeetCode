__________________________________________________________________________________________________
sample 44 ms submission
static auto _=[](){ios::sync_with_stdio(false);cin.tie(NULL);return 0;}();
class Solution
{
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int N = prices.size();
        
        if (N == 0)
            return 0;
        
        // Profit at i-th day if we don't have stock
        int cash = 0;
        
        // Profit at i-th day if we do have a stock
        // Start with negative price[0] because
        // at day 0, we don't have any profit
        // Nor do we hold any unit of stock
        int hold = -1 * prices[0];
        
        for (int i = 1; i < N; ++i)
        {
            int prev_cash = cash;
            
            // What if we sold the unit of stock
            // Either we continue to hold no stock
            // Or we sell any stock we held on previous day
            cash = max(prev_cash, hold + prices[i] - fee);
            
            // What if we bought a unit of stock
            // Either we continue to hold stock we had previously
            // Or we buy new stock today
            // Or we sell previously held stock today, and buy it back.
            // Third option is ruled out, as it results in useless fees
            // It will be anyways get eliminated by max operation.
            hold = max(hold, prev_cash - prices[i]);
        }
        
        return cash;
    }
    
    int maxProfit_greedy(vector<int>& prices, int fee)
    {
        int result = 0;
        int N = prices.size();
        
        if (N == 0)
            return result;
        
        int minimum = prices[0];
        for (int i = 1; i < N; ++i)
        {
            if (prices[i] < minimum)
                minimum = prices[i];
            else if (prices[i] - minimum > fee)
            {
                result += prices[i] - minimum - fee;
                
                // When we book profit at a higher point
                // We might get yet another high later.
                // Need to get that delta profit as well.
                // Since minimum is going to get subtracted there,
                // The negation in front of fee cancels fee so that
                // we don't charge double fees.
                // Example: 1, 8, 9
                // First we try to sell at 8, but later we arrive at 9
                minimum = prices[i] - fee;
            }
        }
        
        return result;
    }
};
__________________________________________________________________________________________________
sample 15120 kb submission
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            cash =max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};
__________________________________________________________________________________________________
