__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int scoreOfParentheses(String S) {
        int res = 0, cur = 0;
        for (int i = 0; i < S.length(); i++) {
            cur += S.charAt(i) == '(' ? 1 : -1;
            if (S.charAt(i) == ')' && S.charAt(i-1) == '(') res += 1 << cur;
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 35268 kb submission
class Solution {
    public int scoreOfParentheses(String S) {
        
        Stack<Integer> st = new Stack<>();
         st.push(0);
        
        for(int i = 0; i<S.length(); i++){
            
            if(S.charAt(i) == '(') {
                st.push(0);
            } else {
                int top = st.pop();
                int secondTop = st.pop();
                
                int result = secondTop + Math.max(2*top,1);
                st.push(result);
            }
        }
        return st.pop();
    }
}
__________________________________________________________________________________________________
