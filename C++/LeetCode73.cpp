__________________________________________________________________________________________________
44ms
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int m = matrix.size();
        if(!m) return ;
        int n = matrix[0].size();
        bool row[m + 5] = {0}, col[n + 5] = {0};
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                if(!matrix[i][j]) {row[i] = true; col[j] = true;}
        
        for(int i = 0; i < m; i++) {
            if(row[i]) 
                for(int j = 0; j < n; j++) matrix[i][j] = 0;
        }
        
        for(int j = 0; j < n; j++) {
            if(col[j]) 
                for(int i = 0; i < m; i++) matrix[i][j] = 0;
        }
    }
};
__________________________________________________________________________________________________
11304 kb
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        for (int i=0; i<rows; i++) {
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j=1; j<cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i=rows-1; i>=0; i--) {
            for (int j=cols-1; j>=1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};
__________________________________________________________________________________________________
