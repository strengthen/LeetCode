__________________________________________________________________________________________________
sample 4 ms submission

class Solution {
public:
    int findIntegers(int n) {
        vector<int> f(32);
        f[0] = 1;
        f[1] = 2;
        for (int j = 2; j < 32; ++j)
            f[j] = f[j-1] + f[j-2];
        
        vector<int> d;
        ++n;
        while (n) {
            d.push_back(n&1);
            n >>= 1;
        }
        
        int ans = 0;
        for (int i = d.size()-1; i >= 0; --i)
            if (d[i] == 1) {
                ans += f[i];
                if (i+1 < d.size() && d[i+1] == 1)
                    break;
            }
                
        return ans;
    }
};
__________________________________________________________________________________________________
sample 11084 kb submission
class Solution {
public:
    int findIntegers(int num) {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i)
            f[i] = f[i-1]+f[i-2];
        int ans = 0, k = 30, pre_bit = 0;
        while (k >= 0) {
            if (num&(1<<k)) {
                ans += f[k];
                if (pre_bit) return ans;
                pre_bit = 1;
            } else
                pre_bit = 0;
            --k;
        }
        return ans+1;
    }
};
__________________________________________________________________________________________________
