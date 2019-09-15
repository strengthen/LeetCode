__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String reverseParentheses(String s) {
        char[] cs = s.toCharArray();
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < cs.length; i++) {
            if (cs[i] == '(') {
                st.push(i);
            }   
            else if (cs[i] == ')') {
                reverseInterval(cs, st.pop(), i);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (char c : cs) {
            if (c != '(' && c != ')') sb.append(c);
        }
        return sb.toString();
    }
    
    private void reverseInterval(char[] cs, int s, int e) {
        while (s < e) {
            char temp = cs[s];
            cs[s] = cs[e];
            cs[e] = temp;
            s++;
            e--;
        }
    }
}
__________________________________________________________________________________________________
3ms
class Solution {
    public String reverseParentheses(String s) {
        int begin = 0;
        int end;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '(')
                begin = i;
            if(s.charAt(i) == ')'){
                end = i;
                String temp = s.substring(begin + 1, end);
                return reverseParentheses(s.substring(0, begin) + reverseString(temp) + s.substring(end + 1));
            }
        }
        return s;
    }

    String reverseString(String s){
        char[] temp = s.toCharArray();
        StringBuilder r = new StringBuilder();
        for (int i = temp.length-1; i>=0; i--)
            r.append(temp[i]);

        return r.toString();
    }
}
__________________________________________________________________________________________________
