__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == INT_MAX)
            return 0;        
        for (int i = 1; ; ++i) {
            int k = (1 << i) - 1;
            if (k >= N)
                return k - N;
        }
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int bitwiseComplement(int N) {
        int X = 1;
        while (N > X) X = X * 2 + 1;
        return X - N;
    }
};
__________________________________________________________________________________________________
