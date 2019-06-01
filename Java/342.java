__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean isPowerOfFour(int n) {
         return n > 0 && ((n & (n-1)) == 0) && (n &  0x55555555) != 0;
    }
}
__________________________________________________________________________________________________
sample 31988 kb submission
class Solution {
    public boolean isPowerOfFour(int num) {
        if(num<1)
            return false;
        while(num%4==0){
            num /= 4;
        }
        return num==1;
    }
}
__________________________________________________________________________________________________
