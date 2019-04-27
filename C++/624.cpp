__________________________________________________________________________________________________
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int, int>> mx, mn;
        for (int i = 0; i < arrays.size(); ++i) {
            mn.push({-arrays[i][0], i});
            mx.push({arrays[i].back(), i});
        }
        auto a1 = mx.top(); mx.pop();
        auto b1 = mn.top(); mn.pop();
        if (a1.second != b1.second) return a1.first + b1.first;
        return max(a1.first + mn.top().first, mx.top().first + b1.first);
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, start = arrays[0][0], end = arrays[0].back();
        for (int i = 1; i < arrays.size(); ++i) {
            res = max(res, max(abs(arrays[i].back() - start), abs(end - arrays[i][0])));
            start = min(start, arrays[i][0]);
            end = max(end, arrays[i].back());
        }
        return res;
    }
};
__________________________________________________________________________________________________
