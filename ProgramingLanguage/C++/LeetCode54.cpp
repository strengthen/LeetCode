__________________________________________________________________________________________________
4ms
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())return {};
        int row=matrix.size();
        int col=matrix[0].size();
        int begrow=0,begcol=0;
        int endrow=row-1,endcol=col-1;
        vector<int>res;
        while(begrow<=endrow&&begcol<=endcol)
        {
            for(int j=begcol;j<=endcol;j++)
                res.push_back(matrix[begrow][j]);
            begrow++;
            for(int i=begrow;i<=endrow;i++)
                res.push_back(matrix[i][endcol]);
            endcol--;
            if(endrow>=begrow)
            {
                for(int j=endcol;j>=begcol;j--)
                    res.push_back(matrix[endrow][j]);
            }
            endrow--;
            if(begcol<=endcol)
            {
                for(int i=endrow;i>=begrow;i--)
                    res.push_back(matrix[i][begcol]);
            }
            
            begcol++;
            
        }
        return res;
    }
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int c = m > n ? (n + 1) / 2 : (m + 1) / 2;
        int p = m, q = n;
        for (int i = 0; i < c; ++i, p -= 2, q -= 2) {
            for (int col = i; col < i + q; ++col) 
                res.push_back(matrix[i][col]);
            for (int row = i + 1; row < i + p; ++row)
                res.push_back(matrix[row][i + q - 1]);
            if (p == 1 || q == 1) break;
            for (int col = i + q - 2; col >= i; --col)
                res.push_back(matrix[i + p - 1][col]);
            for (int row = i + p - 2; row > i; --row) 
                res.push_back(matrix[row][i]);
        }
        return res;
    }
};
__________________________________________________________________________________________________
8500 kb
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        
        vector<int> res;        
        
        int start_row = 0;
        int start_col = 0;
        int end_row = matrix.size();
        int end_col = matrix[0].size();
        
        while (start_row < end_row && start_col < end_col) {
            for (int i = start_col; i < end_col; i++) {
                res.push_back(matrix[start_row][i]);
            }
            start_row++;
            
            for (int i = start_row; i < end_row ; i++) {
                res.push_back(matrix[i][end_col - 1]);
            }
            end_col--;
            
            if (start_row < end_row) {
                for (int i = end_col - 1; i >= start_col; i--) {
                    res.push_back(matrix[end_row - 1][i]);
                }
                end_row--;
            }
            
            if (start_col < end_col) {
                for (int i = end_row - 1; i >= start_row; i--) {
                    res.push_back(matrix[i][start_col]);
                }
                start_col++;
            }
            
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
8536 kb
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {            
        vector<int> ans;
        if(matrix.size() == 0)
            return ans;
        int top = 0;
        int bottom = matrix.size();
        int left = -1;
        int right = matrix[0].size();
        int x = 0;
        int y = 0;
        int dir = 0;//0: to right, 1: downward, 2: to left, 3: upward
        while(left<right && top<bottom){
            ans.push_back(matrix[y][x]);
            if(dir == 0){
                if(x<right-1)
                    x++;
                else if(y<bottom-1){
                    y++;
                    right--;
                    dir = (dir+1)%4;
                }
                else
                    break;
            }
            else if(dir == 1){
                if(y<bottom-1)
                    y++;
                else if(x>left+1){
                    x--;
                    bottom--;
                    dir = (dir+1)%4;
                }
                else
                    break;
            }
            else if(dir == 2){
                if(x>left+1)
                    x--;
                else if(y>top+1){
                    y--;
                    left++;
                    dir = (dir+1)%4;
                }
                else
                    break;
            }
            else if(dir == 3){
                if(y>top+1)
                    y--;
                else if(x<right-1){
                    x++;
                    top++;
                    dir = (dir+1)%4;
                }
                else
                    break;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        if (matrix.empty())
            return {};
        const int colSize = matrix[0].size();
        const int rowSize = matrix.size();
        vector<int> res;

        int count = 0;
        int state = 0;
        int rowCnt = rowSize;
        int colCnt = colSize;
        int rowIdx = 0;
        int colIdx = 0;
        int i = 0;
        
        while (rowCnt != 0 && colCnt != 0)
        {
            if (state == 0) //right
            {
                for (i = 0; i < colCnt; i++)
                    res.push_back(matrix[rowIdx][colIdx + i]);
                colIdx += (i - 1);
                rowIdx++;
                
                rowCnt--;
                
            }
            else if (state == 1) //down
            {
                for (i = 0; i < rowCnt; i++)
                    res.push_back(matrix[rowIdx + i][colIdx]);
                rowIdx += (i - 1);
                colIdx--;
                
                colCnt--;
                
            }
            else if (state == 2) //left
            {
                for (i = 0; i < colCnt; i++)
                    res.push_back(matrix[rowIdx][colIdx - i]);
                colIdx -= (i - 1);
                rowIdx--;
                
                rowCnt--;
                
            }
            else //up
            {
                for (i = 0; i < rowCnt; i++)
                    res.push_back(matrix[rowIdx- i][colIdx]);

                rowIdx -= (i - 1);
                colIdx++;
                
                colCnt--;
                
            }
            state++;
            state = state % 4;
        }
        return res;
    }
    
};
__________________________________________________________________________________________________