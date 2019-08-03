__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) {
            return -1;
        }
        int n = 1;
        int count = 1;
        while (n % K != 0) {
            n = n * 10 + 1;
            n = n % K;
            count++;
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 31556 kb submission
class Solution {
    public int smallestRepunitDivByK(int K) {
       //if (K % 2 == 0 || K % 5 == 0) return -1;
        int r = 0;
        for (int N = 1; N <= K; ++N) {
            r = (r * 10 + 1) % K;
            if (r == 0) return N;
        }
        return -1; 
    }
}
__________________________________________________________________________________________________
