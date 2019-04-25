__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
        for (int i = 0; i < A.size(); ++i) {
            for (int k = 0; k < A[0].size(); ++k) {
                if (A[i][k] != 0) {
                    for (int j = 0; j < B[0].size(); ++j) {
                        if (B[k][j] != 0) res[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
        vector<vector<pair<int, int>>> v(A.size(), vector<pair<int,int>>());
        for (int i = 0; i < A.size(); ++i) {
            for (int k = 0; k < A[i].size(); ++k) {
                if (A[i][k] != 0) v[i].push_back({k, A[i][k]});
            }
        }
        for (int i = 0; i < A.size(); ++i) {
            for (int k = 0; k < v[i].size(); ++k) {
                int col = v[i][k].first;
                int val = v[i][k].second;
                for (int j = 0; j < B[0].size(); ++j) {
                    res[i][j] += val * B[col][j];
                }
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
