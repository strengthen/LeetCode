__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
     int nthMagicalNumber(int N, int A, int B) {
        long lcm = A * B / __gcd(A, B), l = 2, r = 1e14, mod = 1e9 + 7;
        while (l < r) {
            long m = (l + r) / 2;
            if (m / A + m / B - m / lcm < N) l = m + 1;
            else r = m;
        }
        return l % mod;
    }
};
__________________________________________________________________________________________________
sample 8420 kb submission
class Solution {
public:
    long long gcd(long long a, long long b)
    {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    long long lcm(long long a, long long b)
    {
        return a / gcd(a, b) * b;
    }
    
    
    int nthMagicalNumber(int N, int A, int B) {        
        long long L = 0, R = 1e17, ans = -1, mid = 1, t, _lcm = lcm(A,B), mod = 1e9 + 7;
        mid = 1LL * A * B * N / (A + B - A * B * 1LL / _lcm);
        L = mid - (A + B);
        R = mid + (A + B);
        while(L <= R)
        {
            
            mid = (L + R) >> 1;
            t = mid / A + mid / B - mid / _lcm;
            if(t >= N)
            {
                ans = mid;
                R = mid - 1;
            }
            else 
            {
                L = mid + 1;
            }
        }
        return ans % mod;
    }
};

__________________________________________________________________________________________________
