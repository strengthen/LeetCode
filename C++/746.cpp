__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=cost.size();
        if(n==0)
            return 0;
        if(n==1)
            return cost[0];
        if(n==2)
            return min(cost[0],cost[1]);
        int dp[n];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[n-1],dp[n-2]);
    }
};
__________________________________________________________________________________________________
sample 8584 kb submission
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i = 2; i<cost.size(); ++i)
            cost[i] += min(cost[i-2], cost[i-1]);
        return min(cost[cost.size()-1], cost[cost.size()-2]);
    }

};

static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
