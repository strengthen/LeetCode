__________________________________________________________________________________________________
sample 44 ms submission
class MyCircularQueue {
    int[] array;
    int head;
    int tail;
    int size;
    boolean isFull;
    boolean isEmpty;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        array = new int[k];
        head = -1;
        tail = -1;
        size = k;
        isFull = false;
        isEmpty = true;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        if (isFull) return false;
        if (isEmpty) isEmpty = false;
        
        head = (head+1)%size;
        array[head] = value;
        
        if ((head+1)%size==(tail+1)%size) isFull = true;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if (isEmpty) return false;
        if (isFull) isFull = false;
        
        tail = (tail+1)%size;        
        array[tail] = -1;
        
        if (head==tail) {tail = -1; head = -1; isEmpty = true;}
        return true;
    }
    
    /** Get the front item from the queue. */
    public int Front() {
        if (isEmpty) return -1;
        return array[(tail+1)%size];
    }
    
    /** Get the last item from the queue. */
    public int Rear() {
        if (isEmpty) return -1;
        return array[(head)%size];        
    }
    
    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return isEmpty;
    }
    
    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        return isFull;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */
__________________________________________________________________________________________________
sample 35952 kb submission
class MyCircularQueue {
    int[] array;
    int headIndex;
    int tailIndex;
    int size;

    public MyCircularQueue(int size) {
        array = new int[size];
        headIndex = -1;
        tailIndex = -1;
        this.size = size;
    }

    /**
     * Insert an element into the circular queue. Return true if the operation is successful.
     */
    public boolean enQueue(int value) {
        if (isFull()) {
            System.out.println("Queue is full");
            return false;
        }

        if (isEmpty()) {
            headIndex = 0;
            tailIndex = 0;
        } else {
            tailIndex = (tailIndex + 1) % size;
        }


        array[tailIndex] = value;
        return true;
    }

    /**
     * Delete an element from the circular queue. Return true if the operation is successful.
     */
    public boolean deQueue() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return false;
        }

        array[headIndex] = 0;

        if (headIndex == tailIndex) {
            headIndex = -1;
            tailIndex = -1;
            return true;
        }

        headIndex = (headIndex + 1) % size;

        return true;
    }

    /**
     * Get the front item from the queue.
     */
    public int Front() {
        if (headIndex != -1)
            return array[headIndex];

        return -1;
    }

    /**
     * Get the last item from the queue.
     */
    public int Rear() {
        if (tailIndex != -1)
            return array[tailIndex];

        return -1;
    }

    /**
     * Checks whether the circular queue is empty or not.
     */
    public boolean isEmpty() {
        return tailIndex == -1 & headIndex == -1;
    }

    /**
     * Checks whether the circular queue is full or not.
     */
    public boolean isFull() {
        return (tailIndex + 1) % size == headIndex;
    }
}
__________________________________________________________________________________________________
