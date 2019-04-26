__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if ((x & (1 << i)) ^ (y & (1 << i))) {
                ++res;
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 8200 kb submission
static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int hamming = x^y;
        int counter=0;
        while(hamming){
            counter+=(hamming&1);
            hamming>>=1;
        }
        return counter;
    }
};
__________________________________________________________________________________________________
