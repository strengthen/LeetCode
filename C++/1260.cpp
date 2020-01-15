__________________________________________________________________________________________________
sample 44 ms submission
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int ijk = (i * n + j + k) % (m*n);
                cout << ijk << endl;
                int x = ijk / n;
                int y = ijk % n;
                res[x][y] = grid[i][j];
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 48 ms submission
static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
    vector<vector<int>> G;
    int m, n;
    
    inline int& get(int ij)
    {
        int i=ij/n, j=ij%n;
        return G[i][j];
        //auto R=div(ij, n);
        //return G[R.quot][R.rem];
    }
    
    // reverse elements in range [from, to]
    void reverse(int from, int to)
    {
        for(int L=from, R=to; L<R; L++, R--) swap(get(L), get(R));
    }
    
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        G=move(grid);
        m=G.size(); n=G[0].size();
        int mn=m*n;
        k%=mn;
        // cyclic shift to the right by k elements:
        if(k!=0)
        {
            reverse(0, mn-1);
            reverse(0, k-1);
            reverse(k, mn-1);
        }
        
        return move(G);
    }
};
__________________________________________________________________________________________________
