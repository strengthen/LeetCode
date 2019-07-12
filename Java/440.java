__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int findKthNumber(int n, int k) {
        int curr = 1;
        k = k - 1;
        while (k > 0) {
            int steps = calSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr += 1;
                k -= steps;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }

    public int calSteps(int n, long n1, long n2) {
    int steps = 0;
    while (n1 <= n) {
        steps += Math.min(n + 1, n2) - n1;
        n1 *= 10;
        n2 *= 10;
    }
    return steps;
}
}
__________________________________________________________________________________________________
sample 31588 kb submission
class Solution {

    private int nOnes(int n) {
        int ans = 0;
        while (n-- > 0) {
            ans = ans * 10 + 1;
        }
        return ans;
    }

    private int digits(int x) {
        int ans = 0;
        while (x > 0) {
            ans++;
            x /= 10;
        }
        return ans;
    }

    private int pow10(int n) {
        int ans = 1;
        while (n-- > 0) {
            ans *= 10;
        }
        return ans;
    }

    private int numStartWith(int n, int x, int pow) {
        if (x == 0) {
            return 0;
        }
        int mod = pow10(pow), start = n / mod;
        if (start > x) {
            return nOnes(pow + 1);
        } else {
            return nOnes(pow) + (start == x ? n % mod + 1 : 0);
        }
    }

    public int findKthNumber(int n, int k) {
        int ans = 0;
        for (int i = digits(n) - 1; i >= 0; --i) {
            int sum = 0;
            for (int j = 0; j < 10; ++j) {
                int cur = numStartWith(n, 10 * ans + j, i);
                if (sum + cur >= k) {
                    k -= sum;
                    ans = 10 * ans + j;
                    break;
                }
                sum += cur;
            }
            if (k == 1) {
                break;
            } else {
                k--;
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
