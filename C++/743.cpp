__________________________________________________________________________________________________
sample 60 ms submission
static auto _=[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
const int INF=0x3f3f3f3f;
class Solution {
public:
    static const int MAXN = 3000;
    int head[MAXN], vis[MAXN],dis[MAXN],k,cnt;
    void init() {
	    memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(dis,INF,sizeof(dis));
        k = 0;
        cnt = 0;
    }
    struct Edge {
	    int from;
	    int to;
        int w;
	    int next;
    } edge[MAXN*2];
    void add(int from,int to,int w) {
	    edge[cnt].from = from;
	    edge[cnt].to = to;
        edge[cnt].w = w;
	    edge[cnt].next = head[from];
	    head[from] = cnt++;
    }
    struct Node
    {
        int pos,time;
        bool operator < (const Node &a)const{
            return time > a.time;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        init();
        for(int i = 0;i < times.size();++i)
        {
            add(times[i][0],times[i][1],times[i][2]);
        }
        priority_queue<Node> q;
        Node p;
        p.time = 0;p.pos = K;dis[K] = 0;q.push(p);
        while(!q.empty())
        {
            p = q.top();q.pop();
            if(vis[p.pos])
                continue;
            vis[p.pos] = true;
            k = head[p.pos];
            while(k!=-1)
            {
                if(dis[edge[k].to]>dis[edge[k].from]+edge[k].w)
                {
                    dis[edge[k].to] = dis[edge[k].from]+edge[k].w;
                    if(!vis[edge[k].to])
                    {
                        p.time = dis[edge[k].to];
                        p.pos = edge[k].to;
                        q.push(p);
                    }
                }
                 k = edge[k].next;
            }
        }
        int ans;
        return (ans=*max_element(dis+1,dis+N+1))==INF?-1:ans;
    }
};
__________________________________________________________________________________________________
sample 24240 kb submission
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int w[101][101];
        bool nodes[101], visit[101];
        int dist[101];
        for (int i = 0; i < 101; ++ i)
        {
            dist[i] = -1;
            visit[i] = true;
        }
        memset(nodes, false, sizeof nodes);
        memset(w, -1, sizeof w);
        for (int i = 0; i < times.size(); ++ i)
        {
            w[times[i][0]][times[i][1]] = times[i][2];
            //w[times[i][1]][times[i][0]] = times[i][2];
            nodes[times[i][1]] = true;
            nodes[times[i][0]] = true;
                           
            visit[times[i][1]] = false;
            visit[times[i][0]] = false;
        }
        
        if (!nodes[K]) return -1;
        
        dist[K] = 0;
        //visit[k] = true;
        for (int i = 1; i <= N; ++ i)
        {
            int select_index = 0;
            if (!findminnode(dist, visit, N, select_index)) 
            {
                break;
            }
            for (int j = 1; j <= N; ++ j)
            {
                if (w[select_index][j] == -1 || visit[j] == true)
                    continue;
                if (dist[j] == -1)
                    dist[j] = dist[select_index] + w[select_index][j];
                else if (dist[j] > dist[select_index] + w[select_index][j])
                    dist[j] = dist[select_index] + w[select_index][j];
            }
            visit[select_index] = true;
        }
        
        int result = 0;
        for (int i = 1; i <= N; ++ i)
        {
            if (nodes[i] == false) return -1;
            if (dist[i] == -1) return  -1;
            if (dist[i] > result)
                result = dist[i];
        }
        return result;
    }
    
private:
    bool findminnode(int *p, bool *visit, int n, int& s)
    {
        int len = 1000000, choose = -1;
        for (int i = 1; i <= n; ++ i)
        {
            if (visit[i] == true)
                continue;
            if (p[i] != -1 && p[i] < len)
            {
                choose = i;
                len = p[i];
            }
        }
        if (choose == -1)
            return false;
        s = choose;
        return true;
    }
};
__________________________________________________________________________________________________
