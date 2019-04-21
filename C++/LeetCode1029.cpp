__________________________________________________________________________________________________
4ms
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // sort in asending order of A - B
        vector<pair<int, int>> indices;
        int n = costs.size();
        for (int i = 0; i < n; i++)
            indices.emplace_back(costs[i][0] - costs[i][1], i);
        sort(indices.begin(), indices.end());
        int ans = 0;
        for (int i = 0; i < n / 2; i++)
            ans += costs[indices[i].second][0];
        for (int i = n / 2; i < n; i++)
            ans += costs[indices[i].second][1];
        return ans;
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    const int N = costs.size() >> 1;
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
      return abs(a[0] - a[1]) > abs(b[0] - b[1]);
    });
    int ans = 0;
    int a = 0, b = 0;
    for (const auto& c : costs) {
      if (c[0] < c[1]) {
        if (a < N) {
          ++ a;
          ans += c[0];
        } else {
          ++ b;
          ans += c[1];
        }
      } else {
        if (b < N) {
          ++ b;
          ans += c[1];
        } else {
          ++ a;
          ans += c[0];
        }
      }
    }
    return ans;
  }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int, int>> ps;
        int i = 0;
        for(vector<int> & ab : costs) {
            ps.emplace_back(ab[0] - ab[1], i++);
        }
        sort(ps.begin(), ps.end());
        int ans = 0, n = costs.size() / 2;
        for(int i = 0; i < ps.size(); ++i) {
            if (i < n) {
                ans += costs[ps[i].second][0];
            } else {
                ans += costs[ps[i].second][1];
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& cs, int res = 0) {
        sort(begin(cs), end(cs), [](vector<int> &v1, vector<int> &v2) {
            return (v1[0] - v1[1] < v2[0] - v2[1]);
        });
        for (auto i = 0; i < cs.size(); ++i) {
            res += i < cs.size() / 2 ? cs[i][0] : cs[i][1];
        }
        return res;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________