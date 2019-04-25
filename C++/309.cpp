__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int maxp = 0;
		if (n <= 1)
			return maxp;
		if (n <= 2)
			return maxp = max(maxp, prices[1] - prices[0]);
		vector<int> dp(n, 0);
        dp[1] = max(0, prices[1] - prices[0]);
		int diff = max(0 - prices[0], 0 - prices[1]);
		for (int i = 2; i < n; ++i)
		{
			dp[i] = max(dp[i - 1], prices[i] + diff);
			diff = max(diff, dp[i - 2] - prices[i]);
		}
		return dp[n - 1];
	}
};
__________________________________________________________________________________________________
sample 8620 kb submission
class Solution {
public:
    int maxProfit(vector<int> &p) {
        if (p.size() < 2) return 0;
        int result = 0;
        vector<int> buy(p.size(),  0);
        vector<int> sell(p.size(), 0);
        
        buy[0] = -p[0];
        
        for(int i = 1; i < p.size(); i++){
            sell[i] = max(buy[i - 1] + p[i], sell[i - 1] - p[i - 1] + p[i]);
            if(sell[i] > result) result = sell[i];
            
            if(i == 1) buy[i] = -p[1];
            else buy[i] = max(sell[i-2] - p[i], buy[i-1] + p[i-1] - p[i]);
        }
        
        return result;

    }
};

// Fast I/O
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
__________________________________________________________________________________________________
