__________________________________________________________________________________________________
sample 12 ms submission
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
    int countLessEqualTarget(vector<vector<int>>& matrix, int target){
        int n = matrix.size();
        int i = n-1;
        int j = 0;
        int count = 0;
        
        while(i>=0 && j<n){
            if(matrix[i][j]<=target){
                count += i+1;
                j++;
            }else {
                i--;
            }
        }
        
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0];
        int r = matrix.back().back();
        int m;
        
        while(l<r){
            m = l + (r-l)/2;
            countLessEqualTarget(matrix, m) < k ? l = m+1 : r = m;
        }
        
        return l;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
