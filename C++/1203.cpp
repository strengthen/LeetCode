__________________________________________________________________________________________________
sample 204 ms submission
class Solution {
public:
    vector < int > itog;
    vector < vector < int > > grp;
    vector < set < int > > adjj, aaa;
    
    bool ok = true;
    void topo(int node, vector < set < int > > &adj, map < int, int > &vis, vector < int > &s) {
        vis[node] = 1;
        if(!ok) {
            return;
        }
        for(auto it = adj[node].begin();it != adj[node].end();++it) {
            int to = *it;
            if(vis[to] == 1) {
                ok = false;
                return;
            }
            if(!vis[to]) {
                topo(to, adj, vis, s);
            }
        }
        vis[node] = 2;
        s.push_back(node);
    }
    
    void order(int g_num, vector < int > &ans) {
        vector < int > x = grp[g_num];
        vector < int > ss, all_g;
        map < int, int > v;
        for(int i = 0;i < x.size();++i) {
            // cout << x[i] << " <-\n";
            if(!v[x[i]]) {
                topo(x[i], aaa, v, ss);
            }
        }
        if(!ok) {
            return;
        }
        v.clear();
        for(int i = ss.size() - 1;i > -1;--i) {
            ans.push_back(ss[i]);
        }
    }
    
    
    vector<int> sortItems(int n, int m, vector<int>& A, vector<vector<int>>& before) {
        int gcnt = m;
        grp.resize(n + m + 4);
        adjj.resize(n + m + 4);
        aaa.resize(n + 5);
        for(int i = 0;i < n;++i) {
            if(A[i] == -1) {
                A[i] = gcnt;
                ++gcnt;
            }
            grp[A[i]].push_back(i);
        }
        itog = A;
        
        for(int i = 0;i < n;++i) {
            int ga = itog[i];
            for(int j = 0;j < before[i].size();++j) {
                int b = before[i][j];
                int gb = itog[b];
                if(ga == gb) {
                    aaa[b].insert(i);
                } else {
                    adjj[gb].insert(ga);
                }
            }
        }
        map < int, int > vis;
        vector < int > s;
        for(int i = 0;i < gcnt;++i) {
            if(!vis[i]) {
                topo(i, adjj, vis, s);
            }
        }
        
        if(!ok) {
            return {};
        }
        
        vis.clear();
        vector < int > ans;
        
        for(int i = s.size() - 1;i > -1;--i) {
            order(s[i], ans);
        }
        
        if(!ok) {
            return {};
        }
        
        return ans;
    }
};

/*

8
2
[-1,-1,1,0,0,1,0,-1]
[[],[6],[5],[6],[3,6],[],[],[]]

8
2
[-1,-1,1,0,0,1,0,-1]
[[],[6],[5],[6],[3],[],[4],[]]


5
5
[2,0,-1,3,0]
[[2,1,3],[2,4],[],[],[]]
*/
__________________________________________________________________________________________________
sample 232 ms submission
class Solution {
    unordered_map<int,unordered_set<int>> gg;
    unordered_map<int,unordered_set<int>> ig;
    vector<int> result;
    vector<int> gstate;
    vector<int> istate;
    unordered_map<int,unordered_set<int>> g2i;
    vector<int> group;
    
    bool schedule_item(int i) {
        if (istate[i]==1) return false;
        if (istate[i]==2) return true;
        istate[i] = 1;
        for (int j : ig[i]) {
            if (group[i]==group[j]) {
                if (!schedule_item(j)) return false;
            }
        }
        istate[i] = 2;
        
        result.push_back(i);
        
        return true;
    }
    
    bool schedule_group(int g) {
        if (gstate[g]==1) return false;
        if (gstate[g]==2) return true;
        gstate[g] = 1;
        for (int h : gg[g])
            if (!schedule_group(h)) return false;
        gstate[g] = 2;
        
        for (int i : g2i[g])
            if (!schedule_item(i)) return false;
        
        return true;
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        this->group = group;
        for (int i=0; i<n; i++) {
            if (group[i]==-1) group[i] = m++;
            g2i[group[i]].insert(i);
        }
        for (int i=0; i<n; i++) {
            int g = group[i];
            for (int depi : beforeItems[i]) {
                ig[i].insert(depi);
                int depg = group[depi];
                if (g != depg) {
                    gg[g].insert(depg);
                }
            }
           
        }
        istate.resize(n);
        gstate.resize(m);
        for (int g=0; g<m; g++) {
            if (!schedule_group(g)) return {};
        }
        return result;
    }
};
__________________________________________________________________________________________________
