__________________________________________________________________________________________________
sample 16 ms submission
int vis[30][30][1<<6];
int keys;
int si, sj;
int n, m;
int all;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct Node {
    int state, x, y;
    Node(int x, int y, int state = 0):x(x), y(y),state(state) {}
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(vis, -1, sizeof(vis));
        char c;
        keys = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            c = grid[i][j];
            if (c == '@') {si = i; sj = j;}
            if (c >= 'a' && c <= 'f') keys++;
        }
        all = (1 << keys) - 1;
        queue<Node> q;
        q.push(Node(si, sj, 0));
        vis[si][sj][0] = 1;
        
        int stp = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto t = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    int x = dx[i] + t.x, y = dy[i] + t.y, state = t.state;

                    if (x < 0 || y < 0 || x >= n || y >= m) continue;
                    char c = grid[x][y];

                    if (c == '#') continue;
                    if (c >= 'A' && c <= 'F') {
                        int diff = c - 'A';
                        if ( ((1 << diff) & state) == 0 ) continue;
                    }
                    if (c >= 'a' && c <= 'f') {
                        int diff = c - 'a';
                        state = state | (1 << diff);
                    }

                    if (state == all) return stp + 1;

                    if (vis[x][y][state] == -1) {
                        vis[x][y][state] = 1;
                        q.push(Node(x, y, state));
                    }
                }
            }
            stp++;
        }
        
        return -1;
    }
};
__________________________________________________________________________________________________
sample 11484 kb submission

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int target=0;
        queue<pair<int,int>> q; // first: i*n+j , second: state
        vector<vector<vector<bool>>> visited(m,vector<vector<bool>>(n,vector<bool>(64,false)));
        
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '@'){
                    q.push({i*n+j,0});
                    visited[i][j][0]=true;
                }else if('a' <= grid[i][j] && grid[i][j] <= 'f'){
                    target |= (1 << (grid[i][j]-'a'));
                }
            }    
        }
        
        int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
        int level =0;
        while(!q.empty()){
            int size = q.size();
            for(int s=0;s<size;s++){
                auto p = q.front();q.pop();
                int i = p.first/n;
                int j = p.first%n;
                int cur_keys = p.second;
                if(cur_keys == target) return level;
                
                for(int k=0;k<4;k++){
                    int ni = i+dirs[k][0];
                    int nj = j+dirs[k][1];
                    if(ni<0 || ni>=m || nj<0 || nj>=n) continue;
                    char ch = grid[ni][nj];
                    if(ch == '#') continue;
                    if('A' <= ch && ch <= 'F' &&  !(cur_keys & (1<<(ch-'A'))) )
                        continue;
                    int next_keys = cur_keys; 
                    if('a' <= ch && ch <= 'f'){//要考慮可能有'.'
                        next_keys |= (1<<(ch-'a'));
                    }
                    if(visited[ni][nj][next_keys])
                        continue;
                    q.push({ni*n+nj,next_keys});
                    visited[ni][nj][next_keys]=true;
                }
            }
            level++;
        }
        return -1;
    }
};
__________________________________________________________________________________________________
