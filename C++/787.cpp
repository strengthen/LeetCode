__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        g_ = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) g_[i][i] = 0;
        for (auto& f : flights) g_[f[0]][f[1]] = f[2];
        
        vector<int> mincost(n, INT_MAX);
        queue<pair<int, int>> q;  // node : cost
        
        K = K + 1; // to level
        q.push({src, 0});
        mincost[src] = 0;
        
        while (!q.empty() && K) {
            int size = q.size();
            
            for (int i = 0; i < size; ++i) {
                auto p = q.front(); q.pop();
                int now = p.first;
                int cost = p.second;
                for (int next = 0; next < n; ++next) {
                    if (g_[now][next] != INT_MAX && now != next) {
                        int cost_next = cost + g_[now][next];
                        if (cost_next >= mincost[next] || cost_next > mincost[dst]) continue;
                        q.push({next, cost_next});
                        mincost[next] = cost_next;
                    }
                }
            }
            --K;
        }
        return mincost[dst] == INT_MAX ? -1 : mincost[dst];
    }
    
    vector<vector<int>> g_;
};
__________________________________________________________________________________________________
sample 11156 kb submission
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dis(n,1e8);
        dis[src]=0;
        for(int i=0;i<=K;i++){
            vector<int> x(dis);
            for(auto& j:flights)
                x[j[1]]=min(x[j[1]],dis[j[0]]+j[2]);
            dis=x;
        }
        return dis[dst]==1e8 ? -1 : dis[dst];
    }
};
__________________________________________________________________________________________________
