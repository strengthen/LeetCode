__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        bool f=true;
        int r,c,i,j;
        r=matrix.size();
        if(r)
            c=matrix[0].size();
        
        for(int i=0;i<c;i++){
            int val=matrix[0][i];
            for(int j=0;j<r && i+j<c && f;j++){
                if(val!=matrix[j][i+j]){
                    f=false;
                }
            }
        }
        for(int i=0;i<r;i++){
            int val=matrix[i][0];
            for(int j=0;j<c && f && i+j<r;j++){
                if(val!=matrix[i+j][j])
                f=false;
            }
        }
        return f;
    }
};
__________________________________________________________________________________________________
sample 9812 kb submission
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        if(matrix.size() < 2 or matrix[0].size() < 2)
            return true;
        for(auto r = 0; r != matrix.size() - 1; ++r)
        {
            for(auto c = 0; c != matrix[0].size() - 1; ++c)
            {
                if(matrix[r][c] != matrix[r+1][c+1])
                    return false;
            }
        }
        
        return true;
    }
};

static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
