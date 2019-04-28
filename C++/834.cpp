__________________________________________________________________________________________________
sample 92 ms submission
class Solution {
    void dfs1(int root, int root_parent, vector<vector<int>> &graph,
              vector<int> &num, vector<int> &ans) {
        for (auto &son : graph[root]) {
            if (son != root_parent) {
                // 这里是先dfs子结点
                // 计算出ans[son] & num[son]
                dfs1(son, root, graph, num, ans);
                num[root] += num[son];
                // NOTE: 这里顺路要计算出ans[root]
                ans[root] += ans[son] + num[son];
            }
        }
        num[root] += 1;  // 这里的1表示把自己统计进去
    }

    void dfs2(int root, int root_parent, vector<vector<int>> &graph,
              vector<int> &num, vector<int> &ans, const int N) {
        for (auto &son : graph[root]) {
            if (son != root_parent) {
                // ans[root]already computed, 计算 ans[son]
                const int other = N - num[son];
                const int C = ans[son] + num[son];
                ans[son] += ans[root] - C + other;
                dfs2(son, root, graph, num, ans, N);
            }
        }
    }

   public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &es) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> graph(N, vector<int>());
        for (auto &e : es) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        // pickup a root.
        int root = 0;
        for (int i = 1; i < graph.size(); i++) {
            if (graph[i].size() > graph[root].size()) {
                root = i;
            }
        }

        vector<int> ans(N, 0), num(N, 0);
        dfs1(root, -1, graph, num, ans);
        dfs2(root, -1, graph, num, ans, N);
        return ans;
    }
};
__________________________________________________________________________________________________
sample 26032 kb submission
class Solution {
public:
    static const int N = 1e4 + 10;
    vector <int> G[N];
    vector <int> ans; 
    vector <int> count;
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        ans.resize(N, 0);
        count.resize(N + 1, 0);
        for (auto &x : edges) {
            G[x[0]].push_back(x[1]);
            G[x[1]].push_back(x[0]);
        }
        dfs(0, -1);
       // cout << "1234" << endl;
        dfs2(0, -1, N);
        return ans;
    }
    
    // bottom-up ans
    void dfs(int n, int p) {
        for (auto &x : G[n]) {
            if (x != p) {
             count[x] = 1;
              dfs(x, n);
              count[n] += count[x];
              ans[n] += (ans[x] + count[x]);
               // cout << x << endl;
            }
        }
    }
    
     // top-down ans
    void dfs2(int n, int p, int N) {
        for (auto &x : G[n]) {
            if (x != p) {
              ans[x] = ans[n] - count[x] + N - count[x];
              dfs2(x, n, N);
            }
        }
    }
};
__________________________________________________________________________________________________
