__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for(int i = 1; i < n; i++){
            int x = points[i][0], y = points[i][1];
            int px = points[i - 1][0], py = points[i - 1][1];
            res += min(abs(x - px), abs(y - py)) + abs(abs(x - px) - abs(y - py));
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for( int i=1;i<points.size();i++)
        {
            ans +=max(abs(points[i][0] - points[i-1][0]) ,abs(points[i][1] - points[i-1][1]) );
        }
        return ans;
    }
};
static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sum = 0;
        int idx = 0;
        while(idx < points.size()-1){
            vector<int> current = points.at(idx);
            int movex = points.at(idx+1)[0] - current[0];
            int movey = points.at(idx+1)[1] - current[1];
            sum += (abs(movex) > abs(movey)) ? abs(movex) : abs(movey);
        
            idx++;
        }
        return sum;
    }
};