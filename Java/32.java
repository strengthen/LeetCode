__________________________________________________________________________________________________
1ms
class Solution {
    public int longestValidParentheses(String s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                l++;
            } else {
                r++;
            }
            if (r == l) {
                ans = Math.max(ans, r * 2);
            } else if (r > l) {
                l = 0;
                r = 0;
            }
        }
        l = 0;
        r = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') {
                l++;
            } else {
                r++;
            }
            if (r == l) {
                ans = Math.max(ans, l * 2);
            } else if (l > r) {
                l = 0;
                r = 0;
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
1ms
public class Solution {
    public int longestValidParentheses(String s) {
        int length=s.length();
        if (length==0) {
            return 0;
        }
        int ans=0;
        char[] c=s.toCharArray();
        int[] vals=new int[length];
        for (int i = length-2; i >= 0; i--) {
            if (c[i]=='(') {
                int t=i+1+vals[i+1];
                if (t<length&&c[t]==')') {
                    vals[i]=vals[i+1]+2;
                    vals[i]+=((t+1<length)?vals[t+1]:0);
                    ans=ans<vals[i]?vals[i]:ans;
                }
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public int longestValidParentheses(String s) {
        if (s.length() <= 1) return 0;  // 单个char也不能组成valid parentheses
        
        int[] dp = new int[s.length()];
        int max = Integer.MIN_VALUE;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                dp[i] = 0;
            } else if (s.charAt(i) == ')') {
                if (s.charAt(i - 1) == '(') {
                    dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
                } else if (s.charAt(i - 1) == ')') {
                    if (i - dp[i - 1] - 1 >= 0 && s.charAt(i - dp[i - 1] - 1) == '(') {
                        dp[i] = i - dp[i - 1] - 2 >= 0 ? dp[i - 1] + 2 + dp[i - dp[i - 1] - 2] : dp[i - 1] + 2;
                    }
                }
            } else throw new IllegalArgumentException("invlid input!");
            max = Math.max(max, dp[i]);
        }
        
        return max;
    }
}
__________________________________________________________________________________________________
35368 kb 
class Solution {
    public int longestValidParentheses(String s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++){
            if (s.charAt(i)=='(') {
                left ++;
            }  else {
                right++;
            }

            if (left == right ){
                maxlength = Math.max(maxlength, right * 2);
            }else if (right > left ) {
                left = right = 0;
            }
            
        }
        left = right = 0;
        for (int i=s.length()-1; i>=0; i--){
            if ( s.charAt(i) == ')') {
                right ++;
            }else 
                left ++;
            
            if (left == right ){
                maxlength = Math.max(maxlength,left*2);
            } else if (left > right) {
                left = right = 0;
            }
        }
        
        return maxlength;
    }    
}
__________________________________________________________________________________________________
35428 kb
class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(-1);
        int max  = 0;
        for (int i=0;i<s.length();i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.isEmpty()) {
                    stack.push(i);
                } else {
                    max = Math.max(max, i - stack.peek());
                }
            }
        }
        return max;
    }
}
__________________________________________________________________________________________________