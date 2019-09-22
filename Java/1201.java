__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) {
        int min = 1, max = 2_000_000_001;
        while(min < max){
            int mid = min + (max - min) / 2;
            if (isFloor(n, a, b, c, mid)){
                min = mid + 1;
            } else {
                max = mid;
            }
        }
        return max;
    }

    public boolean isFloor(int n, int a, int b, int c, int mid){
        int count = mid / a + mid / b + mid / c;
        count = (int) (count - mid / maxCommonDivisor(a, b) - mid / maxCommonDivisor(a, c) - mid / maxCommonDivisor(b, c) + mid / maxCommonDivisor(maxCommonDivisor(a, b), c));
        return count < n;
    }

    private long maxCommonDivisor(long m, long n) {
        long tmp = m * n;
        if (m < n) {
            long temp = m;
            m = n;
            n = temp;
        }
        while (m % n != 0) {
            long temp = m % n;
            m = n;
            n = temp;
        }
        return tmp / n;
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) {
        long low = 1, high = Integer.MAX_VALUE, mid;  
  
        while (low < high) {  
            mid = low + (high - low) / 2;  
  
            // If the current term is less than  
            // n then we need to increase low  
            // to mid + 1  
            if (divTermCount(a, b, c, mid) < n)  
                low = mid + 1;  
      
            // If current term is greater than equal to  
            // n then high = mid  
            else
                high = mid;  
        }  
  
        return (int)low;
    }
    static long divTermCount(long a, long b, long c, long num)  
    {  
  
        // Calculate number of terms divisible by a and  
        // by b and by c then, remove the terms which is are  
        // divisible by both a and b, both b and c, both  
        // c and a and then add which are divisible by a and  
        // b and c  
        return ((num / a) + (num / b) + (num / c)  
                - (num / lcm(a, b))  
                - (num / lcm(b, c))  
                - (num / lcm(a, c))  
                + (num / lcm(a, lcm(b, c))));  
    }
    static long gcd(long a, long b)  
    {  
        if (a == 0)  
            return b;  
          
        return gcd(b % a, a);  
    }  
  
    // Function to return the lcm of a and b  
    static long lcm(long a, long b)  
    {  
        return (a * b) / gcd(a, b);  
    }  
}
__________________________________________________________________________________________________
