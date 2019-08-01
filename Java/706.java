__________________________________________________________________________________________________
sample 52 ms submission
class MyHashMap
{
	ListNode[] nodes = new ListNode[10000];

	public int get(int key)
	{
		int index = getIndex(key);
		ListNode prev = findElement(index, key);
		return prev.next == null ? -1 : prev.next.val;
	}
	
	public void put(int key, int value)
	{
		int index = getIndex(key);
		ListNode prev = findElement(index, key);
		
		if (prev.next == null)
			prev.next = new ListNode(key, value);
		else 
			prev.next.val = value;
	}

	public void remove(int key)
	{
		int index = getIndex(key);
        ListNode prev = findElement(index, key);
			
        if(prev.next != null)
		    prev.next = prev.next.next;
	}

	private int getIndex(int key)
	{	
		return Integer.hashCode(key) % nodes.length;
	}

	private ListNode findElement(int index, int key)
	{
		if(nodes[index] == null)
			return nodes[index] = new ListNode(-1, -1);
        
        ListNode prev = nodes[index];
		
		while(prev.next != null && prev.next.key != key)
		{
			prev = prev.next;
		}
		return prev;
	}

	private static class ListNode
	{
		int key, val;
		ListNode next;

		ListNode(int key, int val)
		{
			this.key = key;
			this.val = val;
		}
	}
}
__________________________________________________________________________________________________
sample 42908 kb submission
class MyHashMap {
    
    Node[] tab;
    int size;

    /** Initialize your data structure here. */
    public MyHashMap() {
        // int i = 1;
        // while(i <= 10000) {
        //     i = i << 1;
        // }
        size = 16384;
        tab = new Node[size];
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
        Node n = find(key);
        if (n != null) {
            n.val = value;
        } else {
            int index = idx(key);
            Node newN = new Node(key, value);
            newN.next = tab[index];
            tab[index] = newN;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        Node n = find(key);
        if (n != null) {
            return n.val;
        } else {
            return -1;
        }
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        Node n = find(key);
        if (n != null) {
            n.val = -1;
        }
    }
    
    private int idx(int key) {
        return (size-1) & (key ^ (key >>> 10));
    }
    
    private Node find(int key) {
        Node cur = tab[idx(key)];
        while(cur != null) {
            if (cur.key == key) {
                return cur;
            }
            cur = cur.next;
        }
        return null;
    }
    
    class Node {
        int val;
        int key;
        Node next;
        Node(int key, int val) {
            this.val = val;
            this.key = key;
        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
__________________________________________________________________________________________________
