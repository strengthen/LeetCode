__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes=0;
        helper(grid, minutes);

        return minutes;
    }
    
    void helper(vector<vector<int>>& grid, int& minutes)
    {
        int M=grid.size();
        if(M>0)
        {
            int N=grid[0].size();
            if(N>0)
            {
                queue<pair<int,int>> q;
                //1)fill queue
                for(int i=0;i<M;i++)
                {
                    for(int j=0;j<N;j++)
                    {
                        if(grid[i][j]==2)
                        {
                            q.push({i,j});
                        }
                    }
                }
                //2)bfs
                bfs(grid,q,minutes);
                for(int i=0;i<M&&minutes!=-1;i++)
                {
                    for(int j=0;j<N&&minutes!=-1;j++)
                    {
                        if(grid[i][j]==1)
                        {
                            minutes=-1;
                        }
                    }
                }
            }
        }
    }
    
    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int& minutes)
    {
        int M=grid.size();
        int N=grid[0].size();
        vector<pair<int,int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
            int size=q.size();
            bool turned=false;
            for(int i=0;i<size;i++)
            {
                pair<int,int>& p=q.front();
                int row=p.first;
                int col=p.second;
                if(row>=0&&row<M&&col>=0&&col<N)
                {
                    if(grid[row][col]==1)
                    {
                        turned=true;
                        grid[row][col]=2;
                    }
                    for(auto d:directions)
                    {
                        int ncol=col+d.second;
                        int nrow=row+d.first;
                        if(nrow>=0&&nrow<M&&ncol>=0&&ncol<N)
                        {
                            if(grid[nrow][ncol]==1)
                            {
                                q.push({nrow,ncol});
                            }
                        }
                    }
                }
                q.pop();
            }
            if(turned)minutes++;
        }
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    
    bool isvalid(int x,int y,int n,int m,vector<vector<int>> &v,vector<vector<bool>> &visited)
    {
        if(x>=0&&x<n&&y>=0&&y<m&&v[x][y]==1&&visited[x][y]==false)
            return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int i,j;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited;
        for(i=0;i<n;i++)
        {
            vector<bool> temp;
            for(j=0;j<m;j++)
            {
                temp.push_back(false);
            }
            visited.push_back(temp);
        }
        
        if(n==1&&m==1&&grid[0][0]==1)
            return -1;
        queue<pair<pair<int,int>,int>> q;
     //   q.push(make_pair(make_pair(0,0),0));
     for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                { q.push(make_pair(make_pair(i,j),0));
                 visited[i][j]=true;
                }
               
            }
        }
        int cnt=0;
        while(!q.empty())
        {
            auto h=q.front();
            q.pop();
            cnt=max(cnt,h.second);
         //   if(h.first.first==n-1&&h.first.second==m-1)
           //     break;
            if(isvalid(h.first.first+1,h.first.second,n,m,grid,visited))
               {
                   q.push(make_pair(make_pair(h.first.first+1,h.first.second),h.second+1));
                   visited[h.first.first+1][h.first.second]=true;
               }
            if(isvalid(h.first.first-1,h.first.second,n,m,grid,visited))
               {
                   q.push(make_pair(make_pair(h.first.first-1,h.first.second),h.second+1));
                   visited[h.first.first-1][h.first.second]=true;
               }
            if(isvalid(h.first.first,h.first.second+1,n,m,grid,visited))
               {
                   q.push(make_pair(make_pair(h.first.first,h.first.second+1),h.second+1));
                   visited[h.first.first][h.first.second+1]=true;
               }
            if(isvalid(h.first.first,h.first.second-1,n,m,grid,visited))
               {
                   q.push(make_pair(make_pair(h.first.first,h.first.second-1),h.second+1));
                   visited[h.first.first][h.first.second-1]=true;
               }   
        }   
      //  if(cnt==0&&v[0][0]!=2)
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==1&&visited[i][j]==false)
                    return -1;
            }
        }
        
        return cnt;
        
    }
};
__________________________________________________________________________________________________
sample 9120 kb submission
static auto x = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    const int EMPTY = 0;
    const int FRESH = 1;
    const int ROTTEN = 2;

   public:
    using point = pair<int, int>;
    int orangesRotting(vector<vector<int>>& grid) {
        queue<point> que;
        int fresh_count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == ROTTEN) que.push({i, j});
                if (grid[i][j] == FRESH) fresh_count++;
            }
        }

        if (fresh_count == 0) return 0;

        int time_count = 0;
        que.push({-1, -1});
        while (!que.empty()) {
            point cur = que.front();
            que.pop();

            if (cur.first == -1 && cur.second == -1 && !que.empty()) {
                time_count++;
                que.push({-1, -1});
            }

            int i = cur.first;
            int j = cur.second;

            if (i > 0 && grid[i - 1][j] == FRESH) {
                que.push({i - 1, j});
                fresh_count--;
                grid[i - 1][j] = ROTTEN;
            }
            if (i < grid.size() - 1 && grid[i + 1][j] == FRESH) {
                que.push({i + 1, j});
                fresh_count--;
                grid[i + 1][j] = ROTTEN;
            }
            if (j > 0 && grid[i][j - 1] == FRESH) {
                que.push({i, j - 1});
                fresh_count--;
                grid[i][j - 1] = ROTTEN;
            }
            if (j < grid[0].size() - 1 && grid[i][j + 1] == FRESH) {
                que.push({i, j + 1});
                fresh_count--;
                grid[i][j + 1] = ROTTEN;
            }
        }

        if (fresh_count == 0)
            return time_count;
        else
            return -1;
    }
};
__________________________________________________________________________________________________
sample 9340 kb submission
static const auto s = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;    
}();

class Solution {
public:
    int m, n;
    
    bool withinBound(int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int duration = 0;
        int d[4] = {0, 1, 0, -1};
        queue<pair<pair<int, int>, int> > q;
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == 2)
                    q.push(make_pair(make_pair(i,j),0));      
        
        while(!q.empty()) {
            pair<pair<int, int>, int> p = q.front(); q.pop();
            int r = p.first.first;
            int c = p.first.second;
            int l = p.second;
            duration = max(duration, l);
            for(int i = 0; i < 4; ++i) {
                int nr = r+d[i];
                int nc = c+d[i^1];
                if(withinBound(nr, nc) && grid[nr][nc] == 1) {
                    q.push(make_pair(make_pair(nr, nc), l+1));
                    grid[nr][nc] = 2;  
                }
            }
        }
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == 1)
                    duration = -1;
            
        return duration;
    }
};