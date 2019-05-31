__________________________________________________________________________________________________
sample 31484 kb submission
class Solution {
    public int countDigitOne(int n) {
        if(n <= 0) return 0;
        int q = n;
        int ans = 0;
        int x = 1;
        
        while(q > 0) {
            int digit = q % 10;
            q /= 10;
            
            if(digit == 0) {
                ans += q * x;
            } else if (digit == 1) {
                ans += q * x + n % x + 1;
            } else {
                ans += q * x + x;
            }
            x *= 10;
        }
        return ans;
    }
}
__________________________________________________________________________________________________
sample 34188 kb submission
/*举一个简单的例子，求0-5137这5138个数字中出现1的个数，就等价于求1在个位、十位、百位、千位出现的个数的总和。现考虑1在百位出现的个数。简单地枚举一下，有100-199,1100-1199,2100-2199,...,5100-5137总共500+37=537个；如果求0-5037出现1的个数，有100-199,1100-1199,2100-2199,...,4100-4199总共500个；如果求0-5237出现1的个数，有100-199,1100-1199,2100-2199,...,5100-5199总共600个。
可以得出结论，对应一个数AbC，b是一个0-9的数字，0-AdC中出现在b位置上的1的个数和b的大小有关：
b=0，个数为A*10^C的位数；
b=1，个数为A*10^C的位数 + C；
b>1，个数为(A+1)*10^C的位数
*/
class Solution {
    public int countDigitOne(int n) {
        if (n<=0) {
            return 0;
        }
        int sum=0;
        int higher=10;
        int lower=1;
        for (int i=0;i<9;i++) {
            // full loop of lower digit repeats
            int mul=n/higher;
            // each full loop of lower digit repeats exactly lower times
            sum+=mul*lower;
            // count non-full loop
            sum+=count(n%higher,lower,1);
            if (mul==0) {
                break;
            }
            if (i==8) {
                // count 10^9 digit
                sum+=count(n,higher,1);
            }
            higher*=10;
            lower*=10;
        }
        return sum;
    }
    
    int count(int val, int rate, int k) {
        // first digit
        int digit=val/rate;
        // first digit less than k, zero
        if (digit<k) {
            return 0;
        }
        // first digit greater than k, full loop
        if (digit>k) {
            return rate;
        }
        // first digit equals k
        return 1+(val%rate);
    }
}
__________________________________________________________________________________________________
