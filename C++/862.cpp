__________________________________________________________________________________________________
sample 68 ms submission
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int ans = INT_MAX;
        vector<int> B(A.size()+1, 0);
        
        for(int i = 0;i<A.size(); ++i) B[i+1] = B[i] + A[i];
        deque<int> monoq;
        
        
        for(int i=0;i<A.size()+1; ++i){
            while(!monoq.empty() && B[i] - B[monoq.front()] >= K){
                ans = min(ans, i - monoq.front());
                monoq.pop_front();
            }
            
            // keep income
            while(!monoq.empty() && B[monoq.back()] >= B[i]) monoq.pop_back();
            
            monoq.push_back(i);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
__________________________________________________________________________________________________
sample 19408 kb submission
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int m = A.size();
        if(!m) return -1;
        int sum[m+1] = {0};
        sum[0] = A[0];
        int n = m+1;
        
        for(int i = 0; i < A.size(); i++){
            sum[i+1] = sum[i] + A[i];
        }
        
        deque<int> q;
        
        for(int i = 0; i <= m; i++){
            while(!q.empty() && sum[i] - sum[q.front()] >= K) {
                n = min(i-q.front(), n);
                q.pop_front();
            }
            while(!q.empty() && sum[q.back()] >= sum[i]) q.pop_back();
            q.push_back(i);
        }
        
        if(n <= m) return n;
        else return -1;
    }
};
__________________________________________________________________________________________________
