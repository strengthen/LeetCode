__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int findIntegers(int num) {
         String s = Integer.toBinaryString(num);
        //System.out.println(sb);
        int n = s.length();
        // a[i] means length of i and ends with 0.
        // b[i] means length of i and ends with 1.
        int[] a = new int[n], b = new int[n];
        a[0] = b[0] = 1;
        for(int i = 1; i < n; i++) {
            a[i] = a[i-1] + b[i-1];
            b[i] = a[i-1];
        }
        int res = a[n-1] + b[n-1];
        for(int i = 1; i < n; i++) {
            if(s.charAt(i) == '1' && s.charAt(i-1) == '1')    break;
            if(s.charAt(i) == '0' && s.charAt(i-1) == '0')    res = res - b[n-i-1];
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 32000 kb submission
public class Solution {
    public int findIntegers(int num) {
        int[] f = new int[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < f.length; i++)
            f[i] = f[i - 1] + f[i - 2];
        int i = 30, sum = 0, prev_bit = 0;
        while (i >= 0) {
            if ((num & (1 << i)) != 0) {
                sum += f[i];
                if (prev_bit == 1) {
                    sum--;
                    break;
                }
                prev_bit = 1;
            } else
                prev_bit = 0;
            i--;
        }
        return sum + 1;
    }
}
__________________________________________________________________________________________________
