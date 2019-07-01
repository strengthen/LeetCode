__________________________________________________________________________________________________
const int MAXN = 10010;

#define X first
#define Y second

int F[MAXN];

int father(int x)
{
    return F[x] == x ? x : F[x] = father(F[x]);
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class Solution {
public:
    using pii = pair<int, int>;
    int maximumMinimumPath(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        
        map<int, vector<pii> > v;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j)
                v[-a[i][j]].push_back(pii(i, j));
        
        auto place = [&](int x, int y)
        {
            return x*m+y;
        };
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j)
                F[place(i, j)] = place(i, j);
        
        for (auto p : v)
        {
            for (auto c : p.Y)
            {
                for (int k = 0; k < 4; ++ k)
                {
                    int x = c.X+dx[k], y = c.Y+dy[k];
                    if (0 <= x && x < n && 0 <= y && y < m && a[x][y] >= -p.X)
                    {
                        F[father(place(x, y))] = father(place(c.X, c.Y));
                    }
                }
            }
            if (father(place(0, 0)) == father(place(n-1, m-1))) return -p.X;
        }
        return -1;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    queue<pair<int, int>> que;
    bool vis[150][150];
    int dx[4]={0, -1, 0, 1};
    int dy[4]={1, 0, -1, 0};
    bool check(int n, int m, vector<vector<int>>& A, int mi){
        while(!que.empty()) que.pop();
        memset(vis, false, sizeof(vis));
        
        if (A[0][0]<mi) return false;
        que.push(make_pair(0, 0));
        vis[0][0]=true;
        
        while(!que.empty()){
            int x=que.front().first, y=que.front().second; que.pop();
            
            if (x==n-1 && y==m-1) return true;
            for (int k=0; k<4; k++){
                int tx=x+dx[k], ty=y+dy[k];
                if (0<=tx && tx<n && 0<=ty && ty<m){
                    if (vis[tx][ty]) continue;
                    if (A[tx][ty]<mi) continue;
                    que.push(make_pair(tx, ty));
                    vis[tx][ty]=true;
                }
            }
        }
        
        return false;
    }
    
    int maximumMinimumPath(vector<vector<int>>& A) {
        int n=A.size(), m=A[0].size();
        int left=0, right=1e9+5, ans=0;
        
        while(left<=right){
            int mid=(left+right)/2;
            if (check(n, m, A, mid)){
                left=mid+1;
                ans=max(ans, mid);
            }else{
                right=mid-1;
            }
        }
        
        return ans;
    }
};

__________________________________________________________________________________________________
