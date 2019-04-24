__________________________________________________________________________________________________
sample 7976 kb submission
class Solution {
public:
    int countDigitOne(int n) {
        long ones = 0;
        for (long m = 1; m <= n; m *= 10) {
        long a = n / m;
        long b = n % m;
        ones += (a + 8) / 10 * m + long((a % 10) == 1) * (b + 1);
    }
        return int(ones);
    }
};
__________________________________________________________________________________________________
sample 7992 kb submission
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long k = 1; k <= n; k *= 10) {
            long r = n / k, m = n % k;
            res += (r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0);
        }
        return res;
    }
};
__________________________________________________________________________________________________
