__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int n = 0;
        for(int i=1; i<=K; i++){            
            n = (n*10+1) % K;
            if(n==0)
                return i;
        }
        
        return -1;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int len = 1, rem = 1 % K;
        while(len < 2 * K) {
            if (!rem) return len;
            ++len;
            rem = (rem * 10 + 1) % K;
        }
        return -1;
    }
};
__________________________________________________________________________________________________
