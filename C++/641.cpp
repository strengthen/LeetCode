__________________________________________________________________________________________________
sample 28 ms submission
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class MyCircularDeque {
public:
	MyCircularDeque(int k): data(k), front(0), back(0), empty(true) {}
	bool insertFront(int value) {
		if (isFull())
			return false;
		front = (front + data.size() - 1) % data.size();
		data[front] = value;
		empty = false;
		return true;
	}
	bool insertLast(int value) {
		if (isFull())
			return false;
		data[back] = value;
		back = (back + 1) % data.size();
		empty = false;
		return true;
	}
	bool deleteFront() {
		if (empty)
			return false;
		front = (front + 1) % data.size();
		empty = front == back;
		return true;
	}
	bool deleteLast() {
		if (empty)
			return false;
		back = (back + data.size() - 1) % data.size();
		empty = front == back;
		return true;
	}
	int getFront() { return empty ? -1 : data[front]; }
	int getRear() { return empty ? -1 : data[(back + data.size() - 1) % data.size()]; }
	bool isEmpty() { return empty; }
	bool isFull() { return !empty && front == back; }

private: 
	vector<int> data;
	int front, back;
	bool empty;
};
__________________________________________________________________________________________________
sample 16536 kb submission
class MyCircularDeque {
    int size, k, front, back;
    vector<int> store;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : size(0), k(k), front(1), back(0) {
        store.resize(k);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(size==k)
            return false;
        front = (front + k - 1) % k;
        store[front] = value;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(size==k)
            return false;
        back = (back + 1) % k;
        store[back] = value;
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(size==0)
            return false;
        front = (front + 1) % k;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(size==0)
            return false;
        back = (back + k - 1) % k;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return size == 0? -1 : store[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return size == 0? -1 : store[back];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */
__________________________________________________________________________________________________
