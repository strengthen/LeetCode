__________________________________________________________________________________________________
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int res = 0;
        for (int i = 0; i <= n / 4; ++i) {
            int cur = read4(buf + res);
            if (cur == 0) break;
            res += cur;
        }
        return min(res, n);
    }
};
__________________________________________________________________________________________________
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int t = read4(buf);
        if (t >= n) return n;
        if (t < 4) return t;
        return 4 + read(&buf[4], n - 4);
    }
};
__________________________________________________________________________________________________
