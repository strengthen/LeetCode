__________________________________________________________________________________________________
sample 1 ms submission
class Solution {    
    private String[] tokens;
    private int index;
    
    public int evalRPN(String[] tokens) {
        this.tokens = tokens;
        this.index = tokens.length -1;
        return eval();
    }
    
    private int eval() {
        String token = tokens[index--];
        if ("+".equals(token)) return eval() + eval();
        else if ("-".equals(token)) return -eval() + eval();
        else if ("*".equals(token)) return eval() * eval();
        else if ("/".equals(token)) { 
            int divisor = eval(); 
            return eval() / divisor; 
        }
        return Integer.parseInt(token);
    }
}
__________________________________________________________________________________________________
sample 34192 kb submission
class Solution {
    public int evalRPN(String[] tokens) {
        if (tokens == null || tokens.length == 0){
            return 0;
        }
        Stack<Integer> stack =  new Stack<>();
        for (String s : tokens){
            if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")){
                int b = stack.pop();
                int a = stack.pop();
                if (s.equals("+")){
                    stack.push(a+b);
                }else if (s.equals("-")){
                    stack.push(a-b);
                }else if (s.equals("*")){
                    stack.push(a*b);
                }else if (s.equals("/")){
                    stack.push(a/b);
                }
            }else{
                stack.push(Integer.valueOf(s));
            }
        }
        return stack.pop();
    }
}
__________________________________________________________________________________________________
