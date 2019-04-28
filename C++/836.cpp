__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x11 = rec2[0], y11 = rec2[1], x22 = rec2[2], y22 = rec2[3];
        if(x11 >= x2 || x1 >= x22) return false;
        if(y11 >= y2 || y1 >= y22) return false;
        return true;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec1[0] < rec2[2] && rec2[0] < rec1[2] && rec1[1] < rec2[3] && rec2[1] < rec1[3];     
    }
};
__________________________________________________________________________________________________
sample 8176 kb submission
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
         return !(rec1[2] <= rec2[0] ||   
                 rec1[3] <= rec2[1] ||  
                 rec1[0] >= rec2[2] ||   
                 rec1[1] >= rec2[3]);    
    }
};