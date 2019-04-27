__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int GetLess(int m, int n, int P)
    {
        int beg = P/ n;
        int   t = n * (beg);
        for(int i = beg + 1; i <= m; ++ i)
        {
          t += (P / i); 
        }
        return t;
    }
    int findKthNumber(int m, int n, int k) {
        if(m > n) swap(m, n);
        int L = 1, R = m * n;
        while(L <= R)
        {
            int mid = (L + R) >> 1;
            int t = GetLess(m, n, mid);
            if(t >= k)
            {
                R = mid - 1;
            }
            else L = mid + 1;
        }
        return R+1;
    }
};
__________________________________________________________________________________________________
sample 8440 kb submission
class Solution {
public:
    bool is_valid(int x, int m, int n, int k) {
        int sum = 0;
        for (int i = 1; i <= m; i++) {
            sum += min(x/i, n);
        }
        return sum >= k;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m*n;
        while (l <= r) {
            int mid = l + r >> 1;
            if (is_valid(mid, m, n, k)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r + 1;
    }
};
__________________________________________________________________________________________________
