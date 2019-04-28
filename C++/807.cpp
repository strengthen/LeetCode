__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int totalDiff = 0;
        vector<int> rowMax;
        vector<int> colMax;
        
        if (grid.size() == 0) return 0;
        int numRows = grid.size();
        int numCols = grid[0].size();
        
        //find the max in each row
        for (vector<int> row : grid) {
            rowMax.push_back(*std::max_element(row.begin(), row.end()));
        }
        
        //find the max in each column
        for (int i = 0; i < numCols; i++) {
            int big = std::numeric_limits<int>::min();
            for (int j = 0; j < numRows; j++) {
                if (grid[j][i] > big) {
                    big = grid[j][i];
                }
            }
            colMax.push_back(big);
        }
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                int maxHeight = (rowMax[i] < colMax[j]) ? rowMax[i] : colMax[j];
                totalDiff += (maxHeight - grid[i][j]);                
            }
        }
        
        return totalDiff;
    }
};
__________________________________________________________________________________________________
sample 9192 kb submission
#pragma GCC optimize ("O3")
static const auto __ = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

using Grid = std::vector<std::vector<int>>;

class Solution {
public:
  int maxIncreaseKeepingSkyline(const Grid& grid) {
    int total_increase {0};
    std::vector<int> col_max(grid.size());
    std::vector<int> row_max(grid.size());
    // Find the tallest building for each row and column
    for (std::size_t row {0}; row < grid.size(); ++row) {
      for (std::size_t col {0}; col < grid.size(); ++col) {
        row_max[row] = std::max(row_max[row], grid[row][col]);
        col_max[col] = std::max(col_max[col], grid[row][col]);
      }
    }
    // Find the height each building can be increased by based on its row's and column's
    // tallest buildings.
    for (std::size_t row {0}; row < grid.size(); ++row) {
      for (std::size_t col {0}; col < grid.size(); ++col) {
        total_increase += std::min(row_max[row], col_max[col]) - grid[row][col];
      }
    }
    return total_increase;
  }
};
__________________________________________________________________________________________________
