__________________________________________________________________________________________________
sample 40 ms submission
class MyStack {
    Queue<Integer> queue1;
    Queue<Integer> queue2;
    /** Initialize your data structure here. */
    public MyStack() {
        queue1 = new LinkedList<>();
        
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        queue1.add(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        queue2 = new LinkedList<>();
        int size = queue1.size();
        for(int i=0 ; i<size-1; i++){
           int val =  queue1.poll();
            queue2.add(val);
        }
        int value = queue1.poll();
        queue1 = queue2;
        return value;
    }
    
    /** Get the top element. */
    public int top() {
        queue2 = new LinkedList<>();
        int size = queue1.size();
        for(int i=0 ; i<size-1; i++){
           int val =  queue1.poll();
            queue2.add(val);
        }
        int value = queue1.peek();
        queue2.add(value);
        queue1 = queue2;
        return value;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue1.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
__________________________________________________________________________________________________
sample 32636 kb submission
class MyStack {

    
    int st[] = new int[30];
    int p = 0;
    
    /** Initialize your data structure here. */
    public MyStack() {
        
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        st[p++] = x;      
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return st[--p];
    }
    
    /** Get the top element. */
    public int top() {
        return st[p-1];
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return p==0;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
__________________________________________________________________________________________________
sample 41 ms submission
class MyStack {

    Queue<Integer> queue;
    
    /** Initialize your data structure here. */
    public MyStack() {
        queue = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        queue.offer(x);
        int size = queue.size();
        while(size > 1){
            queue.offer(queue.poll());
            size--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return queue.poll();
    }
    
    /** Get the top element. */
    public int top() {
        return queue.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */