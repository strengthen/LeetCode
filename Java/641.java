__________________________________________________________________________________________________
sample 44 ms submission
class MyCircularDeque {

    int[] a;
    int front = 0;
    int rear = -1;
    int len = 0;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    public MyCircularDeque(int k) {
        a = new int[k];
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    public boolean insertFront(int value) {
        if(isFull()){
            return false;
        }else{
            front = front == 0 ? a.length - 1 : (front - 1) % a.length;
            a[front] = value;
            len ++;
            if(len == 1){ // very important step
                rear = front;
            }
            return true;
        }  
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    public boolean insertLast(int value) {
        if(isFull()){
            return false;
        }else{
            rear = (rear + 1) % a.length;
            a[rear] = value;
            len ++;
            return true;
        } 
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    public boolean deleteFront() {
        if(isEmpty()){
            return false;
        }else{
            front = (front + 1) % a.length;
            len --;
            return true;
        }
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    public boolean deleteLast() {
        if(isEmpty()){
            return false;
        }else{
            rear = rear == 0 ? a.length - 1 : (rear - 1) % a.length;
            len --;
            return true;
        }
    }
    
    /** Get the front item from the deque. */
    public int getFront() {
        return isEmpty() ? -1 : a[front];
    }
    
    /** Get the last item from the deque. */
    public int getRear() {
        return isEmpty() ? -1 : a[rear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    public boolean isEmpty() {
        return len == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    public boolean isFull() {
        return len == a.length;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */
__________________________________________________________________________________________________
sample 35844 kb submission
class MyCircularDeque {
    
    int count = 0;
    int[] deque;
    int front = 0;
    int rear = 0;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    public MyCircularDeque(int k) {
        deque = new int[k];
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    public boolean insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
            deque[front] = value;
        } else {
            front = (front + deque.length - 1) % deque.length;
            deque[front] = value;
        }
        ++count;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    public boolean insertLast(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
            deque[rear] = value;
        } else {
            rear = (rear + 1) % deque.length;
            deque[rear] = value;
        }
        ++count;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    public boolean deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % deque.length;
        --count;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    public boolean deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear + deque.length - 1) % deque.length;
        --count;
        return true;
    }
    
    /** Get the front item from the deque. */
    public int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return deque[front];
    }
    
    /** Get the last item from the deque. */
    public int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return deque[rear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    public boolean isEmpty() {
        return count == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    public boolean isFull() {
        return count == deque.length;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */
__________________________________________________________________________________________________
