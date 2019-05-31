__________________________________________________________________________________________________
sample 40 ms submission
class MyQueue {
Stack<Integer> s1=new Stack<>();
        Stack<Integer> s2=new Stack<>();
    /** Initialize your data structure here. */
    public MyQueue() {
        
        
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
                s1.push(x);

    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if (s2.isEmpty()) {
        while (!s1.isEmpty())
            s2.push(s1.pop());
    }
    return s2.pop();  
    }
    
    /** Get the front element. */
    public int peek() {
        if(!s2.isEmpty()){
            return s2.peek();
        }
        else{
            while(!s1.isEmpty()){
                s2.push(s1.pop());
            }
            return s2.peek();
        }
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
           return s1.isEmpty() && s2.isEmpty();
 
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
__________________________________________________________________________________________________
sample 32624 kb submission
class MyQueue {
    Stack<Integer> queue;

    /** Initialize your data structure here. */
    public MyQueue() {
        this.queue = new Stack<Integer>();
        
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        Stack<Integer> tmp = new Stack<Integer>();
        if(queue.isEmpty())
            queue.push(x);
        else{
            while(!queue.isEmpty()){
                tmp.push(queue.pop());
            }
            tmp.push(x);
            
            while(!tmp.isEmpty()){
                queue.push(tmp.pop());
            }
        }
            
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return queue.pop();
        
    }
    
    /** Get the front element. */
    public int peek() {
        return queue.peek();
        
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        if(queue.size()>0)
            return false;
        else
            return true;
        
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
__________________________________________________________________________________________________
