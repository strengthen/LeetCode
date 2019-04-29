__________________________________________________________________________________________________
sample 24 ms submission
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        if(!K) return 0;
        int sum = 0;
        int res = 0;
        vector<int> memo(K);
        for(int n: A) {
            sum += n;
            sum = (sum % K + K) % K;
            if(sum == 0) ++res;
            res += memo[sum];
            ++ memo[sum];
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
sample 11976 kb submission
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int mod[K];
        memset(mod,0,sizeof(mod));
        int sum=0,i;
        
        for(i=0;i<A.size();i++)
        {
            sum+=A[i];
            
            mod[((sum%K)+K)%K]++;
        }
        int ct=0;
        
        for(i=0;i<K;i++)
        {
            if(mod[i]>1)
                ct+=(mod[i]*(mod[i]-1))/2;
        }
        
        ct+=mod[0];
        return ct;
    }
};
__________________________________________________________________________________________________
