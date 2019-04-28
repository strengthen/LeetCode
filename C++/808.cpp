__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    double memo[200][200];
    double soupServings(int N) {
        return N >= 4800 ? 1.0 : f(N/25+(N%25>0?1:0), N/25+(N%25>0?1:0));
    }
    double f(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0;
        if (memo[a][b] > 0) return memo[a][b];
        memo[a][b] = 0.25 * (f(a - 4, b) + f(a - 3, b - 1) + f(a - 2, b - 2) + f(a - 1, b - 3));
        return memo[a][b];
    }
};
__________________________________________________________________________________________________
sample 8988 kb submission
const int N = 209;
double dp[N][N];

class Solution {
public:
    double dfs(int x,int y){
        
        if(x<=0 && y>0) return 1;
        if(x<=0 && y<=0) return 0.5;
        if(y<=0) return 0;
        
        double &d = dp[x][y];
        if(d>-0.5) return d;
        
        d = 0;
        d = 0.25 * ( dfs(x-4,y) + dfs(x-3,y-1) + dfs(x-2,y-2) +dfs(x-1,y-3));
        return d;
        
    }
    double soupServings(int n) {
        if(n>5000) return 1.0;
        n = (n+24)/25;
        for(int i = 0 ;i<=n;i++)
            for(int j = 0;j<=n;j++){
                dp[i][j] = -1;
            }
        
        return dfs(n,n);
    }
};
__________________________________________________________________________________________________
