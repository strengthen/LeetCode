__________________________________________________________________________________________________
sample 48 ms submission
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int maxUp[100][100], maxDown[100][100];
        int n = grid.size(), m = grid[0].size();
        
        bool has1 = false, has0 = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) has1 = true;
                else has0 = true;
                if (has1 && has0) break;
            }
            if (has1 && has0) break;
        }
        if (!has1 || !has0) return -1;
        
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 1) maxUp[i][j] = -1e9;
                else if (i > 0) {
                    if (grid[i-1][j] == 1) maxUp[i][j] = 0;
                    else maxUp[i][j] = maxUp[i-1][j] + 1;
                }
                else
                    maxUp[i][j] = 1e9;
            }
            for (int i = n - 1; i >= 0; i--) {
                if (grid[i][j] == 1) maxUp[i][j] = -1e9;
                else if (i < n - 1) {
                    if (grid[i+1][j] == 1) maxDown[i][j] = 0;
                    else maxDown[i][j] = maxDown[i+1][j] + 1;
                }
                else
                    maxDown[i][j] = 1e9;
            }
        }
        
        /*
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                cout << i << ' ' << j << ' ' << maxUp[i][j] << ' ' << maxDown[i][j] << endl;
                */
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) continue;
                int d = min(maxUp[i][j], maxDown[i][j]);
                // cout << d << ' ';
                for (int k = 1; k <= d && j + k < m; k++) {
                    if (grid[i][j+k] != 1) {
                        d = min(d, maxUp[i][j + k] + k);
                        d = min(d, maxDown[i][j + k] + k);
                    }
                    else {
                        d = min(d, k - 1);
                        break;
                    }
                }
                for (int k = 1; k <= d && j - k >= 0; k++) {
                    if (grid[i][j - k] != 1) {
                        d = min(d, maxUp[i][j - k] + k);
                        d = min(d, maxDown[i][j - k] + k);
                    }
                    else {
                        d = min(d, k - 1);
                        break;
                    }
                }
                // cout << i << ' ' << j << ' ' << d << endl;
                ans = max(ans, d);
            }
        }
        return ans + 1;
    }
};
__________________________________________________________________________________________________
sample 52 ms submission
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j])
                    q.emplace(i, j);

        if (n * m == q.size() || 0 == q.size())
            return -1;
        
        int ds[4][2] = {0,1,0,-1,1,0,-1,0};
        for (int k = 1; ; k++) {
            int N = q.size();
            for (int i = 0; i < N; i++) {
                auto [u, v] = q.front();
                q.pop();
                for (auto [du, dv] : ds) {
                    int nu = u + du, nv = v + dv;
                    if (nu < 0 || nu >= n || nv < 0 || nv >= m || grid[nu][nv])
                        continue;
                    grid[nu][nv] = k;
                    q.emplace(nu, nv);
                }
            }
            if (q.empty()) return k - 1;
        }
    }
};
__________________________________________________________________________________________________
