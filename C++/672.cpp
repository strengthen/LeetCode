__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int flipLights(int n, int m) {
        static const int t[4][4] = {
            {},
            {1, 2, 2, 2},
            {1, 3, 4, 4},
            {1, 4, 7, 8}
        };
        
        m = min(3, m);
        n = min(3, n);
        
        return t[n][m];
    }
};
__________________________________________________________________________________________________
sample 8440 kb submission
class Solution {
public:
    int flipLights(int n, int m) {
        if (m == 0 || n == 0) return 1;
        if (n == 1) return 2;
        if (n == 2) return m == 1? 3:4;
        if (m == 1) return 4;
        return m == 2? 7:8;
    }
};
__________________________________________________________________________________________________
