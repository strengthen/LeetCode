__________________________________________________________________________________________________
sample 4 ms submission
static int __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);
    return 0;
}();

void transpose(vector<vector<int>>& grid) {
  assert(grid.size() == grid[0].size());
  for (size_t r = 0; r < grid.size(); r++) 
    for (size_t c = 0; c < r; c++) 
      std::swap(grid[r][c], grid[c][r]);
}


class Solution {
public:  
    int projectionArea(vector<vector<int>>& grid) {
      int s = 0;
      for (auto &v : grid)
        for (auto c : v)
          s += c > 0;
      
      for (auto &v : grid)
        s += *max_element(v.begin(), v.end());
      
      transpose(grid);
      
      for (auto &v : grid)
        s += *max_element(v.begin(), v.end());
      
      return s;
    }
};
__________________________________________________________________________________________________
sample 9668 kb submission
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans;
        int xy = 0, yz = 0, zx = 0;
        for(int  i = 0; i < grid.size(); i++){
            int max1 = 0, max2 = 0;
            for(int j = 0; j < grid[i].size(); j++){
                
                if(grid[i][j] != 0)
                    xy++;
                
                if(grid[i][j] > max1)
                    max1 = grid[i][j];
                
                if(grid[j][i] > max2)
                    max2 = grid[j][i];
                
            }
            
            yz += max2;
            zx += max1;
        }
        ans = xy + yz +zx;
        return ans;
    }
};
__________________________________________________________________________________________________
