__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points1) {
        vector<pair<int, int>> points;
        set<pair<int, int>> pointsSet;
        points.reserve(points1.size());
        for (const auto& p : points1) {
            auto pp = make_pair(p[0], p[1]);
            points.push_back(pp);
            pointsSet.insert(pp);
        }
        
        int best = INT_MAX;
        
        for (int i = 2; i < points.size(); ++i) {
            auto p1 = points[i];
            for (int j = 1; j < i; ++j) {
                auto p2 = points[j];
                for (int k = 0; k < j; ++k) {
                    auto p3 = points[k];
                    auto x1 = p2.first - p1.first;
                    auto y1 = p2.second - p1.second;
                    auto x2 = p3.first - p1.first;
                    auto y2 = p3.second - p1.second;
                    
                    if (x1*x2 + y1*y2 != 0) continue;
                    
                    auto p4 = make_pair(p2.first + x2, p2.second + y2);
                    
                    if (pointsSet.find(p4) == pointsSet.end()) continue;
                    
                    auto area = abs(x1*y2 - x2*y1);
                    if (area > 0 && area < best) best = area;
                }
            }
        }
        
        return best == INT_MAX ? 0 : best;
    }
};
__________________________________________________________________________________________________
sample 9960 kb submission
class Solution {
public:
  double minAreaFreeRect(vector<vector<int>>& points) {
    int n = points.size();
    bool find = false;
    double ans = INT_MAX;
    vector<vector<int>>& P = points;
    for(int a = 0; a < n; ++a)
      for(int b = 0; b < n; ++b)
        for(int c = 0; c < n; ++c)
          for(int d = 0; d < n; ++d) {
            if(a == b || a == c || a == d || b == c || b == d || c == d) continue;
            if(P[a][0] - P[b][0] != P[d][0] - P[c][0]) continue;
            // Deal with the parallel sides
            if(P[a][1] - P[b][1] != P[d][1] - P[c][1]) continue;
            
            double x1 = P[a][0] - P[b][0];
            double x2 = P[c][0] - P[b][0];
            double y1 = P[a][1] - P[b][1];
            double y2 = P[c][1] - P[b][1];
            
            if (x1 * x2 + y1 * y2 == 0) {
              double area = abs(x1 * y2 - x2 * y1);
              if (area > 0 && area < ans) {
                find = true;
                ans = area;
                // ans = min(ans, area);
              }
            }
          }
    if (!find) return 0;
    return ans;
  }
};
__________________________________________________________________________________________________
