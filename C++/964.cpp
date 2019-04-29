__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        int pos = 0, neg = 0, exp = 0;
        while (target) {
            int cur = target%x;
            target /= x;
            if (exp) {
                int tmpPos = min(cur*exp+pos, (cur+1)*exp+neg);
                int tmpNeg = min((x-cur)*exp+pos, (x-cur-1)*exp+neg);
                pos = tmpPos;
                neg = tmpNeg;
            } else {
                pos = cur * 2;
                neg = (x-cur) * 2;
            }
            exp++;
        }
        return min(pos, exp+neg) - 1;
    }
};
__________________________________________________________________________________________________
sample 9184 kb submission
int dp[30][2];
int GetCnt(int v) {
    if (v == 0) return 1;
    else return v - 1;
}
class Solution {
    void Update(int i, int j, int v) {
        if (dp[i][j] == -1 || dp[i][j] > v) dp[i][j] = v;
    }
public:
    int leastOpsExpressTarget(int x, int target) {
        memset(dp, -1, sizeof(dp));
        int val[30], cnt = 0;
        while (target) {
            val[cnt++] = target % x;
            target /= x;
        }
        val[cnt++] = 0;
        //for (int i = 0; i < cnt; i++) cout << val[i] << " "; cout << endl;
        dp[cnt - 1][0] = 0;
        dp[cnt - 1][1] = GetCnt(cnt - 1);
        for (int i = cnt - 2; i >= 0; i--) {
            int v = val[i];
            // -
            for (int j = i + 1; j < cnt; j++) {
                // no left
                if (dp[j][1] != -1)
                {
                    Update(i, 0, dp[j][1] + (x - v) * (GetCnt(i) + 1));
                }
                // left
                if (dp[j][1] != -1 && v != x - 1)
                {
                    Update(i, 1, dp[j][1] + (x - v - 1) * (GetCnt(i) + 1));
                }
                if (val[j] != x - 1)break;
            }
            
            // +
            //  no left
            if (dp[i + 1][0] != -1)
            {
                if (v == 0) {
                    Update(i, 0, dp[i + 1][0]);
                } else {
                    Update(i, 0, dp[i + 1][0] + v * (GetCnt(i) + 1) + (i == cnt - 2 ? -1 : 0));
                }
                
            }
            //  left
            if (v < x - 1 && dp[i + 1][0] != -1) {
                Update(i, 1, dp[i + 1][0] + (v + 1) * (GetCnt(i) + 1) + (i == cnt - 2 ? -1 : 0));
            }
        }
        
        //for (int i = 0; i < cnt; i++) printf("%d %d\n", dp[i][0], dp[i][1]);
        
        return dp[0][0];
    }
};
__________________________________________________________________________________________________
