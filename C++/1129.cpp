__________________________________________________________________________________________________
const int INF = 1e9 + 5;

struct edge {
    int node, weight;

    edge() {}

    edge(int _node, int _weight) : node(_node), weight(_weight) {}
};

int N;
vector<vector<edge>> adj;
vector<int> dist;

void bfs_check(queue<int> &q, queue<int> &next_q, int node, int current_dist, int add) {
    assert(0 <= add && add <= 1);

    if (current_dist < dist[node]) {
        dist[node] = current_dist;
        (add == 0 ? q : next_q).push(node);
    }
}

void bfs(int source1, int source2) {
    // Two queues are needed for 0-1 BFS.
    queue<int> q, next_q;
    dist.assign(N, INF);
    bfs_check(q, next_q, source1, 0, 0);
    bfs_check(q, next_q, source2, 0, 0);
    int level = 0;

    while (!q.empty() || !next_q.empty()) {
        while (!q.empty()) {
            int top = q.front(); q.pop();

            if (level > dist[top])
                continue;

            for (edge &e : adj[top])
                bfs_check(q, next_q, e.node, dist[top] + e.weight, e.weight);
        }

        swap(q, next_q);
        level++;
    }
}


class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        N = 2 * n;
        adj.assign(N, {});

        for (vector<int> edge : red_edges) {
            int a = 2 * edge[0], b = 2 * edge[1] + 1;
            adj[a].emplace_back(b, 1);
        }

        for (vector<int> edge : blue_edges) {
            int a = 2 * edge[0] + 1, b = 2 * edge[1];
            adj[a].emplace_back(b, 1);
        }

        bfs(0, 1);
        vector<int> answer;

        for (int i = 0; i < n; i++) {
            answer.push_back(min(dist[2 * i], dist[2 * i + 1]));

            if (answer.back() >= INF)
                answer.back() = -1;
        }

        return answer;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
    vector< vector<int> > G(n),H(n);
    for(auto vs:red_edges) G[vs[0]].emplace_back(vs[1]);
    for(auto vs:blue_edges) H[vs[0]].emplace_back(vs[1]);

    using P = pair<int, int>;
    queue<P> que;
    vector<int> dp0(n,-1),dp1(n,-1);
    dp0[0]=dp1[0]=0;
    que.emplace(0,0);
    que.emplace(0,1);

    while(!que.empty()){
      int v,d;
      tie(v,d)=que.front();que.pop();
      if(d==0){
        for(int u:G[v]){
          if(~dp1[u]) continue;
          dp1[u]=dp0[v]+1;
          que.emplace(u,1);
        }
      }else{
        for(int u:H[v]){
          if(~dp0[u]) continue;
          dp0[u]=dp1[v]+1;
          que.emplace(u,0);
        }
      }
    }
    vector<int> res(n,-1);
    for(int i=0;i<n;i++){
      if(~dp0[i]){
        if(res[i]<0) res[i]=dp0[i];
        res[i]=min(res[i],dp0[i]);
      }
      if(~dp1[i]){
        if(res[i]<0) res[i]=dp1[i];
        res[i]=min(res[i],dp1[i]);
      }
    }
    return res;
  }
};
__________________________________________________________________________________________________
