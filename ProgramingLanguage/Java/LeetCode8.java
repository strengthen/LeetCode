__________________________________________________________________________________________________
1ms
class Solution {
    public int myAtoi(String str) {
        int index = 0, sign = 1, total = 0;
        //1. Empty string
        if(str.length() == 0) return 0;

        //2. Remove Spaces
        while(index < str.length() && str.charAt(index) == ' ')
            index ++;
        if (index >= str.length()) return 0;
        
        //3. Handle signs
        if(str.charAt(index) == '+' || str.charAt(index) == '-'){
            sign = str.charAt(index) == '+' ? 1 : -1;
            index ++;
        }

        //4. Convert number and avoid overflow
        while(index < str.length()){
            int digit = str.charAt(index) - '0';
            if(digit < 0 || digit > 9) break;

            //check if total will be overflow after 10 times and add digit
            if(Integer.MAX_VALUE/10 < total || Integer.MAX_VALUE/10 == total && Integer.MAX_VALUE %10 < digit)
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;

            total = 10 * total + digit;
            index ++;
        }
        return total * sign;
    }
}
__________________________________________________________________________________________________
1ms
public class Solution {
    public int myAtoi(String str) {
        if (str.isEmpty()) return 0;
        int sign = 1, base = 0, i = 0, n = str.length();
        while (i < n && str.charAt(i) == ' ') ++i;
        if (i < n && (str.charAt(i) == '+' || str.charAt(i) == '-')) {
            sign = (str.charAt(i++) == '+') ? 1 : -1;
        }
        while (i < n && str.charAt(i) >= '0' && str.charAt(i) <= '9') {
            if (base > Integer.MAX_VALUE / 10 || (base == Integer.MAX_VALUE / 10 && str.charAt(i) - '0' > 7)) {
                return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            base = 10 * base + (str.charAt(i++) - '0');
        }
        return base * sign;
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public int myAtoi(String str) {
        int sign = 0;
        char[] chars = str.toCharArray();
        long temp = 0;
        for (char c: chars) {
            if (sign == 0) {
                if (c == ' ') {
                    continue;
                } else if (c == '+') {
                    sign = 1;
                } else if (c == '-') {
                    sign = -1;
                } else if (Character.isDigit(c)) {
                    sign = 1;
                    temp = Long.parseLong(String.valueOf(c));
                } else {
                    return 0;
                }
            } else {
                if (Character.isDigit(c)) {
                    temp = temp * 10 + Long.parseLong(String.valueOf(c));
                    temp = temp * sign;
                    if (temp > Integer.MAX_VALUE) {
                        return Integer.MAX_VALUE;
                    }
                    
                    if (temp < Integer.MIN_VALUE) {
                        return Integer.MIN_VALUE;
                    }
                    temp = temp * sign;
                } else {
                    break;
                }
            }
        }
        temp = temp * sign;
        return (int) temp;
    }
}
__________________________________________________________________________________________________
35620 kb
class Solution {
    public int myAtoi(String s) {
        s = s.trim();
        if(s.length() == 0)return 0;
        long result = 0;
        int i = 0;
        int flag = 1;

        if(s.charAt(0) == '-')
        {
            flag = -1;
            i += 1;
        }
        else if(s.charAt(0) == '+')
        {
            flag = 1;
            i += 1;
        }

        while( i < s.length() && Character.isDigit(s.charAt(i)))
        {
            result = result * 10 + s.charAt(i) - '0';
            if (flag*result > Integer.MAX_VALUE ){
                return Integer.MAX_VALUE;
            }
            else if (flag*result<Integer.MIN_VALUE){
                return Integer.MIN_VALUE;
            }
            i += 1;
        }
        return (int)(flag*result);
    }
}
__________________________________________________________________________________________________
35628 kb
class Solution {
    public int myAtoi(String str) {
        long result = 0;
        boolean negative = false;
        str = str.trim();
        
        for (int i = 0; i < str.length(); i++) {
            if (i == 0) {
                if (str.charAt(i) == '-') {
                    negative = true; 
                    continue;
                } else if (str.charAt(i) == '+') {
                    continue;
                }                
            }
            
            if (str.charAt(i) - '0' < 0 || str.charAt(i) - '0' > 9) {
                break;
            }
            
            result = result * 10 + str.charAt(i) - '0';
            
            if (negative == true) {
                if (result > Integer.MAX_VALUE) {
                    return Integer.MIN_VALUE;
                }  
            } else if (result > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            } 
        }
        
        result = negative ? result * -1 : result;
        
        return (int)result;
    }
}
__________________________________________________________________________________________________
