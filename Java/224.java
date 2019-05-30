__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int calculate(String s) {
        if( s == null || s.length() == 0 ) return 0;
        return calculate21( s.toCharArray(), 0, new int[]{0});
    }
    
    private int calculate21( char[] s, int index, int[] next ){
        int sum= 0, n=0, sign = 1;
        for( int i = index; i < s.length; i ++ ){
            char c = s[i];
            if( c == '+' || c == '-'){
                sum += n*sign;
                sign = 1;
                if( c == '-') sign = -1;
                n=0;
            }else if( c >= '0' && c <= '9'){
                n = n*10 + (c-'0');
            }else if( c == '('){
                n = calculate21( s, i+1, next );
                i = next[0];
            }else if( c == ')'){
                next[0] = i;
                break;
            }
        }
        
        sum += n*sign;
        return sum;
    }
    
    private int calculate2( String s, int index, int[] next ){
        int sum = 0, n = 0;
        int sign = 1;
        for( int i = index; i < s.length(); i ++ ){
            char c = s.charAt(i);
            if( c == '+' || c == '-'){
                sum += n*sign;
                
                sign = 1;
                if( c == '-') sign = -1;
                n = 0;
            }else if( c >= '0' && c <= '9'){
                n = n*10 + (c-'0');                
            }else if( c == '('){
                n = calculate2( s, i+1, next );
                sum += n*sign;
                n = 0;
                i = next[0];
            }else if( c == ')'){
                next[0] = i;
                break;
            }
        }
        
        sum += n*sign;
        
        return sum;
    }
    
    private int calculate( String s, int index, int[] next ){
        int sum = 0, n = 0;
        boolean positive = true;
        while( index < s.length() ){
            char c = s.charAt(index);
            if( c == '(' ){
                n = calculate( s, index+1, next);
                index = next[0];
                continue;
            }else if( c == ')'){
                sum += positive ? n : -n;
                next[0] = index + 1;
                return sum;
            }else if( c >= '0' && c <= '9'){
                n = n*10 + (c-'0');
            }else if( c == '+' || c == '-'){
                sum += (positive?n : -n);
                n = 0;
                if( c == '-') positive = false;
                else positive = true;
            }
            index ++;
        }
        sum += positive ? n : -n;
        next[0] = index + 1;
        return sum;
    }
}
__________________________________________________________________________________________________
sample 35964 kb submission
class Solution {
    public int calculate(String s) {
        int m = (s == null) ? 0 : s.length();
        if (m == 0) {
            return 0;
        }
        
        Deque<Integer> stack = new ArrayDeque<>();
        int current = 0;
        int sign = 1;
        
        int index = 0;
        
        while (index < m) {
            char c = s.charAt(index);
            
            if (Character.isSpace(c)) {
                ++index;
                continue;
            } else if (Character.isDigit(c)) {
                int left = index++;
                
                while (index < m && Character.isDigit(s.charAt(index))) {
                    ++index;
                }
                
                current += (sign) * Integer.parseInt(s.substring(left, index));
                sign = 1;
                continue;
            } else if (c == '(') {
                stack.push(current);
                stack.push(sign);
                
                current = 0;
                sign = 1;
            } else if (c == ')') {
                int prevSign = stack.isEmpty() ? 1 : stack.pop();
                int prevVal = stack.isEmpty() ? 0 : stack.pop();
                
                current = prevVal + prevSign * current;
                
                sign = 1;
            } else {
                sign = (c == '+') ? 1 : -1;
            }
            
            ++index;
        }
        
        return current;
    }
}
__________________________________________________________________________________________________
class Solution {
    public static int calculate(String s) {
	int len = s.length(), sign = 1, result = 0;
	Stack<Integer> stack = new Stack<Integer>();
	for (int i = 0; i < len; i++) {
		if (Character.isDigit(s.charAt(i))) {
			int sum = s.charAt(i) - '0';
			while (i + 1 < len && Character.isDigit(s.charAt(i + 1))) {
				sum = sum * 10 + s.charAt(i + 1) - '0';
				i++;
			}
			result += sum * sign;
		} else if (s.charAt(i) == '+')
			sign = 1;
		else if (s.charAt(i) == '-')
			sign = -1;
		else if (s.charAt(i) == '(') {
			stack.push(result);
			stack.push(sign);
			result = 0;
			sign = 1;
		} else if (s.charAt(i) == ')') {
			result = result * stack.pop() + stack.pop();
		}

	}
	return result;
 }
}