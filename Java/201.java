__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        // int offset = 0;
        // while (n != m) {
        //     m >>= 1;
        //     n >>= 1;
        //     offset++;
        // }
        // return m << offset;
        
        
        while (n > m) {
            n &= (n-1);
        }
        return n;
    }
}
__________________________________________________________________________________________________
sample 33800 kb submission
class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        
        int count = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            count++;
        }
        
        return (m <<= count);
    }
}
__________________________________________________________________________________________________
