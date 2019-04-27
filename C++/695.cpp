__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int x, int y) {
        int count = 1;
        grid[x][y] = 0;
        for (int i = 0; i < 4; ++i) {
            int nex = x + dir[i][0];
            int ney = y + dir[i][1];
            if (nex >= 0 && nex < grid.size() && ney >= 0 && ney < grid[0].size() && grid[nex][ney]) {
                count += dfs(grid, nex, ney);
            }
        }
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    result = std::max(result, dfs(grid, i, j));
                }
            }
        }
        return result;
    }
};

static int ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
sample 10412 kb submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int res = 0;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 1) {
                    res = std::max(res, flood(grid, r, c));
                }
            }
        }
        return res;
    }
    
private:
    int flood(std::vector<std::vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size()) return 0;
        if (c < 0 || c >= grid[0].size()) return 0;
        
        int res = 0;
        if (grid[r][c] == 1) {
            grid[r][c] = 0;
            ++res;
            res += flood(grid, r - 1, c);
            res += flood(grid, r + 1, c);
            res += flood(grid, r, c - 1);
            res += flood(grid, r, c + 1);
        }
        return res;
    }
};
__________________________________________________________________________________________________
