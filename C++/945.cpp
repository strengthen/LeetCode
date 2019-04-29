__________________________________________________________________________________________________
sample 44 ms submission
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() == 0){
            return 0;
        }
        sort(A.begin(), A.end());

        int count = 0;
        for(int i = 0; i < A.size()-1; i++){
            if(A[i] >= A[i+1]){
                count += A[i] - A[i+1]+1;
                A[i+1] += A[i] - A[i+1] +1;
            }
        }
        return count;
    }
    
};

static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
sample 12068 kb submission
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.empty()) return 0;
        if(A.size()==1) return 0;
        
        int res=0;
        sort(A.begin(),A.end());
        int pre=A[0];
        for(int i=1;i<A.size();i++){
            while(A[i]<=A[i-1]){
                ++A[i];
                ++res;
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
