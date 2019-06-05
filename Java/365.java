__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(x + y < z) return false;
        //case x or y is zero
        if( x == z || y == z || x + y == z ) return true;

        //get GCD, then we can use the property of Bézout's identity
        return z%GCD(x, y) == 0;
    }
    
    public int GCD(int a, int b){
        while(b != 0 ){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
}
__________________________________________________________________________________________________
sample 31456 kb submission
class Solution {
public boolean canMeasureWater(int x, int y, int z) {
if (z > x + y) return false;
if (z == x || z == y) return true;

    int a = Math.max(x,y);
    int b = Math.min(x,y);
    int gcd = findGcd(a,b);
    System.out.println(gcd);
    return ((y!= 0)  && z % y == 0) || ((x != 0) && z % x == 0) || ((x!= 0 && y != 0 && z % gcd == 0));
}

public static int findGcd(int a, int b){
    if (a == b) return a;
    int gcd = 1;
    for (int i = 2; i <= b; i++){
        while (a % i == 0 && b % i == 0){
            gcd *= i;
            a /= i;
            b /= i;
        }
    }
    return gcd;
}
}
__________________________________________________________________________________________________
