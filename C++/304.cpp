__________________________________________________________________________________________________
sample 20 ms submission
static int fast = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        const int n = matrix.size()+1;
        const int m = n > 1? matrix[0].size()+1 : 1;

        _m.push_back({});
        for (int j = 0;j < m;j++) {
            _m[0].push_back(0);
        }
        for (int i = 1;i < n;i++) {
            _m.push_back({0});
            for (int j = 1;j < m;j++) {
                _m[i].push_back(matrix[i-1][j-1]+_m[i-1][j]+_m[i][j-1]-_m[i-1][j-1]);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       /* if (row1 >= (int)_m.size()-1 ||
           col1 >= (int)_m[0].size()-1) {
            return 0;
        }
        if (row1 < 0) {
            row1 = 0;
        }
        if (col1 < 0) {
            col1 = 0;
        }
        
        if (row2 >= _m.size()-1) {
            row2 = _m.size()-2;
        }
        
        if (col2 >= _m[0].size()-1) {
            col2 = _m[0].size()-2;
        }*/
        return _m[row2+1][col2+1]+_m[row1][col1]-_m[row2+1][col1]-_m[row1][col2+1];
    }

private:
    vector<vector<int>> _m;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
__________________________________________________________________________________________________
sample 16368 kb submission
class NumMatrix {
private:
    vector<vector<int>> summatrix;
public:
    NumMatrix(vector<vector<int>> matrix) {
        for(int i = 0 ; i<matrix.size() ; ++i){
            for(int j=1 ; j<matrix[i].size() ; ++j){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        summatrix = move(matrix);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int re = 0;
        
        for(int i = row1 ; i<= row2 ; ++i){
            if(col1 == 0){
                re += summatrix[i][col2];
            } else {
                re += (summatrix[i][col2] - summatrix[i][col1-1]);
            }
        }
        
        return re;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
__________________________________________________________________________________________________
