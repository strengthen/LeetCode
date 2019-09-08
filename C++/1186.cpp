__________________________________________________________________________________________________
36ms
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<int> fw(n,0);
        vector<int> bw(n,0);
        int cur_max=arr[0],max_so_far=arr[0];
        fw[0]=arr[0];
        for(int i=1;i<n;i++){
            cur_max=max(arr[i],cur_max+arr[i]);
            max_so_far=max(max_so_far,cur_max);
            fw[i]=cur_max;
        }
        cur_max=max_so_far=bw[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            cur_max=max(arr[i],cur_max+arr[i]);
            max_so_far=max(max_so_far,cur_max);
            bw[i]=cur_max;
        }
        int res=max_so_far;
        for(int i=1;i<n-1;i++)
            res=max(res,fw[i-1]+bw[i+1]);
        return res;
    }
};
__________________________________________________________________________________________________
sample 40 ms submission
class Solution {
public:
    vector < int > pref, suf;
    int maximumSum(vector<int>& A) {
        int n = A.size();
        if(n == 1) {
            return A[0];
        }
        pref.resize(n + 4);
        suf.resize(n + 4);
        pref[0] = 0;
        
        int ans = 0;
        int cur = 0;
        for(int i = 0;i < n;++i) {
            cur += A[i];
            ans = max(ans, cur);
            if(cur < 0) {
                cur = 0;
            }
            pref[i] = cur;
            // cout << pref[i] << " ";
        }
        // cout << "\n";
        
        cur = 0;
        for(int i = n - 1;i > -1;--i) {
            cur += A[i];
            ans = max(ans, cur);
            if(cur < 0) {
                cur = 0;
            }
            suf[i] = cur;
            // cout << suf[i] << " ";
        }
        // cout << "\n";
        
        for(int i = 0;i < n;++i) {
            if(A[i] < 0) {
                // cout << i << " " << pref[i] << " " << suf[i + 1] << "\n";
                ans = max(ans, suf[i + 1] + (i ? pref[i - 1] : 0));
            }
        }
        
        if(ans == 0) {
            int mi = A[0];
            for(int i = 0;i < n;++i) {
                mi = min(mi, A[i]);
            }
            if(mi == 0) {
                return 0;
            }
            return mi;
        }
        
        return ans;
    }
};
__________________________________________________________________________________________________
