__________________________________________________________________________________________________
sample 57 ms submission
class AllOne {
    class Node {
        int val;
        Node prev;
        Node next;
        String key;
        
        public Node(int val, String key) {
            this.val = val;
            this.key = key;
            this.prev = null;
            this.next = null;
        }
    }
    
    Map<String, Node> map;
    Node head;
    Node tail;

    /** Initialize your data structure here. */
    public AllOne() {
        this.map = new HashMap<>();
        this.head = new Node(Integer.MIN_VALUE, "");
        this.tail = new Node(Integer.MAX_VALUE, "");
        head.next = tail;
        tail.prev = head;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    public void inc(String key) {
        Node node = map.get(key);
        if(node == null) {
            Node cur = new Node(1, key);
            map.put(key, cur);
            addNode(head, cur);
        } else {
            int val = node.val;
            node.val = val + 1;
            moveNext(node);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    public void dec(String key) {
        Node node = map.get(key);
        if(node == null) {
            return;
        } else {
            if(node.val == 1) {
                deleteNode(node);
                map.remove(key);
            } else {
                int val = node.val;
                node.val = val - 1;
                moveAhead(node);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    public String getMaxKey() {
        if(map.isEmpty()) {
            return "";
        }
        return tail.prev.key;
    }
    
    /** Returns one of the keys with Minimal value. */
    public String getMinKey() {
        if(map.isEmpty()) {
            return "";
        }
        return head.next.key;
    }
    
    private void addNode(Node before, Node node) {
        node.next = before.next;
        node.prev = before;
        before.next.prev = node;
        before.next = node;
    }
    
    private void deleteNode(Node node) {
        node.next.prev = node.prev;
        node.prev.next = node.next;
    }
    
    private void moveNext(Node node) {
        Node next = node.next;
        while(node.val > next.val) {
            next = next.next;
        }
        deleteNode(node);
        addNode(next.prev, node);
    }
    
    private void moveAhead(Node node) {
        Node before = node.prev;
        while(node.val < before.val) {
            before = before.prev;
        }
        deleteNode(node);
        addNode(before, node);
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */
__________________________________________________________________________________________________
sample 41096 kb submission
class AllOne {
    
    class ListNode {
        String key;
        int val;
        ListNode prev;
        ListNode next;
        
        ListNode(String key) {
            this.key = key;
            val = 1;
            prev = null;
            next = null;
        }
    }
    
    Map<String, ListNode> pointers;
    List<ListNode> nodes;
    int min;
    int max;
    int inputs;

    /** Initialize your data structure here. */
    public AllOne() {
        this.pointers = new HashMap<>();
        this.nodes = new ArrayList<>();
        nodes.add(null);
        min = Integer.MAX_VALUE;
        max = Integer.MIN_VALUE;
        inputs = 1;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    public void inc(String key) {
        inputs++;
        ListNode ptr;
        if (pointers.containsKey(key)) {
            ptr = pointers.get(key);
            removePointer(ptr);
            ptr.val++;
        } else {
            ptr = new ListNode(key);
            pointers.put(key, ptr);
        }
        addPointer(ptr);
        max = Math.max(ptr.val, max);
        min = Math.min(ptr.val, min);
        if (nodes.get(min) == null) {
            min++;
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    public void dec(String key) {
        if (pointers.containsKey(key)) {
            ListNode ptr = pointers.get(key);
            removePointer(ptr);
            ptr.val--;
            if (ptr.val > 0) { // add to list below
                addPointer(ptr);
                min = Math.min(ptr.val, min);
                if (nodes.get(max) == null) {
                    max = ptr.val - 1;
                }
            } else { // ptr = 0 : remove from pointers
                pointers.remove(key);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    public String getMaxKey() {
        return (max == Integer.MIN_VALUE) ? "" : nodes.get(max).key;
    }
    
    /** Returns one of the keys with Minimal value. */
    public String getMinKey() {
        for (int i = 0; i < inputs; i++) {
            if (nodes.get(i) != null) {
                return nodes.get(i).key;
            }
        }
        return "";
        // return (min == Integer.MAX_VALUE) ? "" : nodes.get(min).key;
    }
    private void removePointer(ListNode ptr) {
        if (ptr.prev != null) {
            ptr.prev.next = ptr.next;
        }
        if (ptr.next != null) {
            ptr.next.prev = ptr.prev;
        }
        if (nodes.get(ptr.val) == ptr) { // head element for this val: move head to next
            nodes.set(ptr.val, ptr.next);
        }
        ptr.prev = null;
        ptr.next = null;
    }
    private void addPointer(ListNode ptr) {
        int index = ptr.val;
        if (nodes.size() <= index) {
            nodes.add(ptr);
            return;
        }
        ListNode oldHead = nodes.get(index);
        nodes.set(index, ptr);
        if (oldHead != null) {
            oldHead.prev = ptr;
            ptr.next = oldHead;
        }
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */
__________________________________________________________________________________________________
