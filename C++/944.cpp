__________________________________________________________________________________________________
sample 16 ms submission
static const int fastIO = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        
        if (A.empty() || A[0].empty())
            return 0;
        
        int count = 0, size_a = A.size(), size_s = A[0].size();
        
        for (int i = 0; i < size_s; ++i){
            char pre = A[0][i];
            for (int j = 1; j < size_a; ++j){
                if(A[j][i] < pre){
                    ++count;
                    break;
                }
                pre = A[j][i];
            }
        }
        
        return count;
    }
};
__________________________________________________________________________________________________
sample 12864 kb submission
auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m=A.size();
        int n=A[0].size();
        int ret=0;
        for(int i=0;i<n;i++){
            bool needDeletion=false;
            for(int j=1;j<m;j++){
                if(A[j][i]<A[j-1][i]){
                    needDeletion=true;
                    break;
                }
            }
            if(needDeletion){
                ret++;
            }
        }
        return ret;
    }
};
__________________________________________________________________________________________________
