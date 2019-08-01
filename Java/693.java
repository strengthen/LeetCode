__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean hasAlternatingBits(int n) {
        int cur = n % 2; // Rightest bit
        n /= 2;          
        while (n > 0) {
            if (cur == n % 2) return false;
            cur = n % 2;
            n /= 2;
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 31820 kb submission
class Solution {
    public boolean hasAlternatingBits(int n) {
        if (n < 2) return true;
        int last = n % 2;
        while (n >= 1){
            n >>= 1;
            int tmp = (n%2) & 1;
            if (tmp == last)return false;
            last = tmp;
        }
        return true;
    }
}
__________________________________________________________________________________________________
