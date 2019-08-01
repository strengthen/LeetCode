__________________________________________________________________________________________________
sample 0 ms submission
public class Solution {
    public boolean judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; i++) {
            int count = 0;
            if (c % i == 0) {
                while (c % i == 0) {
                    count++;
                    c /= i;
                }
                if (i % 4 == 3 && count % 2 != 0)
                    return false;
            }
        }
        return c % 4 != 3;
    }
}
__________________________________________________________________________________________________
sample 31644 kb submission
class Solution {
    public boolean judgeSquareSum(int c) {
        int l = 0, r = (int)Math.sqrt(c);
        while(l <= r){
            int num = l * l + r * r;
            if(num == c){
                return true;
            }
            if(num < c){
                l = l + 1;
            }else{
                r = r - 1;
            }
        }
        return false;
    }
}
__________________________________________________________________________________________________
