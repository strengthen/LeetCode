__________________________________________________________________________________________________
Runtime: 0 ms
Memory Usage: 34.1 MB
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return(!(rec1[2]<=rec2[0]||rec1[3]<=rec2[1]||rec2[2]<=rec1[0]||rec2[3]<=rec1[1]));
    }
}
__________________________________________________________________________________________________
sample 35244 kb submission
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int rec1PointX1 = rec1[0];
        int rec1PointY1 = rec1[1];
        int rec1PointX2 = rec1[2];
        int rec1PointY2 = rec1[3];
        
        int rec2PointX1 = rec2[0];
        int rec2PointY1 = rec2[1];
        int rec2PointX2 = rec2[2];
        int rec2PointY2 = rec2[3];
        
        boolean checkX1OnRec2X = betweenTwoPoints(rec1PointX1, rec2PointX1, rec2PointX2);
        boolean checkX2OnRec2X = betweenTwoPoints(rec1PointX2, rec2PointX1, rec2PointX2);        
        boolean checkY1OnRec2Y = betweenTwoPoints(rec1PointY1, rec2PointY1, rec2PointY2);
        boolean checkY2OnRec2Y = betweenTwoPoints(rec1PointY2, rec2PointY1, rec2PointY2);
        
        boolean checkX1OnRec1X = betweenTwoPoints(rec2PointX1, rec1PointX1, rec1PointX2);
        boolean checkX2OnRec1X = betweenTwoPoints(rec2PointX2, rec1PointX1, rec1PointX2);
        boolean checkY1OnRec1X = betweenTwoPoints(rec2PointY1, rec1PointY1, rec1PointY2);
        boolean checkY2OnRec1X = betweenTwoPoints(rec2PointY2, rec1PointY1, rec1PointY2);
        
        System.out.println(checkX1OnRec2X + " " + checkX2OnRec2X + " " + checkY1OnRec2Y + " " + checkY2OnRec2Y + " " + checkX1OnRec1X 
                          + " " + checkX2OnRec1X + " " + checkY1OnRec1X + " " + checkY2OnRec1X);
        
        return     checkX1OnRec2X && checkY1OnRec2Y 
                || checkX1OnRec2X && checkY2OnRec2Y
                || checkX1OnRec2X && checkY1OnRec1X
                || checkX1OnRec2X && checkY2OnRec1X
            
                || checkX2OnRec2X && checkY1OnRec2Y
                || checkX2OnRec2X && checkY2OnRec2Y
                || checkX2OnRec2X && checkY1OnRec1X
                || checkX2OnRec2X && checkY2OnRec1X
            
                || checkX1OnRec1X && checkY1OnRec2Y
                || checkX1OnRec1X && checkY2OnRec2Y
                || checkX1OnRec1X && checkY1OnRec1X
                || checkX1OnRec1X && checkY2OnRec1X
            
                || checkX2OnRec1X && checkY1OnRec2Y
                || checkX2OnRec1X && checkY2OnRec2Y
                || checkX2OnRec1X && checkY1OnRec1X
                || checkX2OnRec1X && checkY2OnRec1X;                 
    }
        
    public boolean betweenTwoPoints(int one, int two, int three)
    {
        return (two < one && one < three);
    }
}
__________________________________________________________________________________________________
sample 35256 kb submission
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return isOverlap(rec1[0],rec1[2],rec2[0],rec2[2]) && isOverlap(rec1[1],rec1[3],rec2[1],rec2[3]);
    }
    private boolean isOverlap (int x1, int x2 , int x3, int x4){
        if ((x4 > x1 && x3< x1) || (x2> x3 && x2 < x4) || (x1 >= x3 && x2 <= x4 ) || (x1<= x3 && x2 >=x4)) return true;
        return false;
    }
}