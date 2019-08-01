__________________________________________________________________________________________________
sample 44 ms submission
class MagicDictionary {
    /** Initialize your data structure here. */
    class TrieNode {
        TrieNode[] children;
        boolean isWord;
        TrieNode() {
            this.children = new TrieNode[26];
            isWord = false;
        }
    }
    
    TrieNode root;
    public MagicDictionary() {
        root = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    public void buildDict(String[] dict) {
        for (String word : dict) {
            insert(word);
        }
    }
    
    private void insert(String word) {
        TrieNode curNode = root;
        for (char c : word.toCharArray()) {
            if (curNode.children[c - 'a'] == null) {
                curNode.children[c - 'a'] = new TrieNode();
            }
            curNode = curNode.children[c - 'a'];
        }
        curNode.isWord = true;
    }
    
    /*
        wood
                            #
                               \
                                 w
                                   \
                                     o              
                                        \
                                          r
                                            \
                                              d 
            
    */
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    public boolean search(String word) {
        TrieNode curNode = root;
        int startIndex = 0, len = word.length();
        while (startIndex < len) {
            char curChar = word.charAt(startIndex);
            for (int i = 0; i < 26; i ++) {
                if ((char)i + 'a' != curChar && 
                    curNode.children[i] != null && 
                    searchHelper(curNode.children[i], word, startIndex + 1)) {
                    return true;
                }
            }
            
            if (curNode.children[curChar - 'a'] != null) {
                curNode = curNode.children[curChar - 'a'];
            } else {
                break;
            }
            
            startIndex ++;
        }
        
        return false;
    }
    
    private boolean searchHelper(TrieNode node, String word, int startIndex) {
        //base case:
        if (startIndex == word.length()) {
            return node.isWord;
        }
        
        //induction cases:
        char curChar = word.charAt(startIndex);
        if (node.children[curChar - 'a'] == null) {
            return false;
        }
        
        return searchHelper(node.children[curChar - 'a'], word, startIndex + 1);
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * boolean param_2 = obj.search(word);
 */
__________________________________________________________________________________________________
sample 36700 kb submission
class MagicDictionary {
    
    class TrieNode {
        TrieNode[] children;
        boolean isWord;
        
        TrieNode() {
            children = new TrieNode[26];
            isWord = false;
        }
    }

    /** Initialize your data structure here. */
    private TrieNode root;
    
    public MagicDictionary() {
        root = new TrieNode();
    }
    
    private void insert(String w) {
        TrieNode cur = this.root;
        for (char ch : w.toCharArray()) {
            if (cur.children[ch - 'a'] == null) {
                cur.children[ch - 'a'] = new TrieNode();
            }
            cur = cur.children[ch - 'a'];
        }
        cur.isWord = true;
    }
    
    /** Build a dictionary through a list of words */
    public void buildDict(String[] dict) {
        for (String w : dict) {
            insert(w);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    public boolean search(String word) {
        TrieNode cur = this.root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            for (int j = 0; j < 26; j++) {
                if (j != ch - 'a') {
                    if (search(cur.children[j], word.substring(i+1))) return true;
                }
            }
            if (cur.children[ch - 'a'] == null) return false;
            cur = cur.children[ch - 'a'];
        }
        return false;
    }
    
    private boolean search(TrieNode r, String word) {
        TrieNode cur = r;
        if (cur == null) return false;
        for (char ch : word.toCharArray()) {
            if (cur.children[ch - 'a'] == null) return false;
            cur = cur.children[ch - 'a'];
        }
        return cur.isWord;
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * boolean param_2 = obj.search(word);
 */
__________________________________________________________________________________________________
