__________________________________________________________________________________________________
sample 96 ms submission
struct Edge {
    Edge * nxt;
    int w;
};

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        int dist[N + 2];
        memset(dist, 0x3F, sizeof(dist));
        dist[0] = 0;
        // unordered_map<int, Edge *> adje;
        
        
        
        
        for (int i = 0; i < N; i++) {
            bool ismodified = false;
            for (auto & e: edges) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] > dist[v] + w + 1) {
                    dist[u] = dist[v] + w + 1;
                    ismodified = true;
                }
                if (dist[v] > dist[u] + w + 1) {
                    dist[v] = dist[u] + w + 1;
                    ismodified = true;
                }                
            }
            if (ismodified == false) break;
        }
        int res = 0;
        for (int i = 0; i < N; i++) if (dist[i] <= M) res++;
        // cout<<res<<endl;
        for (auto & e: edges) {
            int u = e[0], v = e[1], w = e[2];
            int tmp = (M - dist[u] > 0) ? M - dist[u] : 0;
            tmp += (M - dist[v] > 0) ? M - dist[v] : 0;
            tmp = min(tmp, w);
            res += tmp;
            // cout<<u<<" "<<v<<" "<<w<<" "<<res<<endl;
        }
        return res;
    }
};
__________________________________________________________________________________________________
× Close
sample 29200 kb submission
class cmp {
public:
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second > p2.second;
    }
};

class Solution {
private:
    int N;
    vector<vector<pair<int, int>>> graph;
    vector<int> minDis;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    
    void init(const vector<vector<int>> &edges, const int N) {
        this->N = N;
        graph.clear();
        minDis.clear();
        while (!pq.empty()) { pq.pop(); }
        vector<pair<int, int>> temp;
        graph.assign((size_t) N, temp);
        for (const vector<int> &edge : edges) {
            graph[edge[0]].push_back(make_pair(edge[1], edge[2]));
            graph[edge[1]].push_back(make_pair(edge[0], edge[2]));
        }
        minDis.assign((size_t) N, INT_MAX);
    }

public:
    int reachableNodes(vector<vector<int>> &edges, int M, int N) {
        init(edges, N);
        pq.push(make_pair(0, 0));
        minDis[0] = 0;
        while (!pq.empty()) {
            while (!pq.empty() && pq.top().second > minDis[pq.top().first]) { pq.pop(); }
            if (pq.empty()) { break; }
            pair<int, int> topItem = pq.top();
            pq.pop();
            for (const pair<int, int> &neighbor : graph[topItem.first]) {
                if (topItem.second + neighbor.second + 1 < minDis[neighbor.first]) {
                    int newNode = neighbor.first, newDis = topItem.second + neighbor.second + 1;
                    minDis[newNode] = newDis;
                    pq.push(make_pair(newNode, newDis));
                }
            }
        }
        int ans = 0;
        for (int d : minDis) { if (d <= M) { ans++; }}
        for (const vector<int> &edge : edges) {
            int leftCanGo = minDis[edge[0]] == INT_MAX ? 0 : M - minDis[edge[0]];
            int rightCanGo = minDis[edge[1]] == INT_MAX ? 0 : M - minDis[edge[1]];
            leftCanGo = leftCanGo < 0 ? 0 : leftCanGo;
            rightCanGo = rightCanGo < 0 ? 0 : rightCanGo;
            ans += (leftCanGo + rightCanGo) < edge[2] ? (leftCanGo + rightCanGo) : edge[2];
        }
        return ans;
    }
};
__________________________________________________________________________________________________
