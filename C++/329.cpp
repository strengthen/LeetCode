__________________________________________________________________________________________________
sample 28 ms submission
class Solution {
public:
    int R, C;
    vector <vector <int> > grid;
    vector <vector <int> > memo;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};
    
    int dfs (int x, int y) {
        if (memo[x][y] != -1) return memo[x][y];
        int ret = 0;
        for (int h = 0; h < 4; h++) {
            int X = x + dx[h], Y = y + dy[h];
            if (X < 0 || X >= R || Y < 0 || Y >= C) continue;
            if (grid[X][Y] <= grid[x][y]) continue;
            ret = max(ret, dfs(X, Y));
        }
        return memo[x][y] = ret + 1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        grid = matrix;
        R = grid.size();
        C = 0; if (R) C = grid[0].size();
        memo.assign (R, vector <int> (C, -1));

        int ret = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ret = max(ret, dfs(i, j));
        
        return ret;
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
sample 12516 kb submission
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())return 0;
        int ans=0;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
            {
                ans=max(ans,dfs(i,j,matrix,dp));
            }
        return ans;
    }
    
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    int dfs(int x,int y,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(dp[x][y]!=-1)return dp[x][y];
        int ans=1;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&nx<matrix.size()&&ny>=0&&ny<matrix[0].size()&&matrix[x][y]<matrix[nx][ny])
            {
                ans=max(ans,1+dfs(nx,ny,matrix,dp));
            }
        }
        return dp[x][y]=ans;
    }
};
__________________________________________________________________________________________________
