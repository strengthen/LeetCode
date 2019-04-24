__________________________________________________________________________________________________
sample 36 ms submission
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0, r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            }
            matrix[r][c] > target ? c-- : r++;
        }
        return false;
    }
};static auto _=[](){ios::sync_with_stdio(false);return 0;}();
__________________________________________________________________________________________________
sample 12036 kb submission
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int cur_row = 0, cur_col = col-1;
        
        while(cur_row < row && cur_col >= 0){
            int tem = matrix[cur_row][cur_col];
            if(tem == target) return true;
            else if(tem > target) --cur_col;
            else ++cur_row;
        }
        
        return false;
    }
};
__________________________________________________________________________________________________
