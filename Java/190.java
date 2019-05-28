__________________________________________________________________________________________________
sample 1 ms submission
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        result += n & 1;
        // In Java: ">>>" to perform logical right shifts
        n >>>= 1;   // CATCH: must do unsigned shift
        if (i < 31) // CATCH: for last digit, don't shift!
        // logical and arithmetic left-shift operations are identical, there is no "<<<" operator in Java
            result <<= 1;
    }
    return result;
  }
}
__________________________________________________________________________________________________
sample 27552 kb submission
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int rev=0;
        for(int i=0;i<32;i++){
            rev= rev<<1 | n&1;
            n=n>>>1;
        }
        return rev;
    }
}
__________________________________________________________________________________________________
