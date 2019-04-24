__________________________________________________________________________________________________
4ms
static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    if(prices.size() == 0)
        return 0;
    int res = 0;
    int curMin = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        if( prices[i] - curMin >= res){
            res = prices[i] - curMin;
        }else if(prices[i] <= curMin){
            curMin = prices[i];
        }
    }
    return res;
}
};
__________________________________________________________________________________________________
9248 kb
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if(prices.size() == 0 || prices.size() == 1)
            return ans;
        int imin = 0;
        for(int i=0; i<prices.size()-1; i++){
            if(prices[i+1]>prices[i]){
                imin = i;
                break;
            }
        }
        for(int i=imin; i<prices.size()-1; i++){
            int max = prices[i];
            for(int j = i+1; j<prices.size(); j++)
                    max = prices[j] > max ? prices[j] : max;
            ans = ans > (max-prices[i]) ? ans : (max-prices[i]);
        }
        return ans;
    }
};
__________________________________________________________________________________________________
