__________________________________________________________________________________________________
4ms
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a=dividend>=0 ? dividend: -(long long)dividend;
        long long b=divisor>=0 ? divisor: -(long long)divisor;
        
        if(dividend==INT_MIN && divisor==-1)//会溢出
            return INT_MAX;
        
        long long result=0;
        while(a>=b){
            long long c=b;
            for(int i=0;a>=c;++i,c<<=1){
                a-=c;
                result+=1<<i;
            }
        }
        return ((dividend^divisor)>>31)? -result: result;
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (n == 1) return sign == 1 ? m : -m;
        while (m >= n) {
            long long t = n, p = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        return sign == 1 ? res : -res;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    int positividivide(int dividend, int di)
    {
        int dd = di;
        vector<int> tmp;
        int flag = 0;
        int ans = 0;
        while (di < dividend)
        {
            printf(" tmp[%d] = di = %d\n", tmp.size(),di);
            tmp.push_back(di);
            if (di>=1073741824)
            {
                break;
            }
            di += di; 
        }
        flag = tmp.size()-1;
        while (dividend>=dd)
        {
            if (dividend < tmp[flag])
            {
                flag--;
                continue;
            }
            printf("dividend = %d,tmp[%d] = %d     ",dividend, flag, tmp[flag]);
            dividend -= tmp[flag];
            printf("dividend = %d\n",dividend);
            ans += 1<<flag;
            flag--;
        }
        return ans;
    }
    int divide(int dividend, int divisor) {
        int ans = 0;
        if (dividend == 0 )
        {
            return 0;
        }
        if (divisor == 0)
        {
            return -1;
        }
        
        if (divisor == -1)
        {
            if (dividend<-2147483647)
            {
                return 2147483647;
            }
            return -dividend;
        }
        if (divisor == 1)
        {
            return dividend;
        }
        if (divisor == -2147483648)
        {
            if (dividend == divisor)
            {
                return 1;
            }
            return 0;
        }
        if (dividend == -2147483648)
        {
            dividend += abs(divisor);
            ans = 1;
        }
        if (dividend == divisor)
        {
            return 1;
        }
        
        ans += positividivide(abs(dividend), abs(divisor));
        printf("ans = %d \n",ans);
        if ((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0))
        {
            return ans;
        }
        return -ans;
    }
};
__________________________________________________________________________________________________
8116 kb
class Solution {
public:
    int divide(int dividend, int divisor) {
        
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        std::ios_base::sync_with_stdio(false);
        
        long a = dividend>0 ? dividend : -(long)dividend;
        long b = divisor>0 ? divisor : -(long)divisor;
        
        long res = 0, c = 0;
        bool pstv = (dividend>0 && divisor>0) || (dividend<0&&divisor<0);
        
        while (a>=b) {
            c = b;
            for (int i=0; a>=c; i++, c<<=1) {
                a -= c;
                res += (1<<i);
            }
        }
        
        if (pstv) {
            return min((long)INT_MAX, res);
        } else {
            return max((long)INT_MIN, -res);
        }
    }
};
__________________________________________________________________________________________________
8248 kb
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
  int divide(int dividend, int divisor) {
	if (divisor == 0) return std::numeric_limits<int>::max();

	int shift = 0;
	long long dividend_value = dividend > 0 ? dividend 
	  : 0LL - ((long long)dividend);
	long long divisor_value = divisor > 0 ? divisor 
	  : 0LL - ((long long)divisor);
	int sign_flag = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
	while ((divisor_value << shift) <= dividend_value) ++shift;

	long long result = 0;
	int bits = shift - 1;
	while (bits >= 0) {
	  if ((dividend_value - (divisor_value << bits)) >= 0) {
		dividend_value -= divisor_value << bits;
		result += (long long)1 << bits;
	  }
	  --bits;
	}

	// if (dividend_value > 0)
	//   if (dividend < 0 || divisor < 0) ++result;

	result = sign_flag * result;

	if (result < std::numeric_limits<int>::min() || 
		result > std::numeric_limits<int>::max()) 
	  return std::numeric_limits<int>::max();
	else return result;
  }
};
__________________________________________________________________________________________________
