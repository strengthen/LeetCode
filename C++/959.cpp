__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int n;
    int count;
    vector<int> parent;
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        count = 4 * n * n;
        parent.resize(count);
        for (int i=0; i<count; i++) {
        parent[i] = i;
        }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                if(i > 0){
                    union_vertices(biaohao(i - 1, j, 2), biaohao(i, j, 0));
                }
                if(j > 0){
                    union_vertices(biaohao(i, j - 1, 1), biaohao(i, j, 3));
                }
                if(grid[i][j] != '/'){
                    union_vertices(biaohao(i, j, 2), biaohao(i, j, 3));
                    union_vertices(biaohao(i, j, 0), biaohao(i, j, 1));
                }
                if(grid[i][j] != '\\'){
                    union_vertices(biaohao(i, j, 0), biaohao(i, j, 3));
                    union_vertices(biaohao(i, j, 1), biaohao(i, j, 2));
                }
            }
        }
        return count;
    }

    int find_root(int x) {
        int x_root = x;
        while( parent[x_root] != x_root ) {
            x_root = parent[x_root];//一直往上找
        }
        return x_root;
}

    void union_vertices(int x, int y) {
        int x_root = find_root(x);
        int y_root = find_root(y);
        if(x_root != y_root) {
            parent[x_root] = y_root;
             count--;
        }
}
   
    int biaohao(int x, int y, int k) {
         return (x * n + y) * 4 + k; 
    }
};
__________________________________________________________________________________________________
sample 9724 kb submission
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m][2];
        memset(vis, 0, sizeof(vis));
        int q[10000][3];
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                for (int k = 0; k < 2; ++k)
                    if (!vis[i][j][k]) {
                        vis[i][j][k] = 1;
                        ++ans;
                        q[0][0] = i;
                        q[0][1] = j;
                        q[0][2] = k;
                        for (int l = 0, r = 1; l < r; ) {
                            int u = q[l][0], v = q[l][1], w = q[l][2]; l++;
                            if (grid[u][v] == ' ') vis[u][v][0] = vis[u][v][1] = 1;
                            if (grid[u][v] == ' ' || w == 0) {
                                if (u > 0 && !vis[u - 1][v][1]) {
                                    vis[u - 1][v][1] = 1;
                                    if (grid[u-1][v] == ' ') vis[u-1][v][0] = 1;
                                    q[r][0] = u - 1;
                                    q[r][1] = v;
                                    q[r++][2] = 1;
                                }
                            }
                            if (grid[u][v] == ' ' || w == 1) {
                                if (u < n - 1 && !vis[u + 1][v][0]) {
                                    vis[u + 1][v][0] = 1;
                                    if (grid[u+1][v] == ' ') vis[u+1][v][1] = 1;
                                    q[r][0] = u + 1;
                                    q[r][1] = v;
                                    q[r++][2] = 0;
                                }
                            }
                            if (grid[u][v] == ' ' || grid[u][v] == '/' && w == 0 || grid[u][v] == '\\' && w == 1) {
                                if (v > 0 && (grid[u][v - 1] == ' ' && !vis[u][v-1][0] || grid[u][v-1] == '\\' && !vis[u][v - 1][0] || grid[u][v-1] == '/' && !vis[u][v-1][1])) {
                                    q[r][0] = u;
                                    q[r][1] = v - 1;
                                    if (grid[u][v-1] == '\\') {
                                        vis[u][v-1][0] = 1; 
                                        q[r++][2] = 0;  
                                    } else if (grid[u][v-1] == '/'){
                                        vis[u][v-1][1] = 1;
                                        q[r++][2] = 1;
                                    } else {
                                        vis[u][v-1][0] = vis[u][v-1][1] = 1;
                                        q[r++][2] = 0;
                                    }
                                }
                            }
                            if (grid[u][v] == ' ' || grid[u][v] == '/' && w == 1 || grid[u][v] == '\\' && w == 0) {
                                if (v < m - 1 && (grid[u][v + 1] == ' ' && !vis[u][v+1][0] || grid[u][v+1] == '\\' && !vis[u][v+1][1] || grid[u][v+1] == '/' && !vis[u][v+1][0])) {
                                    q[r][0] = u;
                                    q[r][1] = v + 1;
                                    if (grid[u][v+1] == '/') {
                                        vis[u][v+1][0] = 1; 
                                        q[r++][2] = 0;  
                                    } else if (grid[u][v+1] == '\\'){
                                        vis[u][v+1][1] = 1;
                                        q[r++][2] = 1;
                                    } else {
                                        vis[u][v+1][0] = vis[u][v+1][1] = 1;
                                        q[r++][2] = 0;
                                    }
                                    
                                }
                            }
                        }
                    }
        return ans;
    }
};
__________________________________________________________________________________________________
