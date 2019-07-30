__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (dp[n]) return dp[n];
        int sum = tribonacci(n-1) + tribonacci(n - 2) + tribonacci(n - 3);
        dp[n] = sum;
        return dp[n];
    }
private: 
    int dp[100];
};
__________________________________________________________________________________________________
Runtime: 4 ms
Memory Usage: 8.1 MB
class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) return n;
        int a = 0, b = 1, c = 1, d = a + b + c;
        while (n-- > 2) {
            d = a + b + c, a = b, b = c, c = d;
        }
        return c;
    }
};
__________________________________________________________________________________________________
