__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    vector < long long > A;
    
    long long gcd(long long a, long long b) {
        return b ? gcd(b, a%b) : a;
    }
    
    long long cnt (long long x) {
        long long all = 0;
        for(int i = 1;i < (1 << 3);++i) {
            int cnt = 0;
            long long f = 1;
            long long g = 0;
            for(int j = 0;j < 3;++j) {
                if(i & (1 << j)) {
                    ++cnt;
                    f *= A[j];
                    g = gcd(A[j], g);
                }
            }
            
            if(cnt == 2) {
                f /= g;
            }
            if(cnt == 3) {
                long long a = A[0];
                long long b = A[1];
                long long c = A[2];
                long long res = f;
                long long gg = gcd(a, b);
                a /= gg;
                long long acc = a * b;
                
                gg = gcd(acc, c);
                c /= gg;
                acc *= c;
                f = acc;
            }
            
            // cout << f << "  ";
            // cout << g << "\n";
            
            if(cnt & 1) {
                all += x/f;
            } else {
                all -= x/f;
            }
            // cout << x << "\n";
        }
        return all;
    }
    
    
    int nthUglyNumber(int n, int a, int b, int c) {
        A.push_back(a);
        A.push_back(b);
        A.push_back(c);
        
        // cout << gcd(0, 25) << "\n";
        
        sort(A.begin(), A.end());
        // cout << cnt(60);
        // return 3;

        long long lo = 0, hi = 1LL << 62;
        while(lo + 1 < hi) {
            long long mid = lo + (hi - lo) / 2;
            if(cnt(mid) >= n) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        // cout << hi << " " << cnt(60) << "\n";
        return lo + 1;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
#define ll long long
class Solution {
public:
    ll help(ll mid,ll a,ll b,ll c,ll lcmab,ll lcmbc,ll lcmca,ll lcm)
    {
        return mid/a+mid/b+mid/c-mid/lcmab-mid/lcmbc-mid/lcmca+mid/lcm;
    }
    int nthUglyNumber(int n, int a, int b, int c)
    {
        
        ll s=1,e=LLONG_MAX;
        ll lcmab=(ll)a*(ll)b/__gcd(a,b),lcmbc =(ll)c*(ll)b/__gcd(c,b),lcmca=(ll)a*(ll)c/__gcd(a,c);
        ll lcm=c*(lcmab)/__gcd((ll)c,lcmab);
        while(s<e)
        {
            ll mid=s+(e-s)/2;
            if(help(mid,a,b,c,lcmab,lcmbc,lcmca,lcm)<n)
            {
                s=mid+1;
            }
            else e=mid;
        }
        return s;
    }
};
__________________________________________________________________________________________________
