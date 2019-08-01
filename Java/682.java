__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int calPoints(String[] ops) {
        String[] arrayWithoutC = new String[ops.length];
        int altI = 0;
        
        for (int i = 0; i < ops.length; ++i) {
            switch (ops[i]) {
                case "C":
                    if (altI > 0) {
                        --altI;
                        arrayWithoutC[altI] = null;
                    }
                    break;
                default:
                    arrayWithoutC[altI] = ops[i];
                    ++altI;
            }
        }
        
        int sum = 0;
        int prev = 0;
        int prev2 = 0;
        int newPrev = 0;
        
        for (String op : arrayWithoutC) {
            if (op == null) {
                continue;
            }
            
            switch (op) {
                case "+":
                    newPrev = prev + prev2;
                    break;
                case "D":
                    newPrev = prev * 2;
                    break;
                default:
                    newPrev = Integer.parseInt(op);
            }
            
            sum += newPrev;
            prev2 = prev;
            prev = newPrev;
        }
        
        return sum;
    }
}
__________________________________________________________________________________________________
sample 34920 kb submission
class Solution {
    public int calPoints(String[] ops) {
       Stack<Integer> stack = new Stack();

        for(String op : ops) {
            if (op.equals("+")) {
                int top = stack.pop();
                int newtop = top + stack.peek();
                stack.push(top);
                stack.push(newtop);
            } else if (op.equals("C")) {
                stack.pop();
            } else if (op.equals("D")) {
                stack.push(2 * stack.peek());
            } else {
                stack.push(Integer.valueOf(op));
            }
        }

        int ans = stack.stream().mapToInt(Integer::intValue).sum();
       // for(int score : stack) ans += score;
        return ans; 
    }
}
__________________________________________________________________________________________________
