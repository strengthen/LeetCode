__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1)
            return 0;
        int tmp = kthGrammar(N - 1, (K + 1) / 2);
        if(K & 1)
            return tmp;
        return 1 - tmp;
    }
};
__________________________________________________________________________________________________
sample 8336 kb submission
class Solution {
public:
    int kthGrammar(int N, int K) {
        //f(N, K) = 1  ==> f(N + 1, 2K-1) = 1, f(N + 1, 2K) = 0
        //f(N, K) = 0  ==> f(N + 1, 2K-1) = 0, f(N + 1, 2K) = 1
        if (N == 1) {
            return 0;
        }
        else {
            int d = kthGrammar(N-1, (K+1)/2);
            if (K % 2 == 0) {
                return 1-d;
            }
            else {
                return d;
            }
        }        
    }
};
__________________________________________________________________________________________________
