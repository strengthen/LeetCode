__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int closedIsland(vector<vector<int>>& g) {
        int m, n;
        if ((m = g.size()) <= 2)
            return 0;
        if ((n = g[0].size()) <= 2)
            return 0;
        
        for (int i = 0; i < n; i++) {
            dfs(g, 0, -1, 0,   i);
            dfs(g, 0, -1, m-1, i);
        }
        for (int i = 0; i < m; i++) {
            dfs(g, 0, -1, i, 0);
            dfs(g, 0, -1, i, n-1);
        }
        
        int c = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 0) {
                    dfs(g, 0, -2, i, j);
                    c++;
                }
            }
        }
        return c;
    }
    
    void dfs(vector<vector<int>>& g, int t, int v, int i, int j) {
        if(i >= 0 && i < g.size() && 
           j >= 0 && j < g[0].size() 
           && g[i][j] == t) {
           
            g[i][j] = v;
            dfs(g, t, v, i+1, j);
            dfs(g, t, v, i-1, j);
            dfs(g, t, v, i, j+1);
            dfs(g, t, v, i, j-1);
        }
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
int xmoves[] {-1, 1, 0, 0};
int ymoves[] {0, 0, 1, -1};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0)
            return 0;
        
        int m = grid[0].size();
        int run = 10;
        int count = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0)
                    if(dfs(grid, i, j, n, m, run+i*n + j))
                        count++;
            }
        }
        return count;
    }
    
    bool dfs(vector<vector<int>>& grid, int x, int y, int n, int m, int run) {
        grid[x][y] = run;
        for(int i=0; i<4; i++) {
            int newX = x + xmoves[i];
            int newY = y + ymoves[i];
            
            if(newX <0 || newX >=n || newY < 0 || newY >=m)
                return false;
            
            if(grid[newX][newY] != 0 && grid[newX][newY] != 1 &&  grid[newX][newY] != run)
                return false;
            
            else if(grid[newX][newY] == 0) {
                if(!dfs(grid, newX, newY, n, m, run))
                    return false;
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
