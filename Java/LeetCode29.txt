__________________________________________________________________________________________________
1ms
class Solution {
    public int divide(int dividend, int divisor) {
        /*
        首先这道题是求商，不用管余数，也就是说看dividend最多可以由多少个divisor组成
        最朴素的想法，就是一个一个加divisor，逼近dividend，不过这样太慢了，如果divisor是1的话很容易超时

        所以在这个朴素想法的基础上，把逼近的做法改为每次乘以2，
        也就是第一次divisor，第二次divisor*2，第三次divisor*2*2
        实际就是位运算的左移操作。
        于此同时我们还要记录乘了多少个divisor，同样的做法，对1做一样的位运算，就记录的divisor的个数

        剩下的就是溢出的边界条件，以及结果符号的处理
        */
        if (divisor == 0 || (dividend == Integer.MIN_VALUE && divisor == -1) || (dividend == Integer.MAX_VALUE && divisor == 1))
            return Integer.MAX_VALUE;
        if (dividend == 0) return 0;
        boolean resultPositive = (dividend < 0) == (divisor < 0); //记录结果符号
        long dividendInLong = Math.abs((long) dividend); //统一转化成正的long
        long divisorInLong = Math.abs((long)divisor); //注意这里long的转换要放在里边，否则可能溢出导致结果不对
        int sum = 0;

        //逼近dividendInLong，内层循环超过之后，dividendInLong减去temp，再循环逼近
        //所以时间复杂度是longn*longn
        while (divisorInLong <= dividendInLong) { 
        	int count = 1;
        	long temp = divisorInLong;
        	while ((temp << 1) < dividendInLong) {
        		temp <<= 1;
        		count <<= 1;
        	}
        	dividendInLong -= temp;
        	sum += count;
        }
        return resultPositive ? sum : -sum;
    }
}
__________________________________________________________________________________________________
1ms    
public class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend==-2147483648&&divisor==-1){
            return 2147483647;
        }
        return dividend/divisor;
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1)
            return Integer.MAX_VALUE;
        if (dividend == 0) return 0;
        
        long divd = dividend, divs = divisor, l = 0, r;
        if ((divd > 0 && divs > 0) || (divd < 0 && divs < 0))
            r = Math.abs(divd) + 1;
        else r = -Math.abs(divd) - 1;
        
        while (Math.abs(r - l) > 1) {
            long mid = l + (r - l) / 2;
            if (Math.abs(mid * divs) == Math.abs(divd)) return (int)mid;
            else if (Math.abs(mid * divs) < Math.abs(divd)) l = mid;
            else r = mid;
        }
        return (int)l;
    }
}
__________________________________________________________________________________________________
37896 kb
class Solution {
 public int divide(int A, int B) {
		 if (A == 1 << 31 && B == -1) return (1 << 31) - 1;
        int a = Math.abs(A), b = Math.abs(B), res = 0;
        for (int x = 31; x >= 0; x--)
            if ((a >>> x) - b >= 0) {
                res += 1 << x;
                a -= b << x;
            }
        return (A > 0) == (B > 0) ? res : -res;
	}
}
__________________________________________________________________________________________________
37904 kb
class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend == Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;
        if(dividend == 0) return 0;
        
        boolean negFlag = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        int quotient = 1;
        long ldividend = Math.abs((long) dividend);
        long ldivisor = Math.abs((long) divisor);
        if(ldividend < ldivisor) return 0;
        
        while(ldividend >= (ldivisor+ldivisor)){
            ldivisor <<= 1;
            quotient <<= 1;
        }
        
        while(ldividend >= (ldivisor + Math.abs((long) divisor))){
            ldivisor += Math.abs((long) divisor);
            quotient += 1;
        }
        
        return (negFlag) ? -1 * quotient : quotient;
    }
}
__________________________________________________________________________________________________
