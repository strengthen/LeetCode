__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<string> res;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    set<string> s;
                    helper(grid, i, j, i, j, visited, s);
                    string t = "";
                    for (auto str : s) t += str + "_";
                    res.insert(t);
                }
            }
        }
        return res.size();
    }
    void helper(vector<vector<int>>& grid, int x0, int y0, int i, int j, vector<vector<bool>>& visited, set<string>& s) {
        int m = grid.size(), n = grid[0].size();
        visited[i][j] = true;
        for (auto dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visited[x][y]) continue;
            string str = to_string(x - x0) + "_" + to_string(y - y0);
            s.insert(str);
            helper(grid, x0, y0, x, y, visited, s);
        }
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int, int>>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                vector<pair<int, int>> v;
                helper(grid, i, j, i, j, v);
                res.insert(v);
            }
        }
        return res.size();
    }
    void helper(vector<vector<int>>& grid, int x0, int y0, int i, int j, vector<pair<int, int>>& v) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) return;
        grid[i][j] *= -1;
        v.push_back({i - x0, j - y0});
        for (auto dir : dirs) {
            helper(grid, x0, y0, i + dir[0], j + dir[1], v);
        }
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int, int>>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                vector<pair<int, int>> v;
                queue<pair<int, int>> q{{{i, j}}};
                grid[i][j] *= -1;
                while (!q.empty()) {
                    auto t = q.front(); q.pop();
                    for (auto dir : dirs) {
                        int x = t.first + dir[0], y = t.second + dir[1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] <= 0) continue;
                        q.push({x, y});
                        grid[x][y] *= -1;
                        v.push_back({x - i, y - j});
                    }
                }
                res.insert(v);
            }
        }
        return res.size();
    }
};