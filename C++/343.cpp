__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int integerBreak(int n) 
    {
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for(int i = 3; i <=n; i++)
        {
            int start = 1, end = i-1;
            while (start <= end)
            {
                int maxstart = max(start,dp[start]);
                int maxend = max(end,dp[end]);
                dp[i] = max(dp[i],maxstart*maxend);
                start++;
                end--;
            }
           
            
        }
        
        
        return dp[n];
        
    }
};
__________________________________________________________________________________________________
sample 8016 kb submission
class Solution {
public:
    int integerBreak(int n) {
        if(n==2||n==3) return n-1;
        int ret=1;
        while(n>4){
            ret*=3;
            n-=3;
        }
        return ret*n;
    }
};
__________________________________________________________________________________________________
