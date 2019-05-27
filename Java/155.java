__________________________________________________________________________________________________
sample 43 ms submission
// how do I know the new min if I pop the current min?
// solution => push the old min when we found a new min, in push()

class MinStack {    
    int min = Integer.MAX_VALUE;
    Stack<Integer> stack;
    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<>();
    }
    
    public void push(int x) {
        if (x <= min) {
            stack.push(min);
            min = x;
        }
        stack.push(x);
    }
    
    public void pop() {
        if (stack.pop() == min) {
            min = stack.pop();
        }
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
__________________________________________________________________________________________________
sample 36480 kb submission
public class MinStack {

    /**
     * initialize your data structure here.
     */
    int size;
    int[] elements;
    int[] min;

    public MinStack() {
        size = 0;
        elements = new int[10000];
        min = new int[10000];
    }

    public void push(int x) {
        elements[size] = x;
        min[size] = Math.min(x, size == 0 ? Integer.MAX_VALUE : min[size - 1]);
        size++;
    }

    public void pop() {
        size--;
    }

    public int top() {
        return elements[size - 1];

    }

    public int getMin() {
        return min[size - 1];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
__________________________________________________________________________________________________
