__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    /**
     *  Idea1:  Recursive Parsing
     *  Idea2:  1)  Use a list to store variable table for each scope.
     *          2)  Each time we have a "let" statement, add a new scope.
     *          3)  When lookup table, lookup from the inner table to outer table.
     *  Complexity:
     *          O(N^2)
     */
    int idx;
    String expression;
    List<Map<String, Integer>> scope;
    
    public Solution() {
        this.scope = new ArrayList<>();
        this.scope.add(new HashMap<>());
    }
    
    public int evaluate(String expression) {
        this.idx = 0;
        this.expression = expression;
        return evaluate();
    }
    
    private int evaluate() {
        int n = this.expression.length();
        if (this.expression.charAt(this.idx) == '(') {  
            this.idx++;
            String opt = token();
            
            int val = 0; 
            // let
            //System.out.println(opt.equals("add"));
            if (opt.equals("let")) {
                Map<String, Integer> h = new HashMap<>();
                this.scope.add(h);
                while(true) {
                    // If its expr, return the val
                    if (this.expression.charAt(this.idx) == '(') {
                        val = evaluate();
                        break;
                    }
                    
                    String name = token();
                    // If its assignment, assign val to name.
                    if (this.expression.charAt(this.idx) != ')') {
                        h.put(name, evaluate());
                    } else {
                        // If its variable or number, return its value
                        val = evlSingle(name);
                        break;
                    }
                }
                this.scope.remove(this.scope.size() - 1);
            // add
            } else if (opt.equals("add")) {
                int e1 = evaluate();
                int e2 = evaluate();
                val = e1 + e2;
            // mult
            } else if (opt.equals("mult")) {
                int e1 = evaluate();
                int e2 = evaluate();
                val = e1 * e2;
            }
            this.idx++;
            removeSpace();
            return val;
        }
        String name = token();
        return evlSingle(name);
    }
    
    private String token() {
        int st = this.idx;
        char cur = this.expression.charAt(this.idx);
        int n = this.expression.length();
        while (this.idx < n && cur != ' ' && cur != ')') {
            this.idx++;
            cur = this.expression.charAt(this.idx);
        }
        
        String exp = this.expression.substring(st, this.idx);
        removeSpace();
        return exp;
    }
       
    private int evlSingle(String name) {
        char c = name.charAt(0);
        if (c == '-' || Character.isDigit(c)) {
            return Integer.parseInt(name);
        }
        int i = this.scope.size() - 1;
        for (; i >=0; i--) {
            if (this.scope.get(i).containsKey(name)) {
                return this.scope.get(i).get(name);
            }
        }
        return 0;
    }
    
    private void removeSpace() {
        while (this.idx < this.expression.length() && this.expression.charAt(this.idx) == ' ') {
            this.idx++;
        }
    }
}
__________________________________________________________________________________________________
sample 36744 kb submission
class Solution {
    public int evaluate(String expression) {
        if (expression == null || expression.length() == 0) {
            return 0;
        }
        
        return evaluate(expression, new HashMap<>());
    }
    
    private int evaluate(String expression, HashMap<String, Integer> outerScope) {
        char ch0 = expression.charAt(0);
        if (ch0 != '(') {
            if (Character.isDigit(ch0) || ch0 == '-') {
                return Integer.parseInt(expression);
            }
            return outerScope.get(expression);
        }
        
        HashMap<String, Integer> curScope = new HashMap<>();
        curScope.putAll(outerScope);
        List<String> tokens = parseExpression(expression);
        
        if (expression.startsWith("(a")) {
            return evaluate(tokens.get(0), curScope) + evaluate(tokens.get(1), curScope);
        } else if (expression.startsWith("(m")) {
            return evaluate(tokens.get(0), curScope) * evaluate(tokens.get(1), curScope);
        } else {
            for (int i = 0; i < tokens.size()-1; i+=2) {
                curScope.put(tokens.get(i), evaluate(tokens.get(i+1), curScope));
            }
            return evaluate(tokens.get(tokens.size()-1), curScope);
        }
    }
    
    private List<String> parseExpression(String expression) {
        List<String> tokens = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        int parenthesesSum = 0;
        int i = expression.startsWith("(m") ? 6 : 5;
        
        while (i < expression.length()-1) {
            char c = expression.charAt(i);
            if (c == ' ' && parenthesesSum == 0) {
                tokens.add(sb.toString());
                sb.setLength(0);
            } else {
                if (c == '(') {
                    parenthesesSum++;
                } else if (c == ')') {
                    parenthesesSum--;
                }
                sb.append(c);
            }
            i++;
        }
        
        if (sb.length() > 0) {
            tokens.add(sb.toString());
        }
        
        return tokens;
    }
}
__________________________________________________________________________________________________
