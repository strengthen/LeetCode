__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public String baseNeg2(int N) {
        return Integer.toBinaryString(1431655765 ^ (1431655765 - N));
    }
}
__________________________________________________________________________________________________
sample 35560 kb submission
class Solution {
    public String baseNeg2(int N) {
        int num = 1;
        while (num < N) num = (num << 2) + 1;
        return Integer.toBinaryString(num ^ (num - N));
    }
}
__________________________________________________________________________________________________
