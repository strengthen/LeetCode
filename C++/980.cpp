__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int startx, starty, endx, endy, res, zero, current;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void search (int startx, int starty, vector<vector<int>>& grid) {
        // cout << startx << " " << starty <<endl;
        if (startx == endx && starty == endy) {
            // cout << current <<endl;
            if (current == zero) {
                res += 1;   
            }
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int x = startx + dir[i][0];
            int y = starty + dir[i][1];
            if (x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]==0) {
                grid[x][y] = -1;
                current += 1;
                search(x, y, grid);
                grid[x][y] = 0;
                current -= 1;
            }
        }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        res = 0;
        zero = 1;
        current = 0;
        for (int i= 0; i<grid.size(); i++) {
            for (int j = 0; j<grid[0].size(); j++) {
                 if (grid[i][j]==0) {
                    zero += 1;
                }
                if (grid[i][j]==1) {
                    startx = i;
                    starty = j;
                }
                if (grid[i][j]==2) {
                    endx = i;
                    endy = j;
                    grid[i][j]=0;
                }
            }
        }
        // cout << zero <<endl;
        search (startx, starty, grid);
        return res;
    }
};
__________________________________________________________________________________________________
sample 8568 kb submission
class Solution {
    int co[2][4] = {{-1,1,0,0}, {0,0,-1,1}};
    int backtrack(vector<vector<int>> &grid, int total, int x, int y, int r, int c) {
        // cout << x << ", " << y << ", " << total << endl;
        if (grid[x][y] == 0) total--;
        int cache = grid[x][y];
        grid[x][y] = 3;
        if (total == 0) {
            grid[x][y] = cache;
            for (int i = 0; i < 4; i++) {
                int xx = x + co[0][i], yy = y + co[1][i];
                if (xx >= 0 && xx < r && yy >= 0 && yy < c && grid[xx][yy] == 2)
                    return 1;
            }
            return 0;
        }

        int res = 0;
        for (int i = 0; i < 4; i++) {
            int xx = x + co[0][i], yy = y + co[1][i];
            if (xx >= 0 && xx < r && yy >= 0 && yy < c && grid[xx][yy] == 0) {
                res += backtrack(grid, total, xx, yy, r, c);
            }
        }
        grid [x][y] = cache;
        return res;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int total = 0;
        pair<int, int> start;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0)
                    total++;
                else if (grid[i][j] == 1)
                    start = {i, j};
            }
        }
        return backtrack(grid, total, start.first, start.second, r, c);
    }
};
__________________________________________________________________________________________________
