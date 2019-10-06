__________________________________________________________________________________________________
sample 40 ms submission
class Solution {
    vector<vector<int>> grid;
    int g = 0;
    int gmax = 0;
    void backtrack(int i, int j) {
        int x = grid[i][j];
        grid[i][j] = 0;
        g+=x;
        gmax = max(gmax,g);
        
        if (i>0 && grid[i-1][j]) backtrack(i-1,j);
        if (j>0 && grid[i][j-1]) backtrack(i,j-1);
        if (i<grid.size()-1 && grid[i+1][j]) backtrack(i+1,j);
        if (j<grid[0].size()-1 && grid[i][j+1]) backtrack(i,j+1);
        
        g-=x;
        grid[i][j] = x;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        this->grid = grid;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j]) backtrack(i,j);
            }
        }
        return gmax;
    }
};
__________________________________________________________________________________________________
sample 48 ms submission
class Solution {
private:
    int global_max, w, h;
public:
    int getMaxFrom(vector<vector<int>>& grid, int i, int j){
        static int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int curr_grid = grid[i][j];
        grid[i][j] = 0;
        int curr_max = 0;
        for(int k = 0; k < 4; k++){
            int ii = i + dir[k][0];
            int jj = j + dir[k][1];
            if(ii >= 0 && ii < w && jj >= 0 && jj < h && grid[ii][jj] != 0){
                curr_max = max(curr_max, getMaxFrom(grid, ii, jj));
            }
        }
        grid[i][j] = curr_grid;
        return curr_max + curr_grid;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        global_max = 0;
        w = grid.size();
        h = grid[0].size();
        for(int i = 0 ; i < w; i++){
            for(int j = 0; j < h; j++){
                if(grid[i][j] != 0){
                    global_max = max(global_max, getMaxFrom(grid, i, j));
                }
            }
        }
        return global_max;
    }
};
__________________________________________________________________________________________________
sample 60 ms submission
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
    
private:
    int dfs(vector<vector<int>> & grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) return 0;
        int val = grid[r][c];
        grid[r][c] = 0;
        int ans = 0;
        int dirs[] = {0, 1, 0, -1, 0};
        for(int k = 0; k < 4; ++k) {
            int nr = r + dirs[k];
            int nc = c + dirs[k + 1];
            ans = max(dfs(grid, nr, nc), ans);
        }
        grid[r][c] = val;
        return ans + val;
    }
};
