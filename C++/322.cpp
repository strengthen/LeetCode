__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int res = INT_MAX, n = coins.size();
        sort(coins.begin(), coins.end());
        helper(coins, n - 1, amount, 0, res);
        return (res == INT_MAX) ? -1 : res;
    }
    
    void helper(vector<int>& coins, int start, int target, int cur, int& res) {
        if (start < 0) return;
        if (target % coins[start] == 0) {
            res = min(res, cur + target / coins[start]);
            return;
        }
        
        for (int i = target / coins[start]; i >= 0; --i) {
            if (cur + i >= res - 1) break;
            helper(coins, start - 1, target - i * coins[start], cur + i, res);
        }
    }
};
__________________________________________________________________________________________________
sample 8476 kb submission
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        unsigned int sum[amount + 1];
        fill(sum, sum + amount + 1, INT_MAX);
        sum[0] = 0;
        for (int coin : coins)
            for (int i = coin; i <= amount; ++i)
                sum[i] = min(sum[i], sum[i - coin] + 1);
        return sum[amount] < INT_MAX ? sum[amount] : -1;
    }
};

auto static _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return nullptr;
}();
__________________________________________________________________________________________________
