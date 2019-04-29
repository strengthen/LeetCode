__________________________________________________________________________________________________
× Close
sample 4 ms submission
class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string ret;
        int base = -2; // Be more general
        while (n) {
            ret = to_string(abs(n % base)) + ret;
            if (n % base != 0 && n < 0) {
                n += n % base;
            }
            n /= base;
        }
        return ret;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    string baseNeg2(int N, string res = "") {
  while (N != 0) {
    int rem = N % -2;
    N /= -2;
    if (rem < 0) rem += 2, N += 1;
    res = to_string(rem) + res;
  }
  return max(string("0"), res);
}
};
__________________________________________________________________________________________________
