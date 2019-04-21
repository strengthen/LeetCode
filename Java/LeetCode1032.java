__________________________________________________________________________________________________
99ms
class TrieNode {
    boolean is_word;
    TrieNode [] children;
    
    public TrieNode() {
        is_word = false;
        children = new TrieNode[26];
    }
}


class StreamChecker {
    TrieNode root;
    List<Character> stream;
    public StreamChecker(String[] words) {
        stream = new ArrayList<>();
        root = new TrieNode();
        for(String word : words) {
            int m = word.length();
            TrieNode cur = root;
            for(int i = m - 1; i >= 0; --i) {
                if(cur.children[word.charAt(i) - 'a'] == null) {
                    cur.children[word.charAt(i) - 'a'] = new TrieNode();
                }
                cur = cur.children[word.charAt(i) - 'a'];
            }
            cur.is_word = true;
        }
    }
    
    public boolean query(char letter) {
        stream.add(letter);
        int m = stream.size();
        TrieNode cur = root;
        for(int i = m - 1; i >= 0; --i) {
            cur = cur.children[stream.get(i) - 'a'];
            if (cur == null) return false;
            else if (cur.is_word) return true;
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
112ms
class StreamChecker {
    Node dummy;
    List<Character> list;

    public StreamChecker(String[] words) {
        dummy = new Node();
        list = new LinkedList<>();
        Node cur;
        for(String word : words) {
            cur = dummy;
            
            for(int i =  word.length() - 1; i >= 0; i--) {
                char c = word.charAt(i);
                
                if(cur.nodes[c - 'a'] == null) {
                    cur.nodes[c - 'a']  =  new Node();
                }
                
                cur = cur.nodes[c - 'a'];
                
                if(i == 0) {
                    cur.isWord = true;
                }
            }
        }
    }
    
    public boolean query(char letter) {
        list.add(0, letter);
        Node cur = dummy;
        for(Character c : list) {
            if(cur.nodes[c - 'a'] == null) {
                return false;
            } else {
                cur = cur.nodes[c - 'a'];
                if(cur.isWord) {
                    return true;
                }
            }
        }
        
        return cur.isWord;
        
    }
    
    class Node{
        Node[] nodes;
        boolean isWord;
        
        public Node(){
            isWord = false;
            nodes = new Node[26];
        }
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */
__________________________________________________________________________________________________
158ms
class StreamChecker {
    class TrieNode {
        TrieNode[] next;
        boolean isLeaf;
        public TrieNode() {
            next = new TrieNode[26];
            isLeaf = false;
        }
    }
    TrieNode root;
    Set<TrieNode> set;
    public StreamChecker(String[] words) {
        set = new HashSet<>();
        root = new TrieNode();
        for(String s: words) {
            TrieNode temp = root;
            for(char c: s.toCharArray()) {
                if(temp.next[c-'a'] == null) {
                    temp.next[c-'a'] = new TrieNode();
                }
                temp = temp.next[c-'a'];
            }
            temp.isLeaf = true;
        }
    }
    
    public boolean query(char letter) {
        Set<TrieNode> next = new HashSet<>();
        boolean re = false;
        for(TrieNode t: set) {
            t = t.next[letter-'a'];
            if(t!= null && t.isLeaf) {
                re = true;
            }
            if(t != null) next.add(t);
        }
        if(root.next[letter-'a'] != null) {
            if(root.next[letter-'a'].isLeaf) re = true;
            next.add(root.next[letter-'a']);
        }    
        set = next;
        return re;
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */
__________________________________________________________________________________________________

__________________________________________________________________________________________________

__________________________________________________________________________________________________