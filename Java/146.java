__________________________________________________________________________________________________
sample 53 ms submission
class LRUCache extends LinkedHashMap<Integer, Integer>{
    private int capacity;
    
    public LRUCache(int capacity) {
        super(capacity, 1F, true);
        this.capacity = capacity;
    }

    public int get(int key) {
        return super.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        super.put(key, value);
    }

    @Override
    protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
        return size() > capacity; 
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
__________________________________________________________________________________________________
sample 47784 kb submission
class LRUCache {
    // naive way: list of size n, each time, put the hit in the tail, always remove head.
    // time: get O(n), put O(n)
    // use hashMap to facilitate look up. we could locate the element in list in O(1), to achieve O(1) delete/update, we need to know previous element in the list, so we need double linkedList 
    // so need map: key -> node in list. and we should also able to get map entry using list node(when removing head)
    private class ListNode{
        int key, val;
        ListNode pre, next;
        public ListNode(int key, int val){
            this.key = key;
            this.val = val;
            this.pre = this.next = null;
        }
    }
    private int cap;
    private HashMap<Integer, ListNode> map;
    private ListNode head, tail;
    
    public LRUCache(int capacity) {
        this.cap = capacity;
        this.map = new HashMap();
        this.head = new ListNode(-1, -1);
        this.tail = new ListNode(-1, -1);
        this.head.next = this.tail;
        this.tail.pre = this.head;
    }

    
    public int get(int key) {
        int ret = -1;
        if(this.map.containsKey(key)){
            ListNode hit = this.map.get(key);
            ret = hit.val;
            this.putToTail(hit);
        }
        return ret;
    }
    
    public void put(int key, int value) {
        this.map.computeIfPresent(key, (k, v)->{
            ListNode hit = this.map.get(key);
            hit.val = value;
            this.putToTail(hit);
            return hit;
        });  
        
        this.map.computeIfAbsent(key, k ->{
            // add new node to the tail
            ListNode toAdd = new ListNode(k, value);
            toAdd.pre = this.tail.pre;
            toAdd.next = this.tail;
            this.tail.pre.next = toAdd;
            this.tail.pre = toAdd;
            if(this.map.size() == cap){
                ListNode toRmv = this.head.next;
                toRmv.next.pre = this.head;
                this.head.next = toRmv.next;
                this.map.remove(toRmv.key);
            }
            return toAdd;
        }); 
    }
    
    private void putToTail(ListNode node){
        node.pre.next = node.next;
        node.next.pre = node.pre;
        node.pre = this.tail.pre;
        node.next = this.tail;
        this.tail.pre.next = node;
        this.tail.pre = node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
__________________________________________________________________________________________________
