__________________________________________________________________________________________________
using vi = vector<int>;
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<vi> graph(N);
        vector<int> in_deg(N, 0);
        for (auto& ed : relations) {
            int u = ed[0] - 1;
            int v = ed[1] - 1;
            graph[u].push_back(v);
            ++in_deg[v];
        }
        
        constexpr int INF = 1e9 + 7;
        vi dp(N, -1);
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (in_deg[i] == 0) {
                q.push(i);
                dp[i] = 0;
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : graph[u]) {
                dp[v] = max(dp[v], dp[u] + 1);
                if (--in_deg[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        for (int i = 0; i < N; ++i)  {
            if (in_deg[i] != 0) {
                return -1;
            }
        }
        
        return 1 + *max_element(begin(dp), end(dp));
    }
};
__________________________________________________________________________________________________
class Solution {

private:
    
    map<int,int> depends;
    map<int,vector<int>> dependents; 
    int ans;
    int terms;
    queue<int> Q;
    
    void topo() { 
        while(!Q.empty()) {
            int x = Q.front();
            Q.pop();
            
            if(x == NULL) {
                terms++;
                if(!Q.empty()) {
                    Q.push(NULL);
                }
                continue;
            }
            
            ans++;
        
            for(int i=0;i<dependents[x].size();i++) { 
                depends[dependents[x][i]]--;
                if(depends[dependents[x][i]]==0)
                    Q.push(dependents[x][i]);
            }
        } // while
    }
    
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        for(auto relation : relations) {
            // Y depends on X
            int X = relation[0];
            int Y = relation[1];
            
            depends[Y]++;
            dependents[X].push_back(Y);
        }
        
        for(int i=1;i<=N;i++)
            if(depends[i]==0)
                Q.push(i);
        
        Q.push(NULL); // for term end
        
        ans = 0;
        terms = 0;
        topo();
        
        if(ans!=N) {
            terms = -1; // not possible
        }
        
        return terms;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
	int minimumSemesters(int N, vector<vector<int>>& relations) {
		int i, j, k, id, x, ct = 0, maxx = 1;
		vector<vector<int>> adj(N + 1);
		vector<int> pred(N + 1, 0), ans(N + 1, 1);
		for (auto p : relations) {
			adj[p[0]].push_back(p[1]); 
			pred[p[1]]++;
		}

		queue<int> q;
		for (i = 1; i <= N; i++) {
			if (pred[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			id = q.front();
			ct++;
			q.pop();

			for (auto p : adj[id]) {
				pred[p]--;
				ans[p] = max(ans[p], ans[id] + 1);
				maxx = max(maxx, ans[p]);
				if (pred[p] == 0) q.push(p);
			}
		}

		if (ct < N) return -1;
		else return maxx;
	}
};
