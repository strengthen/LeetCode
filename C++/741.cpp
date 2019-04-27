__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int tbl[n][n];       
        fill( &tbl[0][0], &tbl[n-1][n-1], -1);
        
        tbl[n-1][n-1] = grid[n-1][n-1];
        
        int i, j;
        //yi = step -i, yj = step -j
        for ( int step = 2*n-3; step >=0; step--){
            for ( i = step- min( step, n-1); i <n && step -i >= 0; i++){               
                for ( j =step- min( step, n-1); j <= i; j++){
                    //ignore the unreachable grids
                    if ( grid[i][step-i] == -1|| grid[j][step-j] == -1){ 
                        tbl[i][j]= -1; 
                        continue;
                    }
                    
                    //T(step+1, i, j):T(step+1, i+1, j)
                    if ( i+1 <n) tbl[i][j] = max(tbl[i][j], tbl[i+1][j]);
                    //               :T(step+1, i, j+1)
                    if ( j+1 <n) tbl[i][j] = max(tbl[i][j], tbl[i][j+1]);
                    //               :T(step+1, i+1, j+1)
                    if ( i+1 <n && j+1 <n) tbl[i][j] = max(tbl[i][j], tbl[i+1][j+1]);
                    // ignore the blocked route
                    if ( tbl[i][j] == -1) continue;
                    tbl[i][j] += grid[i][step -i] + ( i==j? 0: grid[j][step -j]);
                }
            }
        }
        return max(tbl[0][0], 0);   
    }
};
__________________________________________________________________________________________________
sample 9616 kb submission
const int N = 60;
int _d[2][N][N];

class Solution {
public:
    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size();
        int (*d)[N] = _d[0];
        int (*e)[N] = _d[1];
        d[0][0] = a[0][0];
        for (int k = 0; k < 2 * n - 2; ++k) {
            for (int i = 0; i < n; ++i) {
                fill(e[i], e[i] + n, -(1 << 30));
            }
            for (int i = max(k - n + 1, 0); i <= k && i < n; ++i) {
                for (int j = max(k - n + 1, 0); j <= k && j < n; ++j) {
                    int u = k - i, v = k - j;
                    //cout << k << " " << i << " " << j << " " << u << " " << v << endl;
                    if (u + 1 < n && v + 1 < n && a[u + 1][i] != -1 && a[v + 1][j] != -1) {
                        int cur = a[u + 1][i] + d[i][j];
                        if (i != j) cur += a[v + 1][j];
                        e[i][j] = max(e[i][j], cur);
                    }
                    if (u + 1 < n && j + 1 < n && a[u + 1][i] != -1 && a[v][j + 1] != -1) {
                        int cur = a[u + 1][i] + d[i][j];
                        if (i != j + 1) cur += a[v][j + 1];
                        e[i][j + 1] = max(e[i][j + 1], cur);
                    }
                    if (i + 1 < n && v + 1 < n && a[u][i + 1] != -1 && a[v + 1][j] != -1) {
                        int cur = a[u][i + 1] + d[i][j];
                        if (i + 1 != j) cur += a[v + 1][j];
                        e[i + 1][j] = max(e[i + 1][j], cur);
                    }
                    if (i + 1 < n && j + 1 < n && a[u][i + 1] != -1 && a[v][j + 1] != -1) {
                        int cur = a[u][i + 1] + d[i][j];
                        if (i != j) cur += a[v][j + 1];
                        e[i + 1][j + 1] = max(e[i + 1][j + 1], cur);
                    }
                }
            }
            swap(d, e);
        }
        int ret = d[n - 1][n - 1];
        if (ret < 0) ret = 0;
        return ret;
    }
};
__________________________________________________________________________________________________
