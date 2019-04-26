__________________________________________________________________________________________________
sample 128 ms submission
static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();
class Solution {
    private:
        double _radius, _x_center, _y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        _radius = radius; _x_center = x_center;  _y_center = y_center;        
    }
    
    vector<double> randPoint() {
        double r = sqrt((double)rand()/RAND_MAX)*_radius;
        double angle = (double)rand()/RAND_MAX*M_PI*2;
        return {_x_center + r*cos(angle), _y_center + r*sin(angle)};
    }
};
__________________________________________________________________________________________________
sample 27196 kb submission
class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        xc = x_center;
        yc = y_center;
    }
    
    vector<double> randPoint() {
        while(true) {
            double x = (2* (double)rand()/RAND_MAX - 1.0)*r;
            double y = (2* (double)rand()/RAND_MAX - 1.0)*r;
            if(x*x + y*y <= r*r) return {xc+x, yc+y};
        }
    }
    
private:
    double r, xc, yc;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
__________________________________________________________________________________________________
