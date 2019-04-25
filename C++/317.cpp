__________________________________________________________________________________________________
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int res = INT_MAX, val = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum = grid;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    res = INT_MAX;
                    vector<vector<int>> dist = grid;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        int a = q.front().first, b = q.front().second; q.pop();
                        for (int k = 0; k < dirs.size(); ++k) {
                            int x = a + dirs[k][0], y = b + dirs[k][1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == val) {
                                --grid[x][y];
                                dist[x][y] = dist[a][b] + 1;
                                sum[x][y] += dist[x][y] - 1;
                                q.push({x, y});
                                res = min(res, sum[x][y]);
                            }
                        }
                    }
                    --val;                    
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int res = INT_MAX, buildingCnt = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0)), cnt = dist;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++buildingCnt;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    int level = 1;
                    while (!q.empty()) {
                        int size = q.size();
                        for (int s = 0; s < size; ++s) {
                            int a = q.front().first, b = q.front().second; q.pop();
                            for (int k = 0; k < dirs.size(); ++k) {
                                int x = a + dirs[k][0], y = b + dirs[k][1];
                                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && !visited[x][y]) {
                                    dist[x][y] += level;
                                    ++cnt[x][y];
                                    visited[x][y] = true;
                                    q.push({x, y});
                                }
                            }
                        }
                        ++level;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && cnt[i][j] == buildingCnt) {
                    res = min(res, dist[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
__________________________________________________________________________________________________
