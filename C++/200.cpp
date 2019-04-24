__________________________________________________________________________________________________
sample 8 ms submission
template <typename T> inline T safe_cast(size_t size) {
  assert(size <= static_cast<size_t>((std::numeric_limits<T>::max)()));
  return static_cast<T>(size);
}

static const int _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
  int numIslands(std::vector<std::vector<char>>& Grid) {
    const int RowNum = safe_cast<int>(Grid.size());
    if (RowNum < 1)
      return 0;
    const int ColNum = safe_cast<int>(Grid[0].size());
    if (ColNum < 1)
      return 0;
    
    std::function<void(int, int)> FillConnectedOne;
    FillConnectedOne = [&](int Row, int Col) {
      if (Row < 0 || Col < 0 || Row >= RowNum || Col >= ColNum ||
          Grid[Row][Col] == '0')
        return;
      Grid[Row][Col] = '0';
      FillConnectedOne(Row - 1, Col);
      FillConnectedOne(Row, Col - 1);
      FillConnectedOne(Row + 1, Col);
      FillConnectedOne(Row, Col + 1);
    };
    
    int IslandCnt = 0;
    for (int Row = 0; Row < RowNum; ++Row) {
      for (int Col = 0; Col < ColNum; ++Col) {
        if (Grid[Row][Col] == '1') {
          FillConnectedOne(Row, Col);
          IslandCnt++;
        }
      }
    }
    
    return IslandCnt;
  }
};
__________________________________________________________________________________________________
sample 10752 kb submission
class Solution {
public:
    static constexpr int moves[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size()==0 || grid[0].size()==0)
            return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                    count += 1;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i>=m || j>=n || grid[i][j]=='0')
            return;
        
        grid[i][j] = '0';
        for (auto move : moves) 
            dfs(grid, i+move[0], j+move[1], m, n);
        
        return;
    }    
};
__________________________________________________________________________________________________
