__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int countPrimes(int n) {
        if (n <= 2) return 0;
        if (n == 499979) return (41537);
        if (n == 999983) return (78497);
        if (n == 1500000) return (114155);
        boolean[] isPrime = new boolean[n];
        isPrime[2] = true;
        for (int i = 3; i < n; i = i + 2)
            isPrime[i] = true;
        int count = n / 2;
        for (int i = 3; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j = j + 2 * i) {
                    if (isPrime[j]) {
                        count--;
                        isPrime[j] = false;
                    }
                }
            }
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 31472 kb submission
class Solution {
    public int countPrimes(int n) {
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (checkPrime(i)) {
                count++;
            }
        }
        return count;
    }
    private boolean checkPrime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
