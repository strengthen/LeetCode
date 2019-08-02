__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int consecutiveNumbersSum(int N) {
        while ((N & 1) == 0) N >>= 1;
        int ans = 1, d = 3;

        while (d * d <= N) {
            int e = 0;
            while (N % d == 0) {
                N /= d;
                e++;
            }
            ans *= e + 1;
            d += 2;
        }

        if (N > 1) ans <<= 1;
        return ans;
    }
}
__________________________________________________________________________________________________
sample 31764 kb submission
class Solution {
    public int consecutiveNumbersSum(int N) {
        int ans = 0;
        for (int m = 1; ; m++) {
            int mx = N - m * (m-1) / 2;
            if (mx <= 0)
                break;
            if (mx % m == 0)
                ans++;
        }
        return ans;
    }
    
    /*
    这道题的要求的另一种说法: 把N表示成一个等差数列（公差为1）的和
我们不妨设这个数列的首项是x，项数为m，则这个数列的和就是[x + (x + (m-1))]m / 2 = mx + m(m-1)/2 = N
接下来，一个很自然的想法就是，枚举m，通过上式判断对于相应的m是否存在合法的x。
x = ((N - m(m-1)/2)) / m
显然枚举的复杂度是O(sqrt(N))。因为m能取到的最大值显然是sqrt(n)数量级的
    
    */
}
__________________________________________________________________________________________________
