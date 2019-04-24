__________________________________________________________________________________________________
sample 4 ms submission
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		if (buf.size() == 0)
			buf.push(x);
		else
		{
			int sz = buf.size();
			while (!buf.empty())
			{
				tmpbuf.push(buf.front());
				buf.pop();
			}
			buf.push(x);
			while (!tmpbuf.empty())
			{
				buf.push(tmpbuf.front());
				tmpbuf.pop();
			}
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (buf.size() == 0)
			return 0;
		int x = buf.front();
		buf.pop();
		return x;
	}

	/** Get the top element. */
	int top() {
		return  buf.empty() ? 0: buf.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return buf.empty();
	}

private:
	queue<int> buf;
	queue<int> tmpbuf;
};
__________________________________________________________________________________________________
sample 8720 kb submission
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (Q.empty())
        {
            Q.push(x);
        }
        else
        {
            int qSize = Q.size();
            Q.push(x);
            while (qSize--)
            {
                Q.push(Q.front());
                Q.pop();
            }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = Q.front();
        Q.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        if (!Q.empty())
            return Q.front();
        
        return -1;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.empty();
    }
    
private:
    queue<int> Q;
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
__________________________________________________________________________________________________
