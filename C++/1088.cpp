__________________________________________________________________________________________________
class Solution {
public:
    int f[10] = {0, 1, 0, 0, 0, 0, 9, 0, 8, 6};
    int N, len, ans = 0;
    int bit[5] = {0, 1, 6, 8, 9};
    int a[20];
    int check(int x, int m){
        int l = 0;
        while(l < m && a[l] == 0) ++l;
        if(l == m) return 0;
        for(int i = l; i <= l + (m - l) / 2; ++i){
            if(f[a[i]] != a[m - 1 - (i - l)]){
                return 1;
            }
        }
        return 0;
    }
    void go(long long x, int m){
        if(x > N) return ;
        if(m > len){
            ans += check(x, m);
            return ;
        }
        for(int i = 0; i < 5; ++i){
            a[m] = bit[i];
            go(x * 10 + bit[i], m + 1);
        }
    }
    int confusingNumberII(int nn) {
        N = nn;
        for(; nn; nn /= 10) ++len;
        go(0, 0);
        return ans;
    }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
