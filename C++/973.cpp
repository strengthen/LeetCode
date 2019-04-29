__________________________________________________________________________________________________
sample 168 ms submission
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:   
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        std::ios::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL); 
        nth_element(begin(points), begin(points)+K, end(points), [](auto& v1, auto& v2){return v1[0]*v1[0]+v1[1]*v1[1] < v2[0]*v2[0]+v2[1]*v2[1];});
        points.resize(K);
        return points;
    }
};
__________________________________________________________________________________________________
sample 33016 kb submission
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        std::nth_element(points.begin(), points.begin()+ K, points.end(), 
                         [](vector<int>& v1, vector<int>& v2){
            return (v1[0] * v1[0]+ v1[1] * v1[1]) < (v2[0] * v2[0]+ v2[1] * v2[1]) ;
        });
        
        points.resize(K);
        return std::move(points);
    }
};
__________________________________________________________________________________________________
