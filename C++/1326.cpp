__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
public:
    vector < pair < int, int > > A;
    int minTaps(int n, vector<int>& arr) {
        n = arr.size();
        for(int i = 0;i < n;++i) {
            int st = max(0, i - arr[i]);
            int en = min(n-1, i + arr[i]);
            A.push_back({st, en});
        }
        sort(A.begin(), A.end(), [](pair < int, int > &a, pair < int, int > &b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        
        int e = 0, ma = 0, ans = 0;
        int idx = -1;
        for(int i = 0;i < n;++i) {
            if(A[i].first <= e) {
                if(A[i].second > ma) {
                    ma = A[i].second;
                    idx = i;
                }
            } else {
                if(idx == -1) {
                    return -1;
                }
                ++ans;
                e = ma;
                ma = 0;
                idx = -1;
                --i;
            }
        }
        
        if(e < n - 1) {
            if(idx == -1 or ma < n - 1) {
                return -1;
            }
            ++ans;
        }
        
        return ans;
    }
};
__________________________________________________________________________________________________
sample 28 ms submission
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        const int kInf = n + 100;
        vector<int> dp (n + 1, kInf);
        for(int i = 0; i < n + 1; ++i) {
            int left = max(0, i - ranges[i]);
            int best = (i - ranges[i] > 0) ? (dp[left] + 1) : 1;
            for(int j = i; j < min(i + ranges[i] + 1, n + 1); ++j) {
                dp[j] = min(dp[j], best);
            }
        }
        return dp.back() == kInf ? -1 : dp.back();
    }
};
__________________________________________________________________________________________________
