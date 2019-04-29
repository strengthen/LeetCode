__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        // make choice
        // A[i] + K or A[i] - K
        // <=> (A[i] + K) + K or (A[i]+K) -K
        // <=> A[i] + 2K or A[i]
        // the translation operation doesn't effect the result
        // which makes the problem much easier to handle
        sort(A.begin(),A.end());
        int mx = A[A.size()-1],mn = A[0],res = mx -mn,n = A.size();
        for(int i = 0;i<n-1;i++){
            mx = max(mx,A[i]+2*K);
            mn = min(A[i+1],A[0]+2*K);
            res = min(res,mx -mn);
        }
        return res;
        
    }
    
};
    // fast-io
    static int speedup=[](){
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        return 0;
    }();
__________________________________________________________________________________________________
sample 9984 kb submission
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int ans = A[A.size()-1] - A[0];
        for (int i = 0; i < A.size()-1; i++) {
            int high = max(A[i] + K, A[A.size()-1] - K);
            int low = min(A[0] + K, A[i+1] - K);
            ans = min(ans, high - low);
        }
        return ans;
    }
};
__________________________________________________________________________________________________
