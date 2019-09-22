__________________________________________________________________________________________________
sample 144 ms submission
class Solution {
public:
    string smallestStringWithSwaps(string str, vector<vector<int>>& pairs) {
        int sz = str.length();
        vector<int> f(sz);
        function<int(int)> find;
        find = [&](int x) {
            return f[x] = f[x]==x ? f[x] : find(f[x]);
        };
        for (int i=0; i<sz; ++i) { f[i] = i; }
        for (auto &p: pairs) {
            int f1 = find(p[0]), f2 = find(p[1]);
            f[f1] = f2;
        }
        vector<int> gid(sz);
        for (int i=0; i<sz; ++i) { gid[i] = find(i); }

        vector<string> g(sz);
        for (int i=0; i<sz; ++i) { g[gid[i]] += str[i]; }
        for (int i=0; i<sz; ++i) { sort(g[i].begin(), g[i].end()); }
        vector<int> nxt(sz, 0);
        string ans;
        for (int i=0; i<sz; ++i) { ans += g[gid[i]][nxt[gid[i]]++]; }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 264 ms submission
class Solution {
public:
    vector < set < int > > adj;
    vector < int > g, vis;
    
    void dfs(int node) {
        vis[node] = true;
        g.push_back(node);
        for(auto it = adj[node].begin();it != adj[node].end();++it) {
            int to = *it;
            if(!vis[to]) {
                dfs(to);
            }
        }
    }
    
    string smallestStringWithSwaps(string str, vector<vector<int>>& A) {
        int n = A.size();
        vis.resize(str.size() + 4);
        adj.resize(str.size() + 4);
        for(int i = 0;i < n;++i) {
            int f = A[i][0];
            int s = A[i][1];
            
            adj[f].insert(s);
            adj[s].insert(f);
        }
        
        for(int i = 0;i < str.size();++i) {
            if(!vis[i]) {
                dfs(i);
                
                string x;
                for(int j = 0;j < g.size();++j) {
                    int idx = g[j];
                    x += str[idx];
                }
                sort(x.begin(), x.end());
                sort(g.begin(), g.end());
                for(int j = 0;j < g.size();++j) {
                    int idx = g[j];
                    str[idx] = x[j];
                }
                
                g.clear();
            }
        }
        return str;
    }
};
__________________________________________________________________________________________________
