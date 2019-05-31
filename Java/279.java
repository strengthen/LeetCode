__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int numSquares(int n) {
        if(is_sqrt(n))
            return 1;
        while(n%4==0) {
            n/=4;
        }
        if(n%8==7)
            return 4;
        for(int i=0;i*i<n;i++) {
            if(is_sqrt(n-i*i))
                return 2;
        }
        return 3;
    }
    
    public static boolean is_sqrt(int n) {
        int m = (int)Math.sqrt(n);
        if (m*m == n)
            return true;
        else
            return false;
    }
}
__________________________________________________________________________________________________
sample 32024 kb submission
class Solution {
    public int numSquares(int n) {
        while ( n%4 == 0 )
            n/=4;
        if ( ((int)Math.sqrt(n))*((int)Math.sqrt(n)) == n )
            return 1;
        if ( n%8 == 7 )
            return 4;
        for ( int i = 1; i*i < n; i++ ){
            int x = n-i*i;
            if ( ((int)Math.sqrt(x))*((int)Math.sqrt(x)) == x )
                return 2;
        }
        return 3;
    }
}
__________________________________________________________________________________________________
