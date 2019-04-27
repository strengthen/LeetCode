__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        const int mask = 665772;
        int ans = 0;
        for(int i=L; i<=R; i++){
            if(mask & (1 << __builtin_popcountll(i))){
                ans++;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 8148 kb submission
static int speedup = [](){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution {
public:
    bool is_prime(int a){
        if(a == 2 || a == 3 || a == 5 || a == 7 || a == 11 || a == 13 || a == 17 || a == 19 || a == 23 || a == 29 || a == 31){
            return true;
        }
        return false;
    }
    
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for(int i = L; i <= R; i++){
            int c = __builtin_popcount(i);
            if(is_prime(c)){
                ans++;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
