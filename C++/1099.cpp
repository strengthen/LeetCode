__________________________________________________________________________________________________
class Solution {
public:
    int twoSumLessThanK(vector<int>& a, int k) {
        int ret = -1;
        int n = a.size();
        for (int i = 0; i < n; ++ i)
            for (int j = i+1; j < n; ++ j)
                if (a[i]+a[j] < k)
                {
                    if (ret == -1 || a[i]+a[j] > ret) ret = a[i]+a[j];
                }
        return ret;
    }
};

__________________________________________________________________________________________________
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int n=A.size();
        int ans=-1;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (A[i]+A[j]>=K) continue;
                ans=max(ans, A[i]+A[j]);
            }
        }
        
        return ans;
    }
};

__________________________________________________________________________________________________
