__________________________________________________________________________________________________
sample 71 ms submission
class Trie {

    private boolean isKey;
    private Trie[] next;

    /**
     * Initialize your data structure here.
     */
    public Trie() {
        isKey = false;
        next = new Trie[26];
    }

    /**
     * Inserts a word into the trie.
     */
    public void insert(String word) {
        char[] w = word.toCharArray();

        Trie trie = this;
        for (char c : w) {
            if (trie.next[c - 'a'] == null) trie.next[c - 'a'] = new Trie();
            trie = trie.next[c - 'a'];
        }
        trie.isKey = true;
    }

    /**
     * Returns if the word is in the trie.
     */
    public boolean search(String word) {
        char[] w = word.toCharArray();
        Trie trie = this;
        for (char c : w) {
            if (trie.next[c - 'a'] == null) return false;
            trie = trie.next[c - 'a'];
        }
        return trie.isKey;

    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {
        char[] w = prefix.toCharArray();
        Trie trie = this;
        for (char c : w) {
            if (trie.next[c - 'a'] == null) return false;
            trie = trie.next[c - 'a'];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
__________________________________________________________________________________________________
sample 48208 kb submission
class Trie {

    /** Initialize your data structure here. */
    TreeSet<String> set;
    public Trie() {
        set = new TreeSet<>();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        if(!set.contains(word))
            set.add(word);
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        return set.contains(word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        if(set.size()==0)
            return false;
        String s = set.ceiling(prefix);
        if(s!=null)
            return s.startsWith(prefix);
        else
            return false;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
__________________________________________________________________________________________________
