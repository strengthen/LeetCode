__________________________________________________________________________________________________
sample 20 ms submission
auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> vec;
		priority_queue<pair<int, size_t>> q;	//高度降序，最大堆
		q.push({ 0, -1 });
		buildings.push_back({ -1, 0, 0 });
		for (auto &v : buildings) {
			for (size_t t; (t = q.top().second) < (size_t)v[0];) {
				while (q.top().second <= t) { q.pop(); }
				if (vec.back().second > q.top().first) { vec.push_back({ t, q.top().first }); }	//pq按照主次关键字排序
			}
			if (!vec.empty() && vec.back().first == v[0]) { vec.back().second = max(vec.back().second, v[2]); }
			else if (q.top().first < v[2]) { vec.push_back({ v[0], v[2] }); }
			q.push({ v[2], v[1] });
		}
		return vec;
	}
};
__________________________________________________________________________________________________
sample 13028 kb submission
class Solution {
private:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    }
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        set <pair<int, int>> keyPoint;
        int n = buildings.size();
        vector<pair<int, int>> result;
        for (int i = 0; i < n; i++){
            int leftPosition = buildings[i][0];
            int currentHeight = buildings[i][2];
            bool key = true;
            for (int j = 0; j < n; j++){
                if (j != i && buildings[j][0] <= leftPosition && buildings[j][1] >= leftPosition){
                    if (buildings[j][2] > currentHeight || buildings[j][2] == currentHeight && buildings[j][0] < leftPosition)
                    key = false;                   
                }
            }
            if (key)
               keyPoint.insert(make_pair(leftPosition, currentHeight));
            int rightPosition = buildings[i][1];
            key =true;
            int maxLowerHeight = 0;
            for (int j = 0; j < n; j++){
                if (j != i && buildings[j][0] <= rightPosition && buildings[j][1] >= rightPosition){
                    if (buildings[j][2] > currentHeight || buildings[j][2] == currentHeight && buildings[j][1] > rightPosition)
                        key =false;
                    else if (buildings[j][1] > rightPosition && buildings[j][2] < currentHeight && buildings[j][2] > maxLowerHeight)
                        maxLowerHeight = buildings[j][2];
                }
            }
            if (key)
                keyPoint.insert(make_pair(rightPosition, maxLowerHeight));
        }
        for (auto iter = keyPoint.begin(); iter != keyPoint.end(); iter++)
            result.push_back(*iter);
        return result;
    }
};
__________________________________________________________________________________________________
