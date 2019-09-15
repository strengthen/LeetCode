__________________________________________________________________________________________________
sample 724 ms submission
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto &c: connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }   

        vector<int> dfn(n, -1), low(n, -1), f(n, -1);
        int nxt = 0;
        function<void(int, int)> tarjan = [&](int cur, int p) {
            f[cur] = p;
            dfn[cur] = low[cur] = nxt++;
            for (auto v: adj[cur]) {
                if (dfn[v] == -1) {
                    tarjan(v, cur);
                    low[cur] = min(low[cur], low[v]);
                } else if (f[cur] != v) {
                    low[cur] = min(low[cur], dfn[v]);
                }   
            }   
        };  

        tarjan(0, -1);

        vector<vector<int>> ans;
        for (int i=0; i<n; ++i) {
            int v = f[i];
            if (v>=0 && low[i]>dfn[v]) {
                ans.push_back({v, i});
            }   
        }   

        return ans;
    }   
};
__________________________________________________________________________________________________
sample 756 ms submission
class Solution {
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    T = 0;
    vt.resize(n, -1); low.resize(n);
    G.resize(n);
    for (const auto& e : connections) {
      int x = e[0], y = e[1];
      G[x].push_back(y); G[y].push_back(x);
    }
    for (int i = 0; i < n; ++ i) {
      if (vt[i] == -1) {
        dfs(i, -1);
      }
    }
    return bridge;
  }
private:
  int T;
  vector<vector<int>> G;
  vector<int> vt;
  vector<int> low;
  vector<vector<int>> bridge;
  void dfs(int x, int parent) {
    vt[x] = low[x] = T ++;
    for (int y : G[x]) {
      if (y == parent) continue;
      if (vt[y] != -1) {
        low[x] = min(low[x], vt[y]);
      } else {
        dfs(y, x);
        low[x] = min(low[x], low[y]);
        if (low[y] > vt[x]) {
          bridge.push_back({x, y});
        }
      }
    }
  }
};
__________________________________________________________________________________________________
