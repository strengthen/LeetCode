__________________________________________________________________________________________________
class Solution {
    public List<String> braceExpansionII(String expression) {
        Stack<String> stack = new Stack<>();
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            
            if (c == '}') {
                resolveBrackets(stack);
            } else if (c == '{'){
                stack.push(c + "");
            } else if (c == ',') {
                stack.push(c + "");
            } else {
                // Collect entire string
                StringBuilder sb = new StringBuilder();
                while(i < expression.length()) {
                    sb.append(expression.charAt(i)+"");
                    if (i + 1 < expression.length() && expression.charAt(i+1) != '{' && expression.charAt(i+1) != '}' && expression.charAt(i+1) != ',') {
                        i++;
                    } else {
                        break;
                    }
                }
                
                stack.push(sb.toString());
            }
            // Do cartesian product after each iteration
            cartesian(stack);
        }
        
        return extractResult(stack);
    }
    
    private List<String> extractResult(Stack<String> stack) {
        List<String> ret = new ArrayList<String>();
        String top = stack.pop();
        String[] arr = top.split(",");
        
        // Add to a set to resolve duplicates
        Set<String> set = new HashSet<>();
        for (String s : arr) {
            set.add(s);
        }
        
        // Add to an array to sort the results
        String[] sortedArr = new String[set.size()];
        int i = 0;
        for (String s : set) {
            sortedArr[i++] = s;
        }
        
        // Sort
        Arrays.sort(sortedArr);
        for (String s : sortedArr) {
            ret.add(s);
        }
        
        return ret;
    }
    
    private void resolveBrackets(Stack<String> stack) {
        StringBuilder sb = new StringBuilder();
        List<String> collect = new ArrayList<String>();
        while(!stack.isEmpty()) {
            String top = stack.pop();
            if (top.equals("{")) {
                Collections.reverse(collect);
                for (String s : collect) {
                    sb.append(s);
                }
                stack.push(sb.toString());
                break;
            } else {
                collect.add(top);
            }
        }
    }

    private void cartesian(Stack<String> stack) {
        while(!stack.isEmpty() && !stack.peek().equals(",") && !stack.peek().equals("{")) {
            String B = stack.pop();
            if (stack.isEmpty() || stack.peek().equals(",") || stack.peek().equals("{")) {
                stack.push(B);
                break;
            }
            String A = "";
            if(!stack.isEmpty() && !stack.peek().equals(",") && !stack.peek().equals("{")) {
                A = stack.pop();    
            }
            if (A.isEmpty()) {
                stack.push(B);
            } else {
                String[] A_Arr = A.split(",");
                String[] B_Arr = B.split(",");
                StringBuilder sb = new StringBuilder();
                String prefix = "";
                for (String a : A_Arr) {
                    for (String b : B_Arr) {
                        sb.append(prefix);
                        prefix = ",";
                        sb.append(a + b);
                    }
                }
                stack.push(sb.toString());
            }
        }
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
