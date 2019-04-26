__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int fib(int N) {
        if(N==0) return 0;
        int a=1,b=1,c=1;
        if(N<2) return 1;
        N-=2;
        while(N--)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
};
__________________________________________________________________________________________________
sample 8096 kb submission
class Solution {
public:
    int fib(int N) {
        
        if(N == 0)
            return 0;
        int dp[N+1];
        
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2 ;i <= N;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[N];
    }
};
__________________________________________________________________________________________________
