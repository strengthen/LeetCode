__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        vector<int> dp(101, 101);
        dp[0] = 0;
        for (auto& c : clips)
            for (int i = c[0] + 1; i <= c[1]; i++)
                dp[i] = min(dp[i], dp[c[0]] + 1);
        return dp[T] > 100 ? -1 : dp[T];
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int cur = 0;
        int ret = 0;
        while (cur < T) {
            vector<int> best;
            for (auto d : clips) {
                if (d[0] > cur || d[1] <= cur) continue;
                if (best.empty() || best[1] < d[1]) {
                    best = d;
                }
            }
            if (best.empty()) break;
            cur = best[1];
            ret++;
        }
        if (cur < T) return -1;
        return ret;
    }
};
__________________________________________________________________________________________________
