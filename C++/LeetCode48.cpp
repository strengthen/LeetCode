__________________________________________________________________________________________________
4ms
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = n - 2 - i; j >= 0; j--) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
    }
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    void helper(vector<vector<int>>& matrix, int begin, int end) {
        // if it is 1 * 1 matrix
        if (begin >= end) {
            return;
        }
        else {
            for (int i = begin; i < end; i++) {
                int upper_left = matrix[begin][i];
                int upper_right = matrix[i][end];
                // i - begin is the offset from begin
                int bottom_right = matrix[end][end - (i - begin)];
                int bottom_left = matrix[end - (i - begin)][begin];
                matrix[begin][i] = bottom_left;
                matrix[i][end] = upper_left;
                matrix[end][end - (i - begin)] = upper_right;
                matrix[end - (i - begin)][begin] = bottom_right;
            }
            helper(matrix, begin + 1, end - 1);
        }
    }
    
    
    void rotate(vector<vector<int>>& matrix) {
        int begin = 0;
        int end = matrix.size() - 1;
        helper(matrix, begin, end);
    }
};
__________________________________________________________________________________________________
8904 kb
class Solution {
public:
    void rotate(vector<vector<int>>& m) {       
        int n = m.size();
        //transpose
        for(int i = 0 ; i < n; i++)
        {
            for(int j = i ; j < n; j++)
            { 
                 int tmp = m[j][i];
                 m[j][i] = m[i][j];
                 m[i][j] = tmp;
                
            }
        }
        
     // reverse each row
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n / 2; j++) {
        int tmp = m[i][j];
        m[i][j] = m[i][n - j - 1];
        m[i][n - j - 1] = tmp;
      }
    } 
  }
};
__________________________________________________________________________________________________
8988 kb
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        std::reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++)
            for (int j = i + 1; j < matrix[i].size(); j++)
                std::swap(matrix[i][j], matrix[j][i]);
    }
};
__________________________________________________________________________________________________