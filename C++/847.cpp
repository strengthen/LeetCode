__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
	void dfs(bool &f,int x, int sum, vector<vector<int>>& graph, int &ans, int vis[]) {
		if (f)
			return ;
		if (sum == graph.size()-1) {
			f = 1;
			ans = sum;
			return ;
		}
		vis[x] = 1;
		for (int i = 0;i < graph[x].size();i++) {
			if (vis[graph[x][i]] == 0) {
				dfs( f,graph[x][i], sum + 1, graph, ans, vis);
				vis[graph[x][i]] = 0;
			}
		}
		ans = max(sum, ans);
	}
	int shortestPathLength(vector<vector<int>>& graph) {
		if (graph[0].size() == 0)
			return 0;
		int vis[15];
		memset(vis, 0, sizeof(vis));
		int ans = 0;
		//int d[15][15],ans[15][15];
		//memset(d, 0, sizeof(d));
		//for (int i = 0;i < graph.size();i++)
		//	for (int j = 0;j < graph[i].size();j++)
		//		d[i][graph[i][j]] = ans[i][graph[i][j]] = 1;
		//int maxn = 0;
		bool f = 0;
		for (int i = graph.size()-1;i>=0&&!f;i--) {
			memset(vis, 0, sizeof(vis));
			
			dfs(f,i, 0, graph, ans, vis);
		}

		cout << ans << -1 << endl;
		return (graph.size() - 1) * 2 - ans;
	}
};
__________________________________________________________________________________________________
sample 9052 kb submission
class Solution {
public:
    int dp[1<<12][12];
    int solve(int mask, int v, int n, vector<vector<int>> &gr, vector<vector<int>>& dis) {
        if(mask == (1<<n) - 1) {
            return 0;
        }
        if(dp[mask][v] != -1) {
            return dp[mask][v];
        }
        int ans = 1e9;
        for(int i = 0; i < n; ++i) {
            if(mask & (1<<i)) {
                continue;
            }
            ans = min(ans, solve(mask | (1<<i), i, n, gr, dis) + dis[v][i]);
        }
        return dp[mask][v] = ans;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; ++i) {
            for(auto j : graph[i]) {
                adj[i][j] = 1;
            }
            adj[i][i] = 0;
        }
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(i == k || j == k) {
                        continue;
                    }
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        int ans = 1e9;
        for(int i = 0; i < n; ++i) {
            ans = min(ans, solve(1<<i, i, n, graph, adj));
        }
        return ans;
    }
};
__________________________________________________________________________________________________
