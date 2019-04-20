__________________________________________________________________________________________________
4ms
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i % 2 != 0) res *= x;
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    double myPow(double x, int n) 
    {
        if (n==0)
        {
            return 1;
        }
        double res=1;
        int sign=1;
        unsigned int p;
        if (n<0)
        {
            sign = -1;
            if (n==-2147483648)
            {
                p=2147483648;
            }
            else
            {
                p    = -1*n;
            }
        }
        else
        {
            p = n;
        }
        while (p>0)
        {
            if(p%2==1)
            {
                if(sign>0)
                {
                    res = res*x;
                }
                else
                {
                    res = res/x;
                }
            }
            x = x*x;
            p = p/2;
        }
        return res;
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 0) return 1.0;
        if( x == 1) return 1.0;
        if(x == -1) return n%2 == 1 ? -1.0 : 1;
        if(n == INT_MIN) return 0.0;
        if(n < 0) return 1/myPow(x, -n);
        if(n % 2 == 0) return myPow(x * x, n/2);
        else return myPow(x, n-1) * x;
    }
};
__________________________________________________________________________________________________
8492 kb
class Solution {
public:
    double myPow(double x, int _n) {
        long long n = (long long) _n;
        double ret = 1.0;
        if (n < 0) {
            n *= -1;
            x = 1.0 / x;
        }
        while (n > 0) {
            if (n & 1) ret *= x;
            n /= 2;
            x = x * x;
        }
        return ret;
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
9932 kb
class Solution {
public:
    double myPow(double x, int n) {
      double power = 1.0;
      long p = labs(n);  
      while(p){
        if(p % 2){
          power *= x;
        }
        x *= x;
        p /= 2;
      }
      return n >= 1 ? power : 1 / power;
    }
};
__________________________________________________________________________________________________