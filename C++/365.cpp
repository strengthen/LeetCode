__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        
        return z == 0 || (x+y >= z && z % gcd(x,y) == 0);
        
    }
    
    int gcd(int x, int y){
        return y == 0 ? x : gcd(y, x % y);
    }
};
__________________________________________________________________________________________________
sample 7848 kb submission
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        int a=__gcd(x,y);
        if (z>x+y) return false;
        if (a==0){
if (z==0 or z==std::max(x,y)) 
        return true;
else return false;} 
        else{
        if (z%a==0)
            return true;
        else return false;}
    }
};
__________________________________________________________________________________________________
