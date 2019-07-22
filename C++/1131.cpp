__________________________________________________________________________________________________
sample 36 ms submission
const int X[] = {-1, 1};
const int Y[] = {-1, 1};

class Solution {
public:
  int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
    const int n = arr1.size();
    int ans = 0;
    for (int i = 0; i < 2; ++ i) {
      int x = X[i];
      for (int j = 0; j < 2; ++ j) {
        int y = Y[j];
        int best = arr1[0] * x + arr2[0] * y;
        for (int k = 1; k < n; ++ k) {
          int cur = arr1[k] * x + arr2[k] * y + k;
          ans = max(ans, cur - best);
          best = min(best, cur);
        }
      }
    }
    return ans;
  }
};
__________________________________________________________________________________________________
const int INF = 1e9 + 5;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int best1 = -INF, best2 = -INF, best3 = -INF, best4 = -INF;
        int answer = -INF;

        for (int i = 0; i < n; i++) {
            answer = max(answer, best1 + arr1[i] + arr2[i] + i);
            answer = max(answer, best2 - arr1[i] + arr2[i] + i);
            answer = max(answer, best3 + arr1[i] - arr2[i] + i);
            answer = max(answer, best4 - arr1[i] - arr2[i] + i);

            best1 = max(best1, -arr1[i] - arr2[i] - i);
            best2 = max(best2, arr1[i] - arr2[i] - i);
            best3 = max(best3, -arr1[i] + arr2[i] - i);
            best4 = max(best4, arr1[i] + arr2[i] - i);
        }

        return answer;
    }
};

__________________________________________________________________________________________________
