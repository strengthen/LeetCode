__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector <int> sum(A.size(),0);
        vector<int> mp(A.size()+2,0);
        sum[0]=A[0];
        int no=0;
        for(int i=0;i<A.size();i++)
        {
            if(i>=1)
            sum[i]=sum[i-1]+A[i];
            if(sum[i]-S>=0)
            no+=mp[sum[i]-S];
            mp[sum[i]]++;
        }
        no+=mp[S];
        return no;
    }
};
__________________________________________________________________________________________________
sample 10932 kb submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int subarrays_with_sum_at_most(vector <int>& A, int S)
    {
        int ans = 0, L = 0, n = A.size(), sum = 0; // sum : A[L] + ... + A[i]
        for(int i = 0; i < n; i++)
        {
            sum += A[i];
            while(sum > S && L <= i)
            {
                sum -= A[L];
                L++;
            }
            ans += i - L + 1; 
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        int ans = subarrays_with_sum_at_most(A, S);
        if(S > 0)
            ans -= subarrays_with_sum_at_most(A, S - 1);
        return ans;
    }
};
__________________________________________________________________________________________________
