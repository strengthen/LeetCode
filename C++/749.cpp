__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
	int dy_[4] = { -1, 0, 1, 0 };
	int dx_[4] = { 0, -1, 0, 1 };
	vector<vector<int>> visited_;
    int n_;
    int m_;
public:
	int containVirus(vector<vector<int>>& grid) {
		n_ = grid.size();
		m_ = grid[0].size();
        int res = 0;
        while (true) {
            int max_infect = 0;
            int region_i = -1, region_j = -1;
            int color = 2;
            for (int i = 0; i < n_; ++i) {
                for (int j = 0; j < m_; ++j) {
                    if (grid[i][j] != 1) continue;
                    int count = 0;
                    WillInfect(grid, i, j, count, color++);
                    if (count > max_infect) {
                        max_infect = count;
                        region_i = i, region_j = j;
                    }
                }
            }
            int walls = 0;
            if (max_infect > 0) Quarantine(grid, region_i, region_j, walls);
            if (walls == 0) break;
            for (int i = 0; i < n_; ++i) {
                for (int j = 0; j < m_; ++j) {
                    if (grid[i][j] == -2) Infect(grid, i, j);                    
                }
            }            
            for (int i = 0; i < n_; ++i) {
                for (int j = 0; j < m_; ++j) {
                    if (grid[i][j] <= -2) grid[i][j] = 1;
                    if (grid[i][j] >= 2) grid[i][j] = 0;                    
                }
            }            
            res += walls;
        }
        return res;
    }
    
    void WillInfect(vector<vector<int>>& grid, int i, int j, int& count, const int color) {
        grid[i][j] = -2;
        for (int k = 0; k < 4; ++k) {
            int ii = i + dy_[k], jj = j + dx_[k];
            if (ii < 0 || ii >= n_ || jj < 0 || jj >= m_) continue;
            if (grid[ii][jj] == 0 || (grid[ii][jj] >= 2 && grid[ii][jj] != color)) {
                grid[ii][jj] = color;
                ++count;
            }            
        }
        for (int k = 0; k < 4; ++k) {
            int ii = i + dy_[k], jj = j + dx_[k];
            if (ii < 0 || ii >= n_ || jj < 0 || jj >= m_ || grid[ii][jj] != 1) continue;
            WillInfect(grid, ii, jj, count, color);
        }
    }
    
    void Quarantine(vector<vector<int>>& grid, int i, int j, int& walls) {
        grid[i][j] = -1;
        for (int k = 0; k < 4; ++k) {
            int ii = i + dy_[k], jj = j + dx_[k];
            if (ii < 0 || ii >= n_ || jj < 0 || jj >= m_) continue;
            if (grid[ii][jj] == 0 || grid[ii][jj] >= 2) ++walls;
        }
        for (int k = 0; k < 4; ++k) {
            int ii = i + dy_[k], jj = j + dx_[k];
            if (ii < 0 || ii >= n_ || jj < 0 || jj >= m_ || grid[ii][jj] != -2) continue;
            Quarantine(grid, ii, jj, walls);
        }
    }
    
    void Infect(vector<vector<int>>& grid, int i, int j) {
        for (int k = 0; k < 4; ++k) {
            int ii = i + dy_[k], jj = j + dx_[k];
            if (ii < 0 || ii >= n_ || jj < 0 || jj >= m_) continue;
            if (grid[ii][jj] == 0 || grid[ii][jj] >= 2) grid[ii][jj] = -3;
        }
    }
};
__________________________________________________________________________________________________
sample 16096 kb submission
class Solution {
public:
    int containVirus(vector<vector<int>>& grid);
};

void dfs(vector<vector<int>>& grid, int a, int b, vector<vector<int>>& visited, unordered_set<int>& tobe, vector<int>& inside, int& wall) {
    int m = grid.size();
    int n = grid[0].size();
    static vector<vector<int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    for (auto& d: dirs) {
        int r = a + d[0];
        int c = b + d[1];
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c]) {
            continue;
        }
        if (grid[r][c] == 0 && grid[a][b] == 1) {
            tobe.insert(r * n + c);
            ++wall;
        }
        if (grid[r][c] == 1 || grid[r][c] == 2) {
            visited[r][c] = 1;
            inside.push_back(r * n + c);
            dfs(grid, r, c, visited, tobe, inside, wall);
        }
    }
    if (grid[a][b] == 1) { 
        grid[a][b] = 2;
    }
}

void find(vector<vector<int>>& grid, vector<vector<int>>& toinfect, vector<vector<int>>& already, vector<int>& walls, vector<vector<int>>& visited) {
    // color inner points to 2
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                visited[i][j] = 1;
                unordered_set<int> tobe;
                vector<int> inside;
                int wall = 0;
                dfs(grid, i, j, visited, tobe, inside, wall);
                if (!tobe.empty()) {
                    toinfect.push_back(vector<int>(tobe.begin(), tobe.end()));
                    already.push_back(inside);
                    walls.push_back(wall);
                }
            }
        }
    }
}

int infect(vector<vector<int>>& grid, vector<vector<int>>& toinfect, vector<vector<int>>& infected, vector<int>& walls) {
    // find max array, leave it color others, no tie
    int m = grid.size();
    int n = grid[0].size();
    int index = 0;
    int wall = 0;
    int ninfect = 0;
    for (int i = 0; i < toinfect.size(); ++i) {
        if (toinfect[i].size() > ninfect) {
            ninfect = toinfect[i].size();
            index = i;
            wall = walls[i];
        }
    }
    for (int i = 0; i < toinfect.size(); ++i) {
        if (i != index) {
            for (int j = 0; j < toinfect[i].size(); ++j) {
                int geo = toinfect[i][j];
                grid[geo / n][geo % n] = 1; // infect
            }
        } else {
            for (int j = 0; j < infected[i].size(); ++j) {
                int geo = infected[i][j];
                grid[geo / n][geo % n] = 3; // separated
            }
        }
    }
    return wall;
}

// boundary points - 1
// inner points - 2
// unaffected - 0
int Solution::containVirus(vector<vector<int>>& grid) {
    
    int m = grid.size();
    int n = grid[0].size();    
    int res = 0;
    while (true) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> toinfect;
        vector<vector<int>> infected;
        vector<int> walls = {};
        find(grid, toinfect, infected, walls, visited);
        if (toinfect.empty()) {
            break;
        }
        res += infect(grid, toinfect, infected, walls);

    }
    return res;
}
__________________________________________________________________________________________________
