__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int superEggDrop(int K, int N) {
        int dp[N+1][K+1];
    memset(dp, 0, sizeof(dp));
    //dp[0][0] = 0;
    for (int m = 1; m <= N; m++) {
        //dp[m][0] = 0;
        for (int k = 1; k <= K; k++) {
            dp[m][k] = dp[m-1][k] + dp[m-1][k-1] + 1;
            if (dp[m][k] >= N) {
                return m;
            }
        }
    }
    return N;
    }
};
__________________________________________________________________________________________________
sample 8756 kb submission
class Solution {
public:
    int superEggDrop(int K, int N) {
        
        //m最多就是N樓所以allocate N+1
        vector<int> dp(K+1,0);
        int m=0;
        //注意!! 這邊m初始是0, 因為一輪做完m會++
        for(m=0; dp[K] < N; m++){
            for(int k=K;k>=1;k--){
                dp[k] = dp[k-1]+dp[k]+1;
            }
        }
        return m;        
    }
};
__________________________________________________________________________________________________
