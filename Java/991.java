__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int brokenCalc(int X, int Y) {
     if (X > Y){
         return X - Y; 
     }
    if ((X + 1)*2 == Y || (X-1)*2 == Y){
            return 2;
    } 
    int count =0;
    while (Y > X ){
        if (Y % 2 == 1){
            Y++;
        } else{
        Y /=2;
        }
        count++;
    }
        return count+X-Y;
    }
}
__________________________________________________________________________________________________
sample 31648 kb submission
class Solution {
    public int brokenCalc(int X, int Y) {
        int res = 0;
        while (Y > X) {
            Y = Y % 2 > 0 ? Y + 1 : Y / 2;
            res++;
        }
        return res + X - Y;
    }
}
__________________________________________________________________________________________________
