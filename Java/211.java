__________________________________________________________________________________________________
sample 71 ms submission
public class WordDictionary {
    TrieNode root;

    /**
     * Initialize your data structure here.
     */
    public WordDictionary() {
        root = new TrieNode();
    }

    /**
     * Adds a word into the data structure.
     */
    public void addWord(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int index = c - 'a';
            if (node.children[index] == null) {
                node.children[index] = new TrieNode();
            }
            node = node.children[index];
        }
        node.isEndOfAWord = true;
    }

    /**
     * Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
     */
    public boolean search(String word) {
        return search(root, word, 0);
    }

    // compare each node's children with the char at the given index of the word incrementally
    public boolean search(TrieNode node, String word, int index) {
        // if index is already longer than max index (length-1)
        // then check if the node is the end of an work, there's no need to check its children
        if (index == word.length()) {
            return node.isEndOfAWord;
        }

        char ch = word.charAt(index);
        index++;

        if (ch == '.') {
            for (TrieNode child : node.children) {
                if (child != null) {
                    // if this child works then return true
                    if (search(child, word, index)) {
                        return true;
                    }
                }
            }
            // no child's path works.
            return false;
        } else {
            if (node.children[ch - 'a'] != null) {
                return search(node.children[ch - 'a'], word, index);
            } else {
                return false;
            }
        }
    }

    class TrieNode {
        public TrieNode[] children = new TrieNode[26];
        public boolean isEndOfAWord = false;

    }
}
__________________________________________________________________________________________________
sample 50564 kb submission
class WordDictionary {
    TrieNode root;
    
    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new TrieNode();    
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        TrieNode node = root;
        for(char c : word.toCharArray()) {
            if(node.children[c - 'a'] == null) {
                node.children[c - 'a'] = new TrieNode();
            }
            node = node.children[c - 'a'];
        }
        node.isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return searchHelper(root, word);
    }
    
    private boolean searchHelper(TrieNode node, String word) {
        for(int j = 0; j < word.length(); j++) {
            char c = word.charAt(j);
            if(c == '.') {
                for(int i = 0; i < node.children.length; i++) {
                    TrieNode child = node.children[i];
                    if(child != null) {
                        if(searchHelper(child, word.substring(j+1))) {
                            return true;
                        }
                    } 
                }
                return false;
            }else {
                if(node.children[c - 'a'] == null) {
                    return false;
                }
                node = node.children[c - 'a'];
            }
        }
        return node.isWord;
    }
}

class TrieNode{
    boolean isWord;
    TrieNode[] children;
    public TrieNode() {
        children = new TrieNode[26]; 
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
__________________________________________________________________________________________________
