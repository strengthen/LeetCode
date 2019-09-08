__________________________________________________________________________________________________
sample 92 ms submission
constexpr int INF = 1000000000;
class Solution {
public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    sort(arr2.begin(), arr2.end());
    arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
    const int n = arr1.size();
    const int m = arr2.size();
    vector<int> best(m);
    vector<int> f(m);
    int f_keep = 0;
    for (int i = 0; i < m; ++ i) {
      f[i] = best[i] = 1;
    }
    for (int i = 1; i < n; ++ i) {
      // cout << i << endl;
      f[0] = (arr2[0] > arr1[i - 1]) ? (f_keep + 1) : INF;
      for (int j = 1; j < m; ++ j) {
        f[j] = best[j - 1] + 1;
        if (arr2[j] > arr1[i - 1]) {
          f[j] = min(f[j], f_keep + 1);
        }
      }

      f_keep = (arr1[i] > arr1[i - 1]) ? f_keep : INF;

      for (int j = 0; j < m; ++ j) {
        if (arr2[j] < arr1[i]) {
          f_keep = min(f_keep, best[j]);
        } else break;
      }
      /*
      cout << "keep: " << f_keep << endl;
      for (int j = 0; j < m; ++ j) {
        cout << "to " << j << "(" << arr2[j] << "): " << f[j] << endl;
      }
      */
      best[0] = f[0];
      for (int j = 1; j < m; ++ j) {
        best[j] = min(best[j - 1], f[j]);
      }
    }
    int ans = min(f_keep, best[m - 1]);
    return ans >= INF ? -1 : ans;
  }
};
__________________________________________________________________________________________________
sample 100 ms submission
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        vector<int> arr3;
        for (int i=0; i<arr2.size(); ++i) {
            if (arr3.empty() || arr2[i]!=arr3[arr3.size()-1]) {
                arr3.push_back(arr2[i]);
            }   
        }   
        int sz1 = arr1.size(), sz3 = arr3.size(), inf = 1000000;
        vector<vector<int>> dp(sz1, vector<int>(sz3+1, inf));

        for (int i=0; i<sz3; ++i) { dp[0][i] = 1; }
        dp[0][sz3] = 0;

        for (int i=1; i<sz1; ++i) {
            int mn = inf;
            for (int j=0; j<sz3; ++j) {
                if (arr3[j] > arr1[i-1]) { mn = min(mn, dp[i-1][sz3]); }
                dp[i][j] = mn + 1;
                mn = min(mn, dp[i-1][j]);
            }   
            for (int j=0; j<sz3 && arr3[j]<arr1[i]; ++j) {
                dp[i][sz3] = min(dp[i][sz3], dp[i-1][j]);
            }   
            if (arr1[i] > arr1[i-1]) {
                dp[i][sz3] = min(dp[i][sz3], dp[i-1][sz3]);
            }   
        }   

        int mn = inf;
        for (int i=0; i<=sz3; ++i) { mn = min(mn, dp[sz1-1][i]); }
        if (mn >= inf) { mn = -1; }
        return mn; 
    }   
};
__________________________________________________________________________________________________
