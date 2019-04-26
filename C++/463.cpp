__________________________________________________________________________________________________
sample 52 ms submission
static const auto ___ = [](){
    std::cout.sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int height=grid.size(),weight=grid[0].size();
        int res=0;
        for(int i=0;i<height;i++){
            for(int j=0;j<weight;j++){
                if(grid[i][j]==1){
                    if(i==0||grid[i-1][j]==0)
                        res++;
                    if(i==height-1||grid[i+1][j]==0)
                        res++;
                    if(j==0||grid[i][j-1]==0)
                        res++;
                    if(j==weight-1||grid[i][j+1]==0)
                        res++;
                }}}
        return res;
    }
};
__________________________________________________________________________________________________
sample 16312 kb submission
static const auto __ = [](){
    std::cout.sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int moves[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    bool isValid(int x,int y,vector<vector<int>> &grid)
    {
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size())
        {
            return false;
        }
        return true;
    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
          int perimeter=0;
          for(int i=0;i<grid.size();i++)
          {
              for(int j=0;j<grid[0].size();j++)
              {
                  if(grid[i][j]==1)
                  {
                    int t=4;
                    for(int k=0;k<4;k++)
                    {
                        if(isValid(i+moves[k][0],j+moves[k][1],grid) && grid[i+moves[k][0]][j+moves[k][1]]==1)
                        {
                            t--;       
                        }
                    }
                    perimeter+=t;
                  }
              }
          }
        return perimeter;
                           }
};
__________________________________________________________________________________________________
