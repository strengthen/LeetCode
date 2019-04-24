__________________________________________________________________________________________________
122ms
int optimization = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        if (n == 0) return ans;
        int peak = prices[0], valley = prices[0];
        
        for (int i = 0; i < n - 1; ++i) {
            while (i < n - 1 && prices[i] >= prices[i + 1]) ++i;
            valley = prices[i];
            while (i < n - 1 && prices[i] <= prices[i + 1]) ++i;
            peak = prices[i];
            ans += peak - valley;
        }
        
        return ans;
    }
};
__________________________________________________________________________________________________
9164 kb
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)return 0;
        int res = 0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i] < prices[i+1])res += prices[i+1]-prices[i];
        }
        return res;
    }
};
__________________________________________________________________________________________________
