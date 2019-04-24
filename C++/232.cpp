__________________________________________________________________________________________________
sample 4 ms submission
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        int first = 0;
        while(!st.empty())
        {
            tmp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!tmp.empty())
        {
            st.push(tmp.top());
            tmp.pop();
        }
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int last = st.top();
        st.pop();
        return last;
    }
    
    /** Get the front element. */
    int peek() {
        return st.top();
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
    
private:
    stack<int> st;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
__________________________________________________________________________________________________
sample 8724 kb submission
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if (s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top = s2.top();
        return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s1.empty() && s2.empty()){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
__________________________________________________________________________________________________
