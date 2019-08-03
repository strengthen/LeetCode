__________________________________________________________________________________________________
sample 127 ms submission
class StreamChecker {

    private TrieNode root = new TrieNode();
    private StringBuilder buf = new StringBuilder();
    
    public StreamChecker(String[] words) {
        for (String one : words) {
            insert(one);
        }
    }
    
    private void insert(String word) {
        TrieNode cur = root;
        for (int i = word.length() -1; i >= 0; i--) {
            char c = word.charAt(i);
            if (cur.next[c-'a'] == null) {
                cur.next[c-'a'] = new TrieNode();
            }
            cur = cur.next[c-'a'];
        }
        cur.isEnd = true;
    }
    
    public boolean query(char letter) {
        buf.append(letter);
        TrieNode cur = root;
        for (int i = buf.length() - 1; i >= 0; i--) {
            char c = buf.charAt(i);
            cur = cur.next[c - 'a'];
            if (cur == null)
                return false;
            if (cur.isEnd) return true;
        }
        return false;
    }
    
    class TrieNode {
        boolean isEnd;
        TrieNode[] next = new TrieNode[26];
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */
__________________________________________________________________________________________________
sample 80120 kb submission
class StreamChecker {

    class TrieNode {
        boolean end;
        TrieNode[] children = new TrieNode[26];
    }

    TrieNode root;
    StringBuilder sb;
    int maxLen;

    public StreamChecker(String[] words) {
        root = new TrieNode();
        for(String w: words) {
            insert(w);
            maxLen = Math.max(maxLen, w.length());
        }
        sb = new StringBuilder();
    }

    void insert(String word) {
        TrieNode node = root;
        for(int i=word.length()-1;i>=0;i--) {
            char c = word.charAt(i);
            if(node.children[c-'a']==null) node.children[c-'a']=new TrieNode();
            node = node.children[c-'a'];
        }
        node.end = true;
    }

    public boolean query(char letter) {
        sb.append(letter);
        TrieNode node = root;
        for (int i = sb.length()-1; i >=0 && sb.length()-i<=maxLen ; i--) {
            char c = sb.charAt(i);
            node = node.children[c-'a'];
            if(node==null) break;
            if(node.end) return true;
        }
        return false;
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */
__________________________________________________________________________________________________
