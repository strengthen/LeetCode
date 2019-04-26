__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> edge12 = p2, edge13 = p3, edge14 = p4;
        vector<vector<int>> have2compare(4,{0,0}), temp;
        if(p1 == p2 && p3 == p2 && p4 == p3) return false;
        
        for(int i=0; i<2; i++){
            edge12[i] -= p1[i];
            edge13[i] -= p1[i];
            edge14[i] -= p1[i];
        }
        if((edge12[0]*edge13[0] + edge12[1]*edge13[1]) == 0){
            temp.push_back(p2);
            temp.push_back(p3);
            temp.push_back(p1);
            temp.push_back(p4);
        }
        else if((edge12[0]*edge14[0] + edge12[1]*edge14[1]) == 0){
            temp.push_back(p2);
            temp.push_back(p4);
            temp.push_back(p1);
            temp.push_back(p3);
        }
        else if((edge13[0]*edge14[0] + edge13[1]*edge14[1]) == 0){
            temp.push_back(p4);
            temp.push_back(p3);
            temp.push_back(p1);
            temp.push_back(p2);
        }
        else return false;
        
        for(int i=0; i<2; i++){
            have2compare[0][i] = temp[2][i] - temp[0][i];
            have2compare[1][i] = temp[3][i] - temp[0][i];
            have2compare[2][i] = temp[2][i] - temp[1][i];
            have2compare[3][i] = temp[3][i] - temp[1][i];
        }
        if((pow(have2compare[0][0],2) + pow(have2compare[0][1],2)) != (pow(have2compare[1][0],2) + pow(have2compare[1][1],2))) return false;
        
        if((have2compare[0][0]*have2compare[1][0] + have2compare[0][1]*have2compare[1][1]) == 0){
            if((have2compare[2][0]*have2compare[3][0] + have2compare[2][1]*have2compare[3][1]) == 0) return true;
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 9612 kb submission
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int squareOfDistanceA = (p1[0]-p2[0]) * (p1[0]-p2[0]) + (p1[1]-p2[1]) * (p1[1]-p2[1]);
        int squareOfDistanceB = (p1[0]-p3[0]) * (p1[0]-p3[0]) + (p1[1]-p3[1]) * (p1[1]-p3[1]);
        int squareOfDistanceC = (p1[0]-p4[0]) * (p1[0]-p4[0]) + (p1[1]-p4[1]) * (p1[1]-p4[1]);
        if(!isRectangle(p1,p2,p3,p4)) return false;
        
        if(squareOfDistanceA!= 0 && squareOfDistanceB != 0 && squareOfDistanceC != 0 &&((squareOfDistanceA == squareOfDistanceB && squareOfDistanceA + squareOfDistanceB == squareOfDistanceC)
          || (squareOfDistanceA == squareOfDistanceC && squareOfDistanceA + squareOfDistanceC == squareOfDistanceB)
          || (squareOfDistanceB == squareOfDistanceC && squareOfDistanceB + squareOfDistanceC == squareOfDistanceA))) {
            return true;
        }
        
        return false;
        
    }
    
    bool isRectangle(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return (meetPythagorean(p1,p2,p3) && meetPythagorean(p4,p2,p3)) 
            || (meetPythagorean(p1,p3,p4) && meetPythagorean(p2,p3,p4))
            || (meetPythagorean(p1,p2,p4) && meetPythagorean(p3,p2,p4))
            || (meetPythagorean(p2,p1,p4) && meetPythagorean(p3,p1,p4))
            || (meetPythagorean(p2,p1,p3) && meetPythagorean(p4,p1,p3))
            || (meetPythagorean(p3,p1,p2) && meetPythagorean(p4,p1,p2));
    }
    bool meetPythagorean(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
        return (p1[0]-p2[0]) * (p1[0]-p2[0]) + (p1[1]-p2[1]) * (p1[1]-p2[1])
            + (p1[0]-p3[0]) * (p1[0]-p3[0]) + (p1[1]-p3[1]) * (p1[1]-p3[1]) 
            == (p2[0]-p3[0]) * (p2[0]-p3[0]) + (p2[1]-p3[1]) * (p2[1]-p3[1]);
    }
};
__________________________________________________________________________________________________
