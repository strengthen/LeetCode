__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        if(grid.empty()) {
            return 0;
        }
        int dirs[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        int n = grid.size();
        int m = grid[0].size();
        if(k > n - 1 + m - 1) {
            return n + m - 2;
        }
        bool visited[k + 1][n][m];
        for(int i = 0; i <= k; i++) {
            for(int j = 0; j < n; j++) {
                for(int l = 0; l < m; l++) {
                    visited[i][j][l] = 0;
                }
            }
        }
        
        queue<tuple<int,int,int,int>> q;
        q.push(make_tuple(0,0,0, k));
        
        while(!q.empty()) {
            auto [i,j,l,r] = q.front();
            q.pop();
            if(visited[r][i][j]) continue;
            visited[r][i][j] = true;
            if(i == n - 1 && j == m - 1) {
                if(grid[i][j] == 0 || (grid[i][j] == 1 && r > 0)) {
                    return l;
                } else {
                    continue;
                }
            } else {
                if(grid[i][j] == 0 || (grid[i][j] == 1 && r > 0)) {
                    for(auto& d: dirs) {
                        int u = i + d[0];
                        int v = j + d[1];

                        if(u >= 0 && v >= 0 && u < n && v < m) {
                            q.push(make_tuple(u, v, l + 1, r - grid[i][j]));
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        

        int m = grid.size();
        int n = grid[0].size();
        if(k >= m+n-2) return m+n-2;
        queue<tuple<int,int,int>> q;  //x,y,r, where r is remain number of obstacles you can remove.
        q.push(make_tuple(0,0,k));
        int step = 0;
        //vector<int> x = {-1, 1, 0, 0}; // 这样慢，要尽量往右下方走。
        //vector<int> y = {0, 0, -1, 1};
        vector<int> x = {0, 1, 0, -1};
        vector<int> y = {1, 0, -1, 0};
        vector<vector<int>> seen(m, vector<int>(n, INT_MAX)); // 迄今为止从(0,0)走到(i,j)需要去除障碍的数量的最小值, 剪枝用
        seen[0][0] = 0; 
        while(!q.empty()) {
            int sz = q.size();
            //cout << "step=" << step << endl;
            while(sz--) {
                int i,j,r;
                tie(i, j, r) = q.front();
                q.pop();
                //cout << i << " " << j << " " << r << endl;
                if(i == m-1 && j == n-1) return step;
                for(int p=0; p<4; ++p) {
                    int ii = i+x[p];
                    int jj = j+y[p];
                    if(ii<0 || ii>=m || jj<0 || jj>=n) continue;
                    if(r < grid[ii][jj]) continue;
                    int newR = r-1-grid[ii][jj];
                    if(seen[ii][jj] <= k-newR) continue; //之前已经花了更少的步数并且移除更少的障碍到达了(ii,jj)
                    seen[ii][jj] = k-newR;
                    q.push(make_tuple(ii, jj, newR+1));
                }
            }
            ++step;
        }
        return -1;    
    }
};
__________________________________________________________________________________________________
