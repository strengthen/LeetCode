__________________________________________________________________________________________________
4ms
static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		int buy1 = INT_MIN, sell1 = 0;
		int buy2 = INT_MIN, sell2 = 0;

		for (auto p : prices)
		{
			buy1 = max(buy1, -p);
			sell1 = max(sell1, buy1 + p);
			buy2 = max(buy2, sell1 - p);
			sell2 = max(sell2, buy2 + p);
		}

		return sell2;
	}
};
__________________________________________________________________________________________________
9288 kb
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.empty()) return 0;
        int s1=-prices[0],s2=0,s3=INT_MIN,s4=0;
        
        for(auto &price:prices) {
            s1=max(s1,-price);
            s2=max(s2,s1+price);
            s3=max(s3,s2-price);
            s4=max(s4,s3+price);
        }
        return s4;
    }
};
__________________________________________________________________________________________________
