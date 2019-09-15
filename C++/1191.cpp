__________________________________________________________________________________________________
sample 52 ms submission
class Solution 
{
public:
    long long maxSum(vector<int>& arr)
    {
        long long ans=INT_MIN, curr=0LL;
        for(int i=0;i<arr.size();i++)
        {
            curr+=arr[i];
            ans=max(ans,curr);
            if(curr<0)
                curr=0;
        }
        if(ans<0)
            return 0;
        return ans;
    }
    int MOD=1e9+7;
    int kConcatenationMaxSum(vector<int>& arr, int k) 
    {
        long long ans=maxSum(arr);
        long long pp=0,ss=0,pSum=0,sSum=0;
        for(int i=0;i<arr.size();i++)
        {
            sSum+=arr[arr.size()-1-i];
            pSum+=arr[i];
            ss=max(ss,sSum);
            pp=max(pp,pSum);
        }
        
            long long arrSum=0LL;
            for(int i=0;i<arr.size();i++)
                arrSum+=arr[i];
            long long sum=max(0LL,arrSum);
            ans=max(ans,(pp+ss+(k-2)*sum));
            ans%=MOD;
       
        return ans;
    }
};
__________________________________________________________________________________________________
sample 56 ms submission
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int len = arr.size();
        vector<long long> pre_sum(len + 1, 0);
        long long pre_max = 0;
        long long pre_min = 0;
        long long local_max = 0;
        long long local_min = 0;
        for(int i = 0; i < len; ++i){
            pre_sum[i + 1] = pre_sum[i] + arr[i];
            pre_max = max(pre_max, pre_sum[i + 1]);
            pre_min = min(pre_min, pre_sum[i + 1]);
            local_min = min(local_min, pre_min);
            local_max = max(local_max, pre_sum[i+1] - local_min);
        }
        local_max = local_max % 1000000007;
        if(k == 1){
            return local_max;
        }
        long long ans = pre_max + (pre_sum[len] - pre_min);
        if(pre_sum[len] > 0){
            ans += pre_sum[len] * (k - 2);
            ans = ans % 1000000007;
        }
        return max(ans, local_max);
    }
};
__________________________________________________________________________________________________
