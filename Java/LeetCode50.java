__________________________________________________________________________________________________
0ms
class Solution {
    public double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        else if (n == Integer.MIN_VALUE) {
            if (Math.abs(x) == 1) {
                return 1;
            } else {
                return 0;
            }
        } else if (n < 0) {
            x = 1.0 / x;
            n = -1 * n;
        }
        
        return (n % 2 == 0) ? myPow(x * x, n / 2) : myPow(x * x, n / 2) * x; 
        
    }
}
__________________________________________________________________________________________________
1ms
class Solution {
    public double myPow(double x, int y) {
        double result = 1.0;
        long power = y;
        if(y < 0) {
            power = -power;
            x = 1.0/x;
        }
        while(power != 0){
            if((power & 1) != 0) {
                result = result * x;
            }
            x = x*x;
            power >>>= 1;
        }
        return result;
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public double myPow(double x, int n) {
       double result = 1;
        boolean negative = false;
        
        if (n != 0) {
            result = x;
            long i = 1, pos = n;
            
            final TreeMap<Long, Double> cache = new TreeMap<>();
            cache.put(1L, x);

            if (n < 0) {
                pos = n * -1L;
                negative = true;
            }

            while (i < pos) {
                if (i + i <= pos) {
                    result = result * result;
                    i = i + i;
                    cache.put(i, result);
                } else {
                    final Map.Entry<Long, Double> entry = cache.floorEntry(pos - i);
                    result = result * entry.getValue();
                    i = i + entry.getKey();
                }
            }
        }


        return negative ? 1 / result : result;
    }
}
__________________________________________________________________________________________________
37664 kb
class Solution {
    public double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(n == 1) return x;
        if(n < 0) {
            x = 1/x;
            if(n == Integer.MIN_VALUE) {
                n = Integer.MAX_VALUE-1;
            } else {
                n = -n;
            }
        }
        double halved = myPow(x, n/2);
        double result = halved * halved;
        if(n % 2 == 1) {
            result *= x;
        }
        return  result;
    }
}
__________________________________________________________________________________________________
37680 kb
class Solution {
    public double myPow(double x, int n) {
        long t = n;
        t = Math.abs(t);
        double result = 1.0;
        if (t == 0){
            return 1.0;
        }
        while(t > 0){
            long temp = 1;
            double tempx = x;
            while(temp <= t){
                result *= tempx;
                t -= temp;
                temp += 1;
                tempx *= x;                
            }
        }
        if( n < 0){
            result = 1 / result;
        }
        return result;
    }
}
__________________________________________________________________________________________________