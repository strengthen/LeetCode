__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return 0;
        }
        vector<int> track(matrix[0].size(),0);
        int count = 0, max_count = 0;
        for(vector<char> row:matrix){
            for(int i=0;i<row.size();i++){
                if(row[i]=='1'){
                    track[i] += 1;
                }
                else{
                    track[i] = 0;
                }
            }
            count = 0;
            for(int i=0;i<row.size();i++){
                if(track[i]>max_count){
                    count += 1;
                    if(count==max_count+1){
                        max_count += 1;
                        break;
                    }
                }
                else{
                    count = 0;
                }
            }
        }
        return max_count*max_count;
    }
};

static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0; 
}();
__________________________________________________________________________________________________
sample 10752 kb submission
class Solution {
public:
    int dfs(vector<vector<char>>& matrix, int i, int j) {
        int size = 1;
        while (i + size < matrix.size() && j + size < matrix[0].size()) {
            for (int k = i; k <= i + size; ++k) {
                if (matrix[k][j + size] != '1') return size * size;
            }
            for (int k = j + size - 1; k >= j; --k) {
                if (matrix[i + size][k] != '1') return size * size;
            }
            ++size;
        }
        return size * size;
    }
    
    // Runtime: O(M^2 N^2)
    int maximalSquare(vector<vector<char>>& matrix) {
        int ret = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    ret = max(ret, dfs(matrix, i, j));
                }
            }
        }
        return ret;
    }
};
__________________________________________________________________________________________________
