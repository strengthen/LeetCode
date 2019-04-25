__________________________________________________________________________________________________
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        unordered_map<int, set<int>> m;
        int mx = INT_MIN, mn = INT_MAX;
        for (auto a : points) {
            mx = max(mx, a.first);
            mn = min(mn, a.first);
            m[a.first].insert(a.second);
        }
        double y = (double)(mx + mn) / 2;
        for (auto a : points) {
            int t = 2 * y - a.first;
            if (!m.count(t) || !m[t].count(a.second)) {
                return false;
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty()) return true;
        set<pair<int, int>> pts;
        double y = 0;
        for (auto a : points) {
            pts.insert(a);
            y += a.first;
        }
        y /= points.size();
        for (auto a : pts) {
            if (!pts.count({y * 2 - a.first, a.second})) {
                return false;
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
