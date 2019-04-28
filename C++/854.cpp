__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
int dfs(string& A, string& B, int d){     
    //cout << "A = " << A << ", B = " << B << endl;
    if(A == B) return 0;
    for(int i = d; i < A.size(); i++)//if there are a switch can make two slot to be order, take it in priority
        if(A[i] != B[i])
            for(int j = i + 1; j < A.size(); j++)
                if(A[j] == B[i] && A[j] != B[j] && A[i] == B[j]){ //A[j] != B[j], not disorder the ordered lots
                    swap(A[i], A[j]);   
                    //cout << "double" << i << "," << j << endl;
                    int ret = dfs(A, B, d+1) + 1;
                    swap(A[i], A[j]);
                    return ret;
                }
    int ret = INT_MAX;
    //cout << " d = " << d << endl;
    for(int i = 0; i < A.size(); i++)
        if(A[i] != B[i]){
            for(int j = i + 1; j < A.size(); j++)
                if(A[j] == B[i] && A[j] != B[j]){ //now move forward by making one slot to be ordered
                    //cout << "single" << i << "," << j << endl;
                    swap(A[i], A[j]);  
                    ret = min(ret, dfs(A, B, d+1) + 1);
                    swap(A[i], A[j]);
                }
            break;
        }
    //cout << "ret = " << ret << endl;
    return ret == INT_MAX ? 0 : ret;
}
int kSimilarity(string A, string B) {
    int ret = dfs(A, B,0); //use B as target , evolve A
    return ret;
}

};
__________________________________________________________________________________________________
sample 8784 kb submission
class Solution {
public:
    int ans = INT_MAX;
    void dfs(int step, int idx, string& a, string& b){
        if (step >= ans)
            return;
        
        
        if (idx == b.size()){
            ans = min(ans, step);
            return;
        }
        if (a[idx] == b[idx]){
            dfs(step , idx + 1, a, b);
            return;
        }
        for (int i = idx + 1; i < b.size(); i++){
            if (a[i] == b[idx] && a[idx] == b[i]){
                swap(a[i], a[idx]);
                dfs(step + 1, idx + 1 , a, b);
                swap(a[i], a[idx]);
                return;
            }
            
            if (a[i] == b[idx]){  
                swap(a[i], a[idx]);
                dfs(step + 1, idx + 1, a, b);
                swap(a[i], a[idx]);
            }
        }
    }
    
    int kSimilarity(string A, string B) {
        dfs(0 ,0 , A, B);
        return ans;
    }
};
__________________________________________________________________________________________________
