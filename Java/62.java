__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int uniquePaths(int m, int n) {
        int[] dp = new int[m];
        Arrays.fill(dp,1);
        for(int j = 1; j < n;j++){
            for(int i = 0; i < m; i++ ){
                dp[i] = dp[i] + ((i-1>=0)? dp[i-1]: 0);
            }
        }
        return dp[m-1];
    }
}
__________________________________________________________________________________________________
sample 34188 kb submission
/*
找解的个数,不需要打印出具体的解, 直接考虑DP
*/



//F1 -- DFS  ------ T!L!E!!!!!!!!!!!!!!!!
// class Solution {
//     public int uniquePaths(int m, int n) {
       
//         return dfs(m, n, 0, 0);
//     }
    
//     private int dfs(int row, int col, int i, int j) {
//         if(i > row || j > col) 
//             return 0;
//         if(i == row-1 && j == col-1) 
//             return 1;
        
        
//         int ways = dfs(row, col, i+1, j);
//         ways += dfs(row, col, i, j+1);
        
//         return ways;
//     }
// }


// //F2 --- 二维DP --- 找解的个数
// class Solution {
//     public int uniquePaths(int m, int n) {
//         if(m==0||n==0)
//             return 0;
        
//         int[][] path = new int[m][n];
//         Arrays.fill(path[0], 1);
//         for(int i = 0; i < m; i++) {
//             path[i][0] = 1;
//         }
        
//         for(int i = 1; i < m; i++) {
//         	for(int j = 1; j < n; j++)
//         		path[i][j] = path[i-1][j] + path[i][j-1];
//         }
        
//         return path[m-1][n-1];
//     }
// }



// F2.2 --- F2 优化成一维DP -- 滚动数组(两个dp[])
// class Solution {
//     public int uniquePaths(int m, int n) {
//         if(m==0||n==0)
//             return 0;
        
//         int[] path = new int[n];
//         int[] pre = new int[n];
//         Arrays.fill(pre, 1);
//         // path[0] = 1;  //坑 -- 当只有1行时,直接fill path with 1
//         Arrays.fill(path, 1);

//         for(int i = 1; i < m; i++) {
//         	for(int j = 1; j < n; j++)
//         		path[j] = pre[j] + path[j-1];
            
//             int[] temp = pre;
//             pre = path;
//             path = pre;
//         }
        
//         return pre[n-1];
//     }
// }


// //F2.3 -- 一维DP -- 滚动数组, basecase优化
// class Solution {
//     public int uniquePaths(int m, int n) {
//         int[] dp = new int[n];
//         int[] pre = new int[n];
        
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 dp[j] = (i == 0 || j == 0) ? 1 : pre[j] + dp[j - 1];
//             }
            
//             int[] temp = pre;
//             pre = dp;
//             dp = pre;
//         }
        
//         return pre[n - 1];
//     }
// }


//F3 -- 最终优化 ---- [i,j]只依赖于上一行,和本行前一个数: [i-1,j]和[i,j-1] ---- 所以一个dp[]就可以了!!
class Solution {

    public int uniquePaths(int m, int n) {
        int d[] = new int[n];
        d[0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++) {
                d[j] = d[j] + d[j - 1];
            }
        }

        return d[n - 1];
    }
}
__________________________________________________________________________________________________
