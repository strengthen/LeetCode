__________________________________________________________________________________________________
sample 4 ms submission
static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int maxProfit(int k, vector<int>& prices)
	{
		if (k == 0)
			return 0;
        
        if (k >= 2 * prices.size())
		{
			int ans = 0;

			for (int i = 1; i < prices.size(); i++)
			{
				if (prices[i] > prices[i - 1])
					ans += prices[i] - prices[i - 1];
			}

			return ans;
		}

		vector<int> m(2 * k);
		for (int i = 0; i < k; i++)
		{
			m[2 * i] = INT_MIN;
		}

		for (auto p : prices)
		{
			m[0] = max(m[0], -p);
			m[1] = max(m[1], m[0] + p);
			for (int i = 1; i < k; i++)
			{
				m[2 * i] = max(m[2 * i], m[2 * i - 1] - p);
				m[2 * i + 1] = max(m[2 * i + 1], m[2 * i] + p);
			}
		}

		return m[2 * k - 1];
	}
};
__________________________________________________________________________________________________
sample 8756 kb submission
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k < 1) return 0; 
        if(k >= (prices.size()/2)){
            int ret = 0;
            for(int i = 1;i < prices.size();i++){
                if(prices[i] > prices[i-1]){
                    ret += prices[i] - prices[i-1];
                }
            }
            return ret;
        }
     
        int buy[k] = {INT_MIN}, sell[k] = {INT_MIN};
        for(int j = 0;j < k;j++){
            buy[j] = INT_MIN;
            sell[j] = INT_MIN;
        }
        for(int i = 0;i < prices.size();i++){
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max(sell[0], buy[0] + prices[i]);
            for(int j = 1;j < k;j++){
                buy[j] = max(buy[j], sell[j-1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
                
            }
        }
        return sell[k-1];
    }
};
__________________________________________________________________________________________________
