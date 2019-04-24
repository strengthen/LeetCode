__________________________________________________________________________________________________
sample 4 ms submission
#pragma GCC optimize("O3")
static const auto __ = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row_count = dungeon.size();
        if (row_count < 1) return 0;
        int column_count = dungeon[0].size();
        if (column_count < 1) return 0;
        
        if (dungeon[row_count-1][column_count-1] < 1) {
            dungeon[row_count-1][column_count-1] = 1 - dungeon[row_count-1][column_count-1];
        }
        else {
            dungeon[row_count-1][column_count-1] = 1;
        }
        
        for (int i = row_count-2; i >= 0; --i) {
            int val = dungeon[i+1][column_count-1] - dungeon[i][column_count-1];
            if (val < 1) val = 1;
            dungeon[i][column_count-1] = val;
        }
        
        for (int j = column_count-2; j >= 0; --j) {
            int val = dungeon[row_count-1][j+1] - dungeon[row_count-1][j];
            if (val < 1) val = 1;
            dungeon[row_count-1][j] = val;
        }
        
        for (int i = row_count-2; i >= 0; --i) {
            for (int j = column_count-2; j >= 0; --j) {
                int val1 = dungeon[i][j+1] - dungeon[i][j];
                if (val1 < 1) val1 = 1;
                int val2 = dungeon[i+1][j] - dungeon[i][j];
                if (val2 < 1) val2 = 1;
                
                dungeon[i][j] = min(val1, val2);
            }
        }
        
        return dungeon[0][0];
    }
};
__________________________________________________________________________________________________
sample 9864 kb submission
class Solution {
public:
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        dungeon[dungeon.size()-1][dungeon[0].size()-1] = max(1-dungeon[dungeon.size()-1][dungeon[0].size()-1], 1);
        for (int i=dungeon.size()-1;i >= 0;--i) {
            for (int j=dungeon[0].size()-1;j >= 0;--j) {
                if (i == dungeon.size()-1 and j == dungeon[0].size()-1)
                    continue;
                dungeon[i][j] = min(j+1 < dungeon[0].size() ? max(1, dungeon[i][j+1]-dungeon[i][j]) : 1e9, 
                                i+1 < dungeon.size() ? max(1, dungeon[i+1][j]-dungeon[i][j]) : 1e9);
            }
        }
           
        return dungeon[0][0];
    }
    
};
__________________________________________________________________________________________________
