__________________________________________________________________________________________________
sample 28 ms submission
static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        vec.resize(k);
        head = 0, tail = -1;
        size = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
//        if (vec.size() == size)
        if (isFull())
            return false;

        tail = (tail + 1) % vec.size();               
        vec[tail] = value;
        size++;                
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
//        if (size == 0)
        if (isEmpty())
            return false;

        head = (head + 1) % vec.size();             
        size--;
        return true;       
    }
    
    /** Get the front item from the queue. */
    int Front() {
//        if (size == 0)
        if (isEmpty())            
            return -1;
        return vec[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
//        if (size == 0)
        if (isEmpty())            
            return -1;
        return vec[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (size == 0)
            return true;
        else
            return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (vec.size() == size)
            return true;
        else
            return false;
    }
    
private:
    vector<int> vec;
    int head, tail, size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
__________________________________________________________________________________________________
sample 16396 kb submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    vector<int> cache;
    int front;
    int rear;
    int cnt;
    int size;
    MyCircularQueue(int k) {
        cache=vector<int> (k);
        front=0;
        rear=0;
        cnt=0;
        size=k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(cnt==size) return false;
        cache[rear]=value;
        rear=(rear+1)%size;
        cnt++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(cnt==0) return false;
        front=(front+1)%size;
        cnt--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(cnt==0) return -1;
        return cache[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(cnt==0) return -1;
        return cache[(rear-1+size)%size];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return cnt==0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return cnt==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
__________________________________________________________________________________________________
