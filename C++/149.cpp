__________________________________________________________________________________________________
4ms
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(empty(points))
            return 0;
        int n = points.size();
        if(n<3){
            if(n==2){
                return 2;
            }
            return 1;
        }
        vector<int>temp = points[0];
        int max = 2;
        for(int i = 1;i<points.size();i++){
            int count = 0;
            long x1 = temp[0];
            long y1 = temp[1];
            long x2 = points[i][0];
            long y2 = points[i][1];
            if(x1 == x2 && y1 == y2){
                for(int j = 0;j<points.size();j++){
                    if(x1 == points[j][0] && y1 == points[j][1]){
                        count++;
                    }
                }
            }else{
                for(int j = 0;j<points.size();j++){
                   long x3 = points[j][0];
                   long y3 = points[j][1];
                    if(((y3-y2)*(x2-x1))==((y2-y1)*(x3-x2))){
                        count++;
                    }
                    
                }
            }
            temp = points[i];
            max = std::max(max,count);
            
        }
        return max;
    }
};
__________________________________________________________________________________________________
8288 kb
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if(n < 3){
            return n;
        }
        int result = 0;
        for(int i = 0; i < n - 1; i++){
            int duplicate = 1;
            for(int j = i + 1; j < n; j++){
                int count = 0;
                long long x1 = points[i].x, x2 = points[j].x;
                long long y1 = points[i].y, y2 = points[j].y;
                
                if(x1 == x2 && y1 == y2){
                    duplicate++;
                    continue;
                }
                
                for(int k = 0; k < n; k++){
                    long long x3 = points[k].x, y3 = points[k].y;
                    if(x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3 == 0){
                        count++;
                    }
                }
                result = max(result, count);
            }
            result = max(result, duplicate);
        }
        return result;
    }
};
__________________________________________________________________________________________________
