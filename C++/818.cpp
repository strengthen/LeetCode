__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int racecar(int target) {
        // pos[i] = 2^(i)-1
        // pos[i] - pos[i-1] = 2^(i) > pos[i-1]
        vector<int> dp(target * 2, -1);
        dp[0] = 0;
        return impl(target, dp);
    }

    static int impl(int target, vector<int>& dp) {
        assert(target < dp.size() && target >= 0);
        if (dp[target] > 0) {
            return dp[target];
        }

        int steps = log2(target + 1);
        int start = pow(2, steps) - 1;
        int ret = 0;
        if (start == target) {
            // nothing
        } else {
            assert(start < target);
            int end = pow(2, steps + 1) - 1;
            ret = impl(end - target, dp) + 2;  // AR
            for (int i = 0; i < steps; ++i) {
                auto tmp = impl(target - start + pow(2, i) - 1, dp) + 2 + i;  // RA...AR
                ret = min(ret, tmp);
            }
        }
        dp[target] = ret + steps;
        return dp[target];
    }
};
__________________________________________________________________________________________________
sample 8568 kb submission
constexpr int kMaxT = 10000;
int m[kMaxT + 1][2]={0};
 
class Solution {
public:
  int racecar(int target) {
    if (m[1][0] == 0) {
      for (int t = 1; t <= kMaxT; ++t) {
        const int n = ceil(log2(t + 1));
        if (1 << n == t + 1) {
          m[t][0] = n;
          m[t][1] = n + 1;
          continue;
        }
        const int l = (1 << n) - 1 - t;
        m[t][0] = n + 1 + min(m[l][1], m[l][0] + 1);
        m[t][1] = n + 1 + min(m[l][0], m[l][1] + 1);
        for (int i = 1; i < t; ++i) { 
          const int mi = min(m[i][0] + 2, m[i][1] + 1);
          m[t][0] = min(m[t][0], m[t - i][0] + mi);
          m[t][1] = min(m[t][1], m[t - i][1] + mi);
        }
      }
    } 
    return min(m[target][0], m[target][1]);
  }
};
__________________________________________________________________________________________________
