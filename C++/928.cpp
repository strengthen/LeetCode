__________________________________________________________________________________________________
sample 100 ms submission
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = (int) graph.size();
        vector<bool> is_initial(n, false);
        for (auto e : initial) is_initial[e] = true;
        vector<bool> visited(n, false);
        int connected_component_color, connected_component_size;
        vector<int> count(n, 0);
        function<void(int)> dfs;
        dfs = [&](int cur)
        {
            if (is_initial[cur])
            {
                int &cc_color = connected_component_color;
                if (cc_color == -1) cc_color = cur;
                else if (cc_color != cur) cc_color = -2;
                return;
            }
            if (visited[cur]) return;
            visited[cur] = true;
            ++connected_component_size;
            for (int i = 0; i < n; ++i)
                if (graph[cur][i])
                    dfs(i);
        };
        for (int i = 0; i < n; ++i)
            if (!is_initial[i] && !visited[i])
            {
                connected_component_size = 0;
                connected_component_color = -1;
                dfs(i);
                if (connected_component_color >= 0)
                    count[connected_component_color] += connected_component_size;
            }
      
        int ans = initial.front();
        for (auto e : initial)
            if (count[e] > count[ans] || (count[e] == count[ans] && e < ans))
                ans = e;
        return ans;
    }
};
__________________________________________________________________________________________________
sample 21192 kb submission
struct UF {
    vector<short> v;
    short n;
    UF(size_t _n) : v(_n), n(_n) {
        iota(v.begin(), v.end(), 0);
    }
    short find(short i) {
        while (i != v[i])
            i = v[i];
        return i;
    }
    void join(short i, short j) {
        auto p = find(i), q = find(j);
        if (p != q) {
            v[find(j)] = find(i);
            --n;
        }
    }
};
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        auto mx = -1, mn = -1;
        for (auto x : initial) {
            UF u(n);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < i; ++j)
                    if (i != x && j != x && graph[j][i]) u.join(i, j);
            unordered_set<int> m;
            for (auto _x : initial) if (x != _x) m.insert(u.find(_x));
            int _mn = 0;
            for (int i = 0; i < n; ++i) {
                if (i == x) continue;
                _mn += m.count(u.find(i));
            }
            // cout << "x : " << x << ", n: " << _mn << "\n";
            if (mx == -1) {
                mx = x;
                mn = _mn;
            } else if (_mn < mn || (_mn == mn && x < mx)) {
                mx = x;
                mn = _mn;
            }
        }
        return mx;
    }
};
__________________________________________________________________________________________________
