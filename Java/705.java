__________________________________________________________________________________________________
sample 54 ms submission
class MyHashSet {
    boolean[] arr = new boolean[100];// start with 100 elements for fast initialization
    /** Initialize your data structure here. */
    public MyHashSet() {
        
    }
    
    public void add(int key) {
        if(key>=arr.length) // if array is too small to accomodate key, extend it.
            extend(key);
        arr[key]=true;
    }
    
    public void remove(int key) {
        if(key>=arr.length) // if array is too small to accomodate key, extend it.
            extend(key);
        arr[key]=false;
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        if(key>=arr.length) // key cannot be in array if array's length < key
            return false;
        return arr[key]==true;
    }
    
    public void extend(int key){
        arr= Arrays.copyOf(arr, key+2);  // extend array to one more item than necessary, we need "key" items. 
									     // we give "key+1" items to reduce collisions.
    }
}


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
__________________________________________________________________________________________________
sample 49504 kb submission
class MyHashSet {
    
    private BitSet bitset;
    
    /** Initialize your data structure here. */
    public MyHashSet() {
        this.bitset = new BitSet(1000000);        
    }
    
    public void add(int key) {
        this.bitset.set(key);    
    }
    
    public void remove(int key) {
        this.bitset.clear(key);      
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        return bitset.get(key);
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
__________________________________________________________________________________________________
