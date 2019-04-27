__________________________________________________________________________________________________
× Close
sample 132 ms submission
auto speedup =[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {    
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M)
    {
        const int ymax = M.size() - 1;
        const int xmax = M[0].size() - 1;
        vector<vector<int>> out(ymax+1, vector<int>(xmax+1));
        if (ymax == 0 && xmax == 0) 
        {
            out[0][0] = M[0][0];
        }
        else if (ymax == 0)
        {
            out[0][0   ] = (M[0][0     ] + M[0][1   ])/2;
            out[0][xmax] = (M[0][xmax-1] + M[0][xmax])/2;
            for (int x = 1; x < xmax; ++x) 
                out[0][x] = (M[0][x-1] + M[0][x] + M[0][x+1])/3;
        } 
        else if (xmax == 0) 
        {
            out[0   ][0] = (M[0     ][0] + M[1   ][0])/2;
            out[ymax][0] = (M[ymax-1][0] + M[ymax][0])/2;
            for (int y = 1; y < ymax; ++y) 
                out[y][0] = (M[y-1][0] + M[y][0] + M[y+1][0])/3;
        }
        else 
        {
            // four corners
            out[0   ][0   ] = (M[0     ][0     ] + M[0     ][1   ] + M[1   ][0     ] + M[1   ][1   ])/4;
            out[0   ][xmax] = (M[0     ][xmax-1] + M[0     ][xmax] + M[1   ][xmax-1] + M[1   ][xmax])/4;
            out[ymax][0   ] = (M[ymax-1][0     ] + M[ymax-1][1   ] + M[ymax][0     ] + M[ymax][1   ])/4;
            out[ymax][xmax] = (M[ymax-1][xmax-1] + M[ymax-1][xmax] + M[ymax][xmax-1] + M[ymax][xmax])/4;
            
            // left-side, right-side
            for (int y = 1; y < ymax; ++y) {
                out[y][0   ] = (M[y-1][0     ] + M[y-1][1   ] + 
                                M[y  ][0     ] + M[y  ][1   ] +
                                M[y+1][0     ] + M[y+1][1   ])/6;
                out[y][xmax] = (M[y-1][xmax-1] + M[y-1][xmax] + 
                                M[y  ][xmax-1] + M[y  ][xmax] + 
                                M[y+1][xmax-1] + M[y+1][xmax])/6;
            }
            
            // top-, bottom
            for (int x = 1; x < xmax; ++x) {
                out[0   ][x] = (M[0     ][x-1] + M[0     ][x] + M[0     ][x+1] +
                                M[1     ][x-1] + M[1     ][x] + M[1     ][x+1])/6;
                out[ymax][x] = (M[ymax-1][x-1] + M[ymax-1][x] + M[ymax-1][x+1] +
                                M[ymax  ][x-1] + M[ymax  ][x] + M[ymax  ][x+1])/6;
            }
            
            // others
            for (int y = 1; y < ymax; ++y) {
                for (int x = 1; x < xmax; ++x) {
                    out[y][x] = (M[y-1][x-1] + M[y-1][x] + M[y-1][x+1] + 
                                 M[y  ][x-1] + M[y  ][x] + M[y  ][x+1] + 
                                 M[y+1][x-1] + M[y+1][x] + M[y+1][x+1])/9;
                }
            }
        }
        return out;
    }
};
__________________________________________________________________________________________________
sample 17356 kb submission
class Solution {
    void sumRow(vector<int>& row, const int& colCount) {
        int prev = 0;
        for (int col = 0; col < colCount - 1; col++) {
            int tmp = row[col];
            row[col] += prev + row[col+1];
            prev = tmp;
        }
        row[colCount - 1] += prev;
    }
    void sumCol(vector<vector<int>>& M, const int rowCount, const int& col) {
        int prev = 0;
        for (int row = 0; row < rowCount - 1; row++) {
            int tmp = M[row][col];
            M[row][col] += prev + M[row+1][col];
            prev = tmp;
        }
        M[rowCount - 1][col] += prev;
    }
    int getNeighborWithSelfCount(const int& rowCount, const int& colCount, const int& row, const int& col) {
        // special cases
        if (rowCount == 1) {
            if (colCount == 1) {
                // leave this cell alone
                return 1;
            }
            else {
                if (col == 0 || col == colCount - 1) {
                    // first/last in row
                    return 2;
                }
                else {
                    // middle in the row
                    return 3;
                }
            }
        }
        else if (colCount == 1) {
            if (row == 0 || row == rowCount - 1) {
                // first/last in col
                return 2;
            }
            else {
                // middle in the col
                return 3;
            }
        }
        
        // normal matrix;
        if (row == 0 || row == rowCount - 1) {
            if (col == 0 || col == colCount - 1) {
                // corners
                return 4;
            }
            else {
                // top or bottom (not corners)
                return 6;
            }
        }
        else {
            if (col == 0 || col == colCount - 1) {
                // left or right (not corners)
                return 6;
            }
            else {
                // middle cells
                return 9;
            }
        }
    }
    void divByNeighborCount(vector<vector<int>>& M, const int& rowCount, const int& colCount) {
        for (int row = 0; row < rowCount; row++) {
            for (int col = 0; col < colCount; col++) {
                int neighborWithSelfCount = getNeighborWithSelfCount(rowCount, colCount, row, col);
                M[row][col] /= neighborWithSelfCount;
            }
        }
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        const int rowCount = M.size();
        if (rowCount == 0) {
            return {};
        }
        const int colCount = M[0].size();
        if (colCount == 0) {
            return {};
        }
        
        for (int row = 0; row < rowCount; row++) {
            sumRow(M[row], colCount);
        }
        
        for (int col = 0; col < colCount; col++) {
            sumCol(M, rowCount, col);
        }
        
        divByNeighborCount(M, rowCount, colCount);
        return move(M);
    }
};
__________________________________________________________________________________________________
