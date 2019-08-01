__________________________________________________________________________________________________
sample 45 ms submission
class MapSum {

    TrieNode root;
    
    /** Initialize your data structure here. */
    public MapSum() {
        root = new TrieNode();
    }
    
    public void insert(String key, int val) {
        TrieNode node = root;
        for (int i = 0; i < key.length(); i++) {
            char c = key.charAt(i);
            if (node.children[c-'a'] == null) {
                node.children[c-'a'] = new TrieNode();
            }
            node = node.children[c-'a'];
        }
        node.isEnd = true;
        node.val = val;
    }
    
    public int sum(String prefix) {
        TrieNode node = root;
        for (int i = 0; i < prefix.length(); i++) {
            char c = prefix.charAt(i);
            if (node.children[c-'a'] == null) return 0;
            node = node.children[c-'a'];
        }
        return sumFromHere(node);
    }
    int sumFromHere(TrieNode node) {
        int sum = 0;
        if (node.isEnd) sum += node.val;
        
        for (TrieNode child: node.children) {
            if (child != null) sum += sumFromHere(child);
        }
        return sum;
    }
    
    class TrieNode {
        boolean isEnd;
        int val; // only used when isEnd = true;
        TrieNode[] children = new TrieNode[26];
        public TrieNode () {
            
        }
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
__________________________________________________________________________________________________
sample 36760 kb submission
class MapSum {
    Map<String, Integer> map;
    /** Initialize your data structure here. */
    public MapSum() {
        map = new HashMap<>();        
    }
    
    public void insert(String key, int val) {
        map.put(key, val);
    }
    
    public int sum(String prefix) {
        int ans = 0;
        for (String key : map.keySet()) {
            if (key.startsWith(prefix)) {
                ans += map.get(key);
            }
        }
        return ans;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
__________________________________________________________________________________________________
