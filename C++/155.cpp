__________________________________________________________________________________________________
24ms
class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> values;   
    stack<int> min;
    
    
    void push(int x) {
        if(min.empty() || x <= min.top()) min.push(x);
        values.push(x);class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> values;   
    stack<int> min;
    
    
    void push(int x) {
        if(min.empty() || x <= min.top()) min.push(x);
        values.push(x);
    }
    
    void pop() {
        if(min.top() == values.top() )min.pop();
        values.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
    }
    
    void pop() {
        if(min.top() == values.top() )min.pop();
        values.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return min.top();
    }
};
static const auto speedup = [](){                                            ios::sync_with_stdio( false ); cin.tie( nullptr ); return 0;         }(); 
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
__________________________________________________________________________________________________

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        int result = stack[0];
        for (auto item: stack)
        {
            if (result > item)
                result = item;
        }
        return result;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
__________________________________________________________________________________________________
