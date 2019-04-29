__________________________________________________________________________________________________
sample 48 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool visited[50][50];
    int connect[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    void DFS(vector <vector <int>>& grid, int r, int c, int target)
    {
        visited[r][c] = true;
        for(int i = 0; i < 4; i++)
        {
            int next_r = r + connect[i][0], next_c = c + connect[i][1];
            if(next_r != grid.size() && next_r != -1 && next_c != grid[0].size() && next_c != -1 && grid[next_r][next_c] == target && !visited[next_r][next_c])
                DFS(grid, next_r, next_c, target);
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        memset(visited, 0, 50 * 50 * sizeof(bool));
        DFS(grid, r0, c0, grid[r0][c0]);
        for(int r = 0; r < grid.size(); r++)
        {
            for(int c = 0; c < grid[0].size(); c++)
            {
                if(visited[r][c])
                {
                    if(r == 0 || r == grid.size() - 1 || c == 0 || c == grid[0].size() - 1)
                        grid[r][c] = color;
                    for(int i = 0; i < 4; i++)
                    {
                        int next_r = r + connect[i][0], next_c = c + connect[i][1];
                        if(next_r != grid.size() && next_r != -1 && next_c != grid[0].size() && next_c != -1 && !visited[next_r][next_c])
                            grid[r][c] = color;
                    }
                }
            }
        }
        return grid;
    }
};
__________________________________________________________________________________________________
sample 52 ms submission
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        dfs(grid,r0,c0,grid[r0][c0]);
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                grid[i][j]=(grid[i][j]<0?color:grid[i][j]);
        return grid;
    }
    void dfs(vector<vector<int> > &g,int r,int c,int cl){
        if(r>=g.size()||r<0||c>=g[0].size()||c<0||g[r][c]!=cl)
            return ;
        g[r][c]=-cl;
        dfs(g,r-1,c,cl);
        dfs(g,r+1,c,cl);
        dfs(g,r,c-1,cl);
        dfs(g,r,c+1,cl);
        if(r>0&&r<g.size()-1&&c>0&&c<g[0].size()-1&&abs(g[r-1][c])==cl&&abs(g[r][c-1])==cl&&abs(g[r+1][c])==cl&&abs(g[r][c+1])==cl)
            g[r][c]=cl;
    }
};
__________________________________________________________________________________________________
sample 56 ms submission
class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && j<m && i<n;
    }
    bool isCorner(int i,int j,int m,int n){
        return i==0 || j==0 || j==m-1 || i==n-1;
    }
    bool isDiff(int r,int c, vector<vector<int>>& grid)
    {
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        for(int i=0;i<4;++i){
            int r1=r+dx[i];
                int c1=c+dy[i];
                if(isValid(r1,c1,grid[0].size(),grid.size())
                   && grid[r][c]!=grid[r1][c1]){
                    return true;
                }
        }
        return false;
    }
    void dfs(int r,int c,vector<vector<int>>& grid, vector<vector<bool>>& visited,int color){
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        
        for(int i=0;i<4;++i){
                int r1=r+dx[i];
                int c1=c+dy[i];
                if(isValid(r1,c1,grid[0].size(),grid.size()) &&
                  !visited[r1][c1]){
                    
                    if(grid[r1][c1]==color){
                       // cout<<r1<<" "<<c1<<endl;
                        visited[r1][c1]=true;
                        dfs(r1,c1,grid,visited,color);
                    }
                }
            
        }
            
        
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<bool>> change(grid.size(),vector<bool>(grid[0].size(),false));
        int c=grid[r0][c0];
        visited[r0][c0]=true;
        dfs(r0,c0,grid,visited,c);
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(visited[i][j] && grid[i][j]==c 
                  && (isCorner(i,j,grid[0].size(),grid.size())
                     || isDiff(i,j,grid))){
                    change[i][j]=true;
                }
            }
        }
        
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(change[i][j]){
                    grid[i][j]=color;
                }
            }
        }
        return grid;
    }
};