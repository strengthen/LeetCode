__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int lo = max(grid[0][0], grid[n - 1][n - 1]),
            hi = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                hi = max(hi, grid[i][j]);
        while (lo < hi) {
            vector<vector<int>> vistied(n, vector<int>(n, 0));
            int mid = (lo + hi) / 2;
            if (dfs(grid, vistied, 0, 0, mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
private:
    bool dfs(vector<vector<int>> &grid, vector<vector<int>> &vistied, int x, int y, int t) {
        if (grid[x][y] > t)
            return false;
        vistied[x][y] = 1;
        int dirs[] = {-1, 0, 1, 0, -1};
        int n = grid.size();
        if (x == n - 1 && y == n - 1)
            return true;
        for (int i = 0; i < 4; i++) {
            int dx = x + dirs[i],
                dy = y + dirs[i + 1];
            if (dx < 0 || dy < 0 || dx >= n || dy >= n)
                continue;
            if (vistied[dx][dy])
                continue;
            if (dfs(grid, vistied, dx, dy, t))
                return true;
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 9776 kb submission
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        priority_queue<pair<int,int>> q;
        q.push({-grid[0][0], 0*n+0});
        vector<int> seen(n*n);
        vector<int> dirs{-1,0,1,0,-1};
        seen[0*n+0]=1;
        while(!q.empty())
        {
            auto node=q.top(); q.pop();
            int t = -node.first;
            int x= node.second%n;
            int y= node.second/n;
            if(x == n-1 && y== n-1) return t;
            for(int i=0; i<4; i++)
            {
                int tx= x+dirs[i];
                int ty= y+dirs[i+1];
                if(tx <0 || ty <0 || tx >= n || ty >=n) continue;
                if(seen[ty*n+tx]) continue;
                seen[ty*n+tx]=1;
                q.push({-max(t,grid[ty][tx]),ty*n+tx});        
            }
        }
       return -1;
    }
};
__________________________________________________________________________________________________
