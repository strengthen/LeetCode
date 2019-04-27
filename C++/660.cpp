__________________________________________________________________________________________________
class Solution {
public:
   int newInteger(int n) {
        int res = 0, base = 1;
        while (n > 0) {
            res += n % 9 * base;
            n /= 9;
            base *= 10;
        }
        return res;
   }
};
__________________________________________________________________________________________________
class Solution {
public:
   int newInteger(int n) {
        string res = "";
        while (n > 0) {
            res = to_string(n % 9) + res;
            n /= 9;
        }
        return stoi(res);
   }
};
__________________________________________________________________________________________________
class Solution {
public:
    int newInteger(int n) {
        long d = 9, pre = 0, cur = 0;
        while (true) {
            pre = cur;
            cur = helper(n + cur, d);
            if (cur == pre) break;
        }
        return n + cur;
    }
    long helper(long m, long d) {
        long res = 0, p = 1, q = 1;
        for (long i = m; i >= 10; i /= 10) {
            p *= 10;
            q *= 9;
        }
        for (long i = m; i >= d; i %= p, p /= 10, q /= 9) {
            long a = i / p;
            res += a * (p - q);
            if (a == d) {
                res += i % p + 1; break;
            } else if (a > d) {
                res += q;
            }
        }
        return res;
    }
};