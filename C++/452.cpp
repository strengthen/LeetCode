__________________________________________________________________________________________________
sample 52 ms submission
class Solution {
public:
	int findMinArrowShots(vector<pair<int, int>>& points)
	{
		if (points.size() < 2)
			return points.size();

		std::sort(points.begin(), points.end(),
			[](const pair<int, int> & point1, const pair<int, int> & point2)
			{
				return point1.first < point2.first;
			});


		int last_arrow_x = points[0].second;
		int arrow_count = 1;
		for (int k = 1; k < points.size(); ++k)
		{
			// last arrow hits this one
			if (points[k].first <= last_arrow_x)
				last_arrow_x = std::min(last_arrow_x, points[k].second);
			else
			{
				++arrow_count;
				last_arrow_x = points[k].second;
			}
		}

		return arrow_count;
	}
};

static int fastio = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
sample 17388 kb submission
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](pair<int,int>& p1, pair<int,int>& p2) {
           return p1.first < p2.first; 
        });
        
        pair<int,int> current = points[0];
        int minArrows = 1;
        int n = points.size();
        for (int i=1; i<n; ++i) {
            if (points[i].first <= current.second) {
                // overlap
                current = { points[i].first, min(current.second, points[i].second) };
            } else {
                ++minArrows;
                current = points[i];
            }
        }
        return minArrows;
    }
};
__________________________________________________________________________________________________
