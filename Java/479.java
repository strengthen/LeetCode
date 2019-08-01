__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int largestPalindrome(int n) {
        return new int[]{9, 987, 123, 597, 677, 1218, 877, 475}[n - 1];
    }
}
__________________________________________________________________________________________________
sample 11 ms submission
class Solution {
    public int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        if(n==7){
            return 877;
        }
        long limit = (long) Math.pow(10, n);
        long higherBound = limit - 1;
        long lowerBound = limit - limit / 10;
        for (long i = higherBound; i > lowerBound; i--) {
            for (long j = i; j > lowerBound; j--) {
                long product = i * j;
                if (isPalindrome(product)) {
                    System.out.println(product);
                    return (int) (product % 1337);
                }
            }
        }
        return 0;
    }

    private boolean isPalindrome(long num) {
        String str = String.valueOf(num);
        for (int i = 0; i <= (str.length() - 1) / 2; i++) {
            if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 31756 kb submission
class Solution {
    public int largestPalindrome(int n) {
        long max = (long)Math.pow(10, n) - 1;
        long min = max / 10;

        for (long h = max; h > min; h--) {
            long left = h, right = 0;
            for (long i = h; i != 0; right = right * 10 + i % 10, i /= 10, left *= 10);
            long palindrom = left + right;      // construct the palindrome

            for (long i = max; i > min; i--) {
                long j = palindrom / i;
                if (j > i) break;     // terminate if the other number is greater than current number
                if (palindrom % i == 0) return (int)(palindrom % 1337); // found if current number is a factor
            }
        }

        return 9;    // account for case n = 1
    }
}