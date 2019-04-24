__________________________________________________________________________________________________
// DFS
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        vector<bool> v(n, false);
        for (auto a : edges) {
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        if (!dfs(g, v, 0, -1)) return false;
        for (auto a : v) {
            if (!a) return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>> &g, vector<bool> &v, int cur, int pre) {
        if (v[cur]) return false;
        v[cur] = true;
        for (auto a : g[cur]) {
            if (a != pre) {
                if (!dfs(g, v, a, cur)) return false;
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
// BFS
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> g(n, unordered_set<int>());
        unordered_set<int> s{{0}};
        queue<int> q{{0}};
        for (auto a : edges) {
            g[a.first].insert(a.second);
            g[a.second].insert(a.first);
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (auto a : g[t]) {
                if (s.count(a)) return false;
                s.insert(a);
                q.push(a);
                g[a].erase(t);
            }
        }
        return s.size() == n;
    }
};
__________________________________________________________________________________________________
// Union Find
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n, -1);
        for (auto a : edges) {
            int x = find(roots, a.first), y = find(roots, a.second);
            if (x == y) return false;
            roots[x] = y;
        }
        return edges.size() == n - 1;
    }
    int find(vector<int> &roots, int i) {
        while (roots[i] != -1) i = roots[i];
        return i;
    }
};