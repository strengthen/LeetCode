__________________________________________________________________________________________________
sample 24 ms submission
static const auto ___ = [](){
    std::cout.sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==0)    return 0;
        int m = matrix[0].size();
        int count = 0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]>0 && i>0 && j>0)
                    matrix[i][j] = min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]))+1;
                count += matrix[i][j];
            }
        }
        return count;
    }
};
__________________________________________________________________________________________________
sample 28 ms submission
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp(r+1, vector<int>(c+1));
        int ret = 0;
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                if(matrix[i-1][j-1]){
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
                ret += dp[i][j];
            }
        }
        return ret;
    }
};

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
__________________________________________________________________________________________________
sample 32 ms submission
static const auto ___ = [](){
    std::cout.sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==0)    return 0;
        int m = matrix[0].size();
        int count = 0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]>0 && i>0 && j>0)
                    matrix[i][j] = min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]))+1;
                count += matrix[i][j];
            }
        }
        return count;
    }
};