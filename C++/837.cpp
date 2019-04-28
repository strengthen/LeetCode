__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    double new21Game(int N, int K, int W) {
        double ans = 0;
        vector<double> dp(N+1, 0.0);
        double sum = 1.0;   // sum is the running sum of probablity accumulated up to i-1
                            // of the last W numbers.
                            // dp[i] is probability reaching i, qhich is equal to probability
                            // reaching previous W numbers * 1/W. 
        if (K == 0)
            return 1.0;
        dp[0] = 1.0;
        
        for(int i = 1; i <= N; i++) {
            // dp[i] = probility of reaching last W numbers multilply with
            // probability of 1 of W number to get to i
            dp[i] = sum / W;
            if (i < K) {
                // if i less than stopping values, we accumulate, we stop accumulate
                // because once reaching K, we stop hence any number from K won't
                // add probability to reach K+1, K+2.
                sum = sum + dp[i];
            } else {
                ans += dp[i];
            }
            if (i - W >= 0) {
                // if i is bigger than W, we subtract those number that is beyond i-W because
                // from those number we can't reach i, hence remove its probability
                //cout << "subtrace " << sum << " with " << dp[i-W] << endl;
                sum = sum - dp[i-W];
            }
           // cout << i <<": " << sum << ", " << dp[i] << endl;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1.0;
        vector<double> dp(N + 1);
        dp[0] = 1.0;
        double wsum = 1.0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = wsum/W;
            if (i < K)
                wsum += dp[i];
            if (i >= W && i - W < K)
                wsum -= dp[i - W];
        }
        double res = 0.0;
        for (int i = K; i <= N; ++i)
            res += dp[i];
        return res;
    }
};
__________________________________________________________________________________________________
sample 9124 kb submission
class Solution {
public:
    const int M = 10020;
    double new21Game(int N, int K, int W) {
        double pro[M] = {0};
        pro[0] = 1;
        double ans = 0;
        for (int i = 0; i <= N; i++) {
            if (i < K) {
                for (int j = 1; j <= W; j++) {
                    if (i + j > N) {
                        break;
                    }
                    pro[i+j] += (double)pro[i] / W;
                }
            } else {
                ans += pro[i];
            }
        }
        return ans;
    }
};