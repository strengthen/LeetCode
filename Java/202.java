__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean isHappy(int n) {
        if (n < 10){
            if (n == 1 || n == 7) return true;
            else return false;
        }else{
            double y = 0;
            while (n > 0){
                y += Math.pow(n%10,2);
                n /= 10;
            }
            return isHappy((int)y);
        }
    }
}
__________________________________________________________________________________________________
sample 31804 kb submission
class Solution {
    public boolean isHappy(int n) {
        while (n >= 10) {
            int sum = 0;
            while (n > 0) {
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = sum;
        }
        return n == 1 || n == 7;
    }
}
__________________________________________________________________________________________________
