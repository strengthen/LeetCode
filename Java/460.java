__________________________________________________________________________________________________
sample 55 ms submission
/*
 * @lc app=leetcode id=460 lang=java
 *  15% (91ms)
 * 
 * [460] LFU Cache
 */
class LFUCache {

    //*
    static class Node {
        int key;
        int val;
        int freq;
        Node next;
        Node pre;
        void remove() {
            pre.next = next;
            next.pre = pre;
        }
        void insert(Node insertPoint) {
            next = insertPoint;
            pre = insertPoint.pre;
            pre.next = next.pre = this;
        }
    }

    Node head = new Node();
    Map<Integer, Node> keyMap = new HashMap<>();
    List<Node> freqMap = new ArrayList<>();
    int cap;

    public LFUCache(int capacity) {
        cap = capacity;
        head.freq = -1;
        head.pre = head.next = head;
        freqMap.add(null);
    }
    
    public int get(int key) {
        Node n = keyMap.get(key);
        if (n == null) {
            return -1;
        }

        increseFreq(n);
        return n.val;
    }
    
    public void put(int key, int value) {
        Node n = keyMap.get(key);
        if (n == null) {
            if (keyMap.size() < cap) {
                n = new Node();
                n.insert(head);
            } else {
                n = head.pre;
                if (n == head) return;
                keyMap.remove(n.key);
                if (freqMap.get(n.freq) == n) {
                    freqMap.set(n.freq, null);
                }
            }
            n.key = key;
            n.freq = 0;
            keyMap.put(key, n);
        }
        n.val = value;

        increseFreq(n);
    }

    void increseFreq(Node n) {
        if (freqMap.get(n.freq) == n) {
            if (n.freq != n.next.freq) {
                freqMap.set(n.freq, null);
            } else {
                freqMap.set(n.freq, n.next);
            }
        }
        ++n.freq;
        while (freqMap.size() <= n.freq) {
            freqMap.add(null);
        }
        Node start = freqMap.get(n.freq);
        if (start == null) {
            start = freqMap.get(n.freq - 1);
        }
        if (start != null) {
            n.remove();
            n.insert(start);
        }

        freqMap.set(n.freq, n);
    }
__________________________________________________________________________________________________
sample 48676 kb submission
class LFUCache {

    private int mCount;
    private int mCapability;
    private Map<Integer, List<Integer>> mFreq2Keys;
    private Map<Integer, int[]> mKey2Vals;
    private int mLeastFreq;

    public LFUCache(int capacity) {
        mCount = 0;
        mCapability = capacity;
        mFreq2Keys = new HashMap<Integer, List<Integer>>();
        mKey2Vals = new HashMap<Integer, int[]>();
        mLeastFreq = 0;
    }
    
    public int get(int key) {
        if (mCapability <= 0) return -1;
        int[] value = mKey2Vals.get(key);
        if (value == null) return -1;
        List<Integer> l = mFreq2Keys.get(value[1]);
        l.remove(new Integer(key));
        if (l.size() == 0) {
            mFreq2Keys.remove(value[1]);
            if (mLeastFreq == value[1]) {
                mLeastFreq = value[1]+1;
            }
        }
        l = mFreq2Keys.get(++value[1]);
        if (l == null) {
            l = new ArrayList<Integer>();
            mFreq2Keys.put(value[1], l);
        }
        l.add(0, new Integer(key));
        return value[0];
    }
    
    public void put(int key, int value) {
        if (mCapability <= 0) return;
        if (mKey2Vals.containsKey(key)) {
            int[] val = mKey2Vals.get(key);
            val[0] = value;
            get(key);
            return;
        }
        if (mCount < mCapability) {
            mCount++;
            List<Integer> l = mFreq2Keys.get(1);
            if (l == null) {
                l = new ArrayList<Integer>();
                mFreq2Keys.put(1, l);
            }
            l.add(0, new Integer(key));
        } else {
            List<Integer> l = mFreq2Keys.get(mLeastFreq);
            int least = l.get(l.size()-1);
            mKey2Vals.remove(least);
            l.remove(l.size()-1);
            if (mLeastFreq == 1) {
                l.add(0, new Integer(key));
            } else {
                l = new ArrayList<Integer>();
                mFreq2Keys.put(1, l);
                l.add(key);
            }

        }
        mKey2Vals.put(key, new int[]{value, 1});
        mLeastFreq = 1;
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
__________________________________________________________________________________________________
