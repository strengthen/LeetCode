__________________________________________________________________________________________________
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        vector<char> way{'l','u','r','d'};
        queue<pair<int, int>> q;
        unordered_map<int, string> u;
        dists[ball[0]][ball[1]] = 0;
        q.push({ball[0], ball[1]});
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = t.first, y = t.second, dist = dists[x][y];
                string path = u[x * n + y];
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0 && (x != hole[0] || y != hole[1])) {
                    x += dirs[i][0]; y += dirs[i][1]; ++dist;
                }
                if (x != hole[0] || y != hole[1]) {
                    x -= dirs[i][0]; y -= dirs[i][1]; --dist;
                }
                path.push_back(way[i]);
                if (dists[x][y] > dist) {
                    dists[x][y] = dist;
                    u[x * n + y] = path;
                    if (x != hole[0] || y != hole[1]) q.push({x, y});
                } else if (dists[x][y] == dist && u[x * n + y].compare(path) > 0) {
                    u[x * n + y] = path;
                    if (x != hole[0] || y != hole[1]) q.push({x, y});
                }
            }
        }
        string res = u[hole[0] * n + hole[1]];
        return res.empty() ? "impossible" : res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    vector<char> way{'l','u','r','d'};
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
        unordered_map<int, string> u;
        dists[ball[0]][ball[1]] = 0;
        helper(maze, ball[0], ball[1], hole, dists, u);
        string res = u[hole[0] * n + hole[1]];
        return res.empty() ? "impossible" : res;
    }
    void helper(vector<vector<int>>& maze, int i, int j, vector<int>& hole, vector<vector<int>>& dists, unordered_map<int, string>& u) {
        if (i == hole[0] && j == hole[1]) return;
        int m = maze.size(), n = maze[0].size();
        for (int k = 0; k < 4; ++k) {
            int x = i, y = j, dist = dists[x][y];
            string path = u[x * n + y];
            while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0 && (x != hole[0] || y != hole[1])) {
                x += dirs[k][0]; y += dirs[k][1]; ++dist;
            }
            if (x != hole[0] || y != hole[1]) {
                x -= dirs[k][0]; y -= dirs[k][1]; --dist;
            }
            path.push_back(way[k]);
            if (dists[x][y] > dist) {
                dists[x][y] = dist;
                u[x * n + y] = path;
                helper(maze, x, y, hole, dists, u);
            } else if (dists[x][y] == dist && u[x * n + y].compare(path) > 0) {
                u[x * n + y] = path;
                helper(maze, x, y, hole, dists, u);
            }
        }
    }
};
__________________________________________________________________________________________________
