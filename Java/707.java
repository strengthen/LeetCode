__________________________________________________________________________________________________
sample 47 ms submission
class MyLinkedList {
    private int start;
    private int size;
    private int capacity;
    private int[] storage;

    private void adjustCapacity(int capacity) {
        int[] storage = new int[capacity];
        System.arraycopy(this.storage, start, storage, 0, this.size - start);
        System.arraycopy(this.storage, 0, storage, this.size - start, start);
        start = 0;

        this.storage = storage;
        this.capacity = capacity;
    }

    /**
     * Initialize your data structure here.
     */
    public MyLinkedList() {
        start = 0;
        capacity = 1;
        storage = new int[capacity];
    }

    /**
     * Get the value of the index-th node in the linked list. If the index is invalid, return -1.
     */
    public int get(int index) {
        if (index < 0 || index >= size) return -1;
        return storage[(start + index) % capacity];
    }

    /**
     * Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
     */
    public void addAtHead(int val) {
        addAtIndex(0, val);
    }

    /**
     * Append a node of value val to the last element of the linked list.
     */
    public void addAtTail(int val) {
        addAtIndex(size, val);
    }

    /**
     * Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
     */
    public void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;

        if (index == 0) {
            start = (start + capacity - 1) % capacity;
            storage[start] = val;
        } else if (index == size) {
            storage[(start + size) % capacity] = val;
        } else if (index >= size / 2) {
            if (start + size < capacity) {
                System.arraycopy(storage, start + index, storage, start + index + 1, size - index);
            } else if (start + index >= capacity) {
                System.arraycopy(storage, (start + index) % capacity, storage, (start + index + 1) % capacity, size - index);
            } else {
                int t = storage[capacity - 1];
                System.arraycopy(storage, start + index, storage, start + index + 1, capacity - start - index - 1);
                System.arraycopy(storage, 0, storage, 1, size - capacity + start + index + 1);
                storage[0] = t;
            }
            storage[(start + index) % capacity] = val;
        } else {
            if (start == 0) {
                storage[capacity - 1] = storage[0];
                System.arraycopy(storage, 1, storage, 0, index - 1);
            } else if (start + index <= capacity) {
                System.arraycopy(storage, start, storage, start - 1, index);
            } else {
                System.arraycopy(storage, start, storage, start - 1, capacity - start);
                storage[capacity - 1] = storage[0];
                System.arraycopy(storage, 1, storage, 0, index - capacity + start);
            }

            storage[(start + index - 1) % capacity] = val;
            start = (start + capacity - 1) % capacity;
        }

        size++;

        if (size == capacity) adjustCapacity(capacity * 2);
    }

    /**
     * Delete the index-th node in the linked list, if the index is valid.
     */
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index >= size / 2) {
            if (start + size <= capacity) {
                System.arraycopy(storage, start + index + 1, storage, start + index, size - index - 1);
            } else if (start + index >= capacity) {
                System.arraycopy(storage, start + index + 1 - capacity, storage, start + index - capacity, size - index - 1);
            } else {
                System.arraycopy(storage, start + index + 1, storage, start + index, capacity - start - index - 1);
                storage[capacity - 1] = storage[0];
                System.arraycopy(storage, 1, storage, 0, start + size - capacity - 1);
            }
            storage[(start + size + capacity - 1) % capacity] = 0;
        } else {
            if (start + index < capacity) {
                System.arraycopy(storage, start, storage, start + 1, index);
            } else {
                int t = storage[capacity - 1];
                System.arraycopy(storage, start, storage, start + 1, capacity - start - 1);
                System.arraycopy(storage, 0, storage, 1, index - capacity + start);
                storage[0] = t;
            }
            storage[start] = 0;
            start = (start + 1) % capacity;
        }

        size--;
        if (size == capacity / 4) adjustCapacity((capacity / 2));
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
__________________________________________________________________________________________________
sample 42792 kb submission
class MyLinkedList {

   List<Integer> list;
    int len;
    /** Initialize your data structure here. */
    public MyLinkedList() {
        list = new ArrayList<>();
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if(index < 0 || index >= len || len == 0) return -1;
        return list.get(index);
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        list.add(0,val);
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        list.add(val);
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if(index > len) return;
        if(index < 0){
            list.add(0,val);
        }else if(index == len){
            list.add(val);  
        } else{
            list.add(index,val);
        }
        len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if(index < 0 || index >= len || len == 0) return;
        list.remove(index);
        len--;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
__________________________________________________________________________________________________
