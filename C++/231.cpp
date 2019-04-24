__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool isPowerOfTwo(int n) {
        std::int64_t c = 1;
        while (c <= n) {
            if (c == n)
                return true;
            c <<= 1;
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 7804 kb submission
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
__________________________________________________________________________________________________
