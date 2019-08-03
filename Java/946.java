__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int[] stack = new int[pushed.length];
        int i = 0, top = -1;
        for (int p : pushed) {
            stack[++top] = p;
            while (top > -1 && stack[top] == popped[i]) {
                --top;
                ++i;
            }
        }
        return top == -1;
    }
}
__________________________________________________________________________________________________
sample 38108 kb submission
class Solution {
        public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stk = new Stack<>();
        int i = 0;
        for (int p : pushed) {
            stk.push(p);
            while (!stk.isEmpty() && stk.peek() == popped[i]) {
                stk.pop();
                ++i;
            }
        }
        return stk.empty();
    }
}
__________________________________________________________________________________________________
