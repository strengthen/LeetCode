__________________________________________________________________________________________________
6ms
class Solution {
    public boolean isPalindrome(int x) {
      if (x<0) {
          return false;
      }   
      
      // x%10 = value of digit 0
      // x/10%10 value of digit 1
      // x/10^n%10 value of digit n

        // 123 --> 321
        // abcdedcba
        // abba
        // revert half and 
        long number = (long)x;
        long sum = 0;
        // 121
        while (x!=0) {
            int digit = x%10;//1,2,1
            x = x/10;// 12,1,0
            sum = sum * 10 + digit; // 121
        }       
        
        return number == sum;
        // 3,2,1        
    }
}
__________________________________________________________________________________________________
7ms
class Solution {
    public boolean isPalindrome(int x) {
        
        if(x < 0)   return false;
        int w = x;
        int y = 0;
        while(x != 0) {
            y = y * 10 + x % 10;
            x = x / 10;
        }
        return y == w;
    }
}
__________________________________________________________________________________________________
8ms
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) return false;
        char[] str=Integer.toString(Math.abs(x)).toCharArray();
        int len=str.length;
        for(int i=0;i<len/2;i++){
            if(str[i]!=str[len-1-i])
                return false;
        }
        return true;
    }
}
__________________________________________________________________________________________________
37196 kb
import java.util.*;
class Solution {
     int [] intToArray(int n){
        List<Integer> temp = new ArrayList<Integer>();

        while (n!=0){

            temp.add(n%10);
            n = n/10;
        }
        int [] ans = temp.stream().mapToInt(i -> i).toArray();
        return ans ;
    }
    public boolean isPalindrome(int x) {
        if(x<0) return false;
        int [] check = intToArray(x);
        int size = check.length;
        for (int i =0;i<size/2;i++){
            if(check[i]!=check[size-i-1]){
                return false;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
38912 kb
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else {
            int reversedInt = reverseInteger(x);
            return reversedInt == x;
        }
    }

    private int reverseInteger(int x) {
        int sign = 1;
        if(x < 0){
            sign = -1;
            x *= -1;
        }

        long result = 0;
        while(x != 0){
            result = result * 10 + x % 10;
            if(sign * result > Integer.MAX_VALUE ||
                    sign * result < Integer.MIN_VALUE)
                return 0;
            x = x / 10;
        }

        return (int)result * sign;
    }
}
__________________________________________________________________________________________________
