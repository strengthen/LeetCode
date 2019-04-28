__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        const int R = A.size();
        const int C = A[0].size();
        vector<vector<int>> B(C, vector<int>(R));
        for(int r = 0; r < R; ++r){
            for(int c = 0; c < C; ++c){
                B[c][r] = A[r][c];
            }
        }
        return B;
    }
};

struct InputBooster {
    InputBooster(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
}ib;
__________________________________________________________________________________________________
sample 11552 kb submission
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.size() == 0)
            return A;
        int temp = 0;
        int m = A.size(), n = A[0].size();
        vector<vector<int>> result(n, vector<int>(m, 0));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) {
                result[j][i] = A[i][j];
            }
        return result;
    }
};
__________________________________________________________________________________________________
