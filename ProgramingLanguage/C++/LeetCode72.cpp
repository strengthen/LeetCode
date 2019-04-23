__________________________________________________________________________________________________
8ms
class Solution {
public:
    int minDistance(string word1, string word2) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int len1 = word1.length(), len2 = word2.length();
        if(!len1 || !len2) return max(len1, len2);
        
        int dp[2][len2 + 5];
        bool now = 1;
        for(int j = 0; j <= len2; j++) dp[!now][j] = j;
       
        for(int i = 1; i <= len1; i++) {
            if(word1[i - 1] == word2[0]) {
                dp[now][1] = i - 1;
            }else {
                dp[now][1] = min(dp[!now][1], i - 1) + 1;//delete, add, change
            }
            for(int j = 2; j <= len2; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[now][j] = dp[!now][j - 1];
                }else {
                    dp[now][j] = min(dp[!now][j], min(dp[now][j - 1], dp[!now][j - 1])) + 1;//delete, add, change
                }
            }
            now = !now;
        }
        return dp[!now][len2];
        
    }
};
__________________________________________________________________________________________________
8364 kb
class Solution {
public:
    int minDistance(string A, string B) {
        /**
            状态定义：   设f(i,j)为序列<1..j>编辑成<1..i>所需要的最少步数
            转移方程：   f(i,j) = min{  f(i,j-1) + 1, f(i-1,j) + 1, f(i-1,j-1)+0/1  }
            初始条件：   f(0,0) = 0, f(i,0) = i, f(0,j) = j
         **/
        int n = A.size(), m = B.size();
        
        vector<int> dp(m+1, 0);
        for (int j = 1; j <= m; j++) dp[j] = j;
        
        int diag = 0, temp = 0;             // 左上角元素
        for (int i = 1; i <= n; i++) {
            diag   = dp[0];
            dp[0]  = i;
            for (int j = 1; j <= m; j++) {
                temp   = dp[j];
                dp[j]  = min(min(dp[j-1] + 1, dp[j] + 1), diag + (A[i-1] == B[j-1] ? 0 : 1));
                diag   = temp;
            }
        }
        
        return dp[m];
    }
};
__________________________________________________________________________________________________
