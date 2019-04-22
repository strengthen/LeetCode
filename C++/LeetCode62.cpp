__________________________________________________________________________________________________
4ms
class Solution {
public:
    int uniquePaths(int m, int n) {
        unsigned long long grid[m][n];
        for(int i=0;i<m;i++)grid[i][n-1]=1;
        for(int i=0;i<n;i++)grid[m-1][i]=1;
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                grid[i][j]=grid[i+1][j]+grid[i][j+1];
            }
        }
        //cout<<grid[0][0]<<"\n";
        return grid[0][0];
    }
};
__________________________________________________________________________________________________
7888 kb
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        
        int times = min(m,n);
        long long  A1 = 1, A2 = 1;
        for(int i=1; i<times; ++i){
            A1 *= m + n - 1 - i;
            A2 *= i; 
        }
        return A1/A2;
    }
};
__________________________________________________________________________________________________
