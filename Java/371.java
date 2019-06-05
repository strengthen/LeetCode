__________________________________________________________________________________________________
sample 31404 kb submission
class Solution {
    public int getSum(int a, int b) {
        return a + (b);
    }
}
__________________________________________________________________________________________________
sample 31436 kb submission
class Solution {
    public int getSum(int a, int b) {
        if(a == 0) return b;
        if(a == 0) return a;
        while(b!=0){
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
}
__________________________________________________________________________________________________
