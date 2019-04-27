__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    
    int minimumDeleteSum(string s1, string s2) {
        /*
            F[i][j] 在s1前i个字符，s2前j个字符，中选取若干个字符删除后相同。使得目标最大
        */
        int m = s1.size(), n = s2.size();
        int dp[m][n], a, b, c;
        for(int i = 0; i < m; i++){
            memset(dp[i], 0, sizeof(int)*n);
        }
        dp[0][0] = s1[0] == s2[0] ? 0: s1[0] + s2[0];
        bool flag = dp[0][0] == 0 ? true:false;
        
        for(int i = 1; i < m; i++){
            if(s1[i] == s2[0] and !flag){
                dp[i][0] = dp[i-1][0] - s2[0];//第一次相等
                flag = true;
            }else{
                dp[i][0] = dp[i-1][0] + s1[i];
            }
        }
        flag = dp[0][0] == 0 ? true:false;
        for(int i = 1; i < n; i++){
            if(s1[0] == s2[i] and !flag){
                dp[0][i] = dp[0][i-1] - s1[0];
                flag = true;
            }else{
                dp[0][i] = dp[0][i-1] + s2[i];
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(s1[i] == s2[j])dp[i][j] = dp[i-1][j-1];
                else{
                    /*
                    s1[i] != s2[j], 那么这两个字符一定要删除其中一个
                    删除s1[i]: F[i][j] = F[i-1][j] + s1[i]
                    删除s2[j]: F[i][j] = F[i][j-1] + s2[j]
                    */
                    a = dp[i-1][j] + s1[i];
                    b = dp[i][j-1] + s2[j];
                    dp[i][j] = a < b ? a:b;
                }
            }
        }
        
        return dp[m-1][n-1];
        
    }
};
__________________________________________________________________________________________________
sample 9308 kb submission
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> dp(n+1, 0);
        for (int j = 1; j <= n; j++)
            dp[j] = dp[j-1]+s2[j-1];
        for (int i = 1; i <= m; i++) {
            int t1 = dp[0];
            dp[0] += s1[i-1];
            for (int j = 1; j <= n; j++) {
                int t2 = dp[j];
                dp[j] = s1[i-1] == s2[j-1]? t1:min(dp[j]+s1[i-1], dp[j-1]+s2[j-1]);
                t1 = t2;
            }
        }
        return dp[n];
    }
};
__________________________________________________________________________________________________
