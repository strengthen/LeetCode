__________________________________________________________________________________________________
sample 31480 kb submission
class Solution {
    public int bulbSwitch(int n) {
        int i = 1;
        int res = 0;
        while(i * i <= n) {
            res++;
            i++;
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 31500 kb submission
class Solution {
    public int bulbSwitch(int n) {
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            count++;
        }
        return count;
    }
}
__________________________________________________________________________________________________
