__________________________________________________________________________________________________
class Solution {
public:
    int smallestFactorization(int a) {
        if (a == 1) return 1;
        string res = "";
        for (int k = 9; k >= 2; --k) {
            while (a % k == 0) {
                res = to_string(k) + res;
                a /= k;
            }
        }
        if (a > 1) return 0;
        long long num = stoll(res);
        return num > INT_MAX ? 0 : num;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 10) return a;
        long long res = 0, cnt = 1;
        for (int i = 9; i >= 2; --i) {
            while (a % i == 0) {
                res += cnt * i;
                if (res > INT_MAX) return 0;
                a /= i;
                cnt *= 10;
            }
        }
        return (a == 1) ? res : 0;
    }
};
__________________________________________________________________________________________________
