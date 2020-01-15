__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cs) {
        if (cs.size() == 2) return true;
        int x = cs[0][0];
        int y = cs[0][1];
        int n = cs[1][0] - x;
        int d = cs[1][1] - y;
        
        for (int i = 2; i < cs.size(); ++i) {
            int curX = cs[i][0] - x;
            int curY = cs[i][1] - y;
            if (curX * d != curY * n) return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size = coordinates.size();
        if(size <= 2) return true;
        int x0 = coordinates[0][0] - coordinates[1][0];
        int y0 = coordinates[0][1] - coordinates[1][1];
        for(int i=2; i<size; ++i){
            int x = coordinates[i][0] - coordinates[1][0];
            int y = coordinates[i][1] - coordinates[1][1];
            if(x0*y - y0*x != 0) return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& A) {
         int n=A.size();
         double initial=100000.0;
         for(int i=1;i<n;i++)
         {
             int x = A[i][0]-A[i-1][0];
             int y =A[i][1]- A[i-1][1];
             if(y==0)
             {
                 initial=100000.0;
                 continue;
             }
             double slope = (double) x/y;
             if(initial==100000.0)
                 initial=slope;
             else if(initial!=slope)
                 return false;
         }
        return true;
        
    }
};