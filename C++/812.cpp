__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    double area(vector<int>& p1, vector<int>& p2, vector<int>& p3){
        double area = (double)abs(((double)p1[0]*((double)p2[1]-(double)p3[1]) +             (double)p2[0]*((double)p3[1]-(double)p1[1])+ (double)p3[0]*((double)p1[1] -         (double)p2[1]))/2);
        return area;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        size_t len = points.size();
        double max = 0;
        for (size_t i = 0; i < len; i++){
            for(size_t j = i + 1; j < len; j++){
                for(size_t k = j +1; k < len; k++){
                    //cout << area(points[i],points[j],points[k]) << endl;
                    if(area(points[i],points[j],points[k]) > max){
                        max = area(points[i],points[j],points[k]);
                 }
                
                }
            }
        }
        return max;
    }
};
__________________________________________________________________________________________________
sample 9100 kb submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points)
    {
        int n = points.size();
        double maxArea = 0;
        
        for (int p1 = 0; p1 < n; ++p1)
        {
            for (int p2 = p1 + 1; p2 < n; ++p2)
            {
                for (int p3 = p2 + 1; p3 < n; ++p3)
                {
                    double area = points[p1][0] * points[p2][1] +
                                  points[p2][0] * points[p3][1] +
                                  points[p3][0] * points[p1][1] -
                                  points[p1][0] * points[p3][1] -
                                  points[p2][0] * points[p1][1] -
                                  points[p3][0] * points[p2][1];
                    
                    maxArea = std::max(maxArea, std::abs(area) / 2.0);
                }
            }
        }
        
        return maxArea;        
    }
};
__________________________________________________________________________________________________
