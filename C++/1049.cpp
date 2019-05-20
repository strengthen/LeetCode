__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    // DFS
    int mem[31][6002] = {0};
    int lastStoneWeightII(vector<int>& stones, int sum=0, int index=0) {
        if (index == stones.size()) return sum < 0? INT_MAX: sum;
        if (mem[index][sum+3001] != 0) return sum+3001;
        int current_sum = min(lastStoneWeightII(stones, sum+stones[index], index+1),
                              lastStoneWeightII(stones, sum-stones[index], index+1));
        mem[index][sum+3001] = 1;
        return current_sum;
    }
};
__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
     int lastStoneWeightII(vector<int> A) {
        bitset<1501> dp = {1};
        int sumA = 0, res = 100;
        for (int a : A) {
            sumA += a;
            for (int i = sumA; i >= a; --i)
                dp[i] = dp[i] + dp[i - a];
        }
        for (int i = sumA / 2; i > 0; --i)
            if (dp[i]) return sumA - i - i;
        return 0;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
       int lastStoneWeightII(vector<int>& a) {
           
           int i,j,k,n=a.size();
           int sum = accumulate(a.begin(),a.end(),0);
           int prev=sum;

           sum/=2;
           sum += (prev&1)?1:0;
           a.insert(a.begin(),0);
           
           int dp[n+1][sum+1];
           for(i=0;i<=n;i++)
               for(j=0;j<=sum;j++)
                   dp[i][j]=0;
           
           for(i=0;i<=n;i++)
               dp[i][0]=1;
           
           int maxs=0;
           for(j=1;j<=sum;j++)
           {
               for(i=1;i<=n;i++)
               {
                   if(dp[i-1][j])
                       dp[i][j]=1;
                   else if(j>=a[i] && dp[i-1][j-a[i]]==1)
                   {
                       dp[i][j]=1;
                       maxs=max(j,maxs);
                   }    
                }
           }
           
           prev=prev-maxs;
           return abs(maxs-prev);
    }
};